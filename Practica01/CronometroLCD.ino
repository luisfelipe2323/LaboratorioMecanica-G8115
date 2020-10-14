
#include <LiquidCrystal.h>    // importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // pines RS, E, D4, D5, D6, D7 de modulo 1602A

// Variables para los cálculos internos del cronómetro
  int horas = 0;
  int minutos = 0;
  int segundos = 0;
  int decimas = 0;
  long milisegundos = 0;
 
  int pulsador_inicio = 10; // pulsador_inicio en PIN digital 10
  int pulsador_pausa = 9; // pulsador_pausa en PIN digital 9

void setup() {
  lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas
   
}


void loop()
  {
    // Si presionamos el pulsador de inicio se pone todo a cero
    if(digitalRead(pulsador_inicio) == HIGH)
    {
      horas = 0;
      minutos = 0;
      segundos = 0;
      decimas = 0;
      lcd.clear();
    }
   
    // Si presionamos el pulsador de pausa se congela el tiempo hasta que lo volvamos a presionar
    if(digitalRead(pulsador_pausa) == HIGH)
    {
      delay(200);
      while(digitalRead(pulsador_pausa) == LOW);
      delay(200);
    }
   
    // Se cuentan los milisegundos transcurridos
    milisegundos = millis();
   
    // Si el tiempo transcurrido es mayor a una décima de segundo
    if(milisegundos % 100 == 0)
    {
      decimas++;
      // Si han pasado 10 décimas de segundo se cuenta un segundo
      if(decimas == 10)
      {
        decimas = 0;
        segundos++;
      }
      // Si han pasado 60 segundos se cuenta un minuto
      if(segundos == 60)
      {
        segundos = 0;
        minutos++;
      }
      // Si han pasado 60 minutos se cuenta una hora
      if(minutos == 60)
      {
        minutos = 0;
        horas++;
      }
     
      // Mostramos el tiempo a través del LCD
      lcd.setCursor(0,0);
      if(horas < 10)
      {
        lcd.print("0");
      }
      lcd.print(horas);
      lcd.print(":");
      lcd.setCursor(3,0);
      if(minutos < 10)
      {
        lcd.print("0");
      }
      lcd.print(minutos);
      lcd.print(":");
      lcd.setCursor(6,0);
      if(segundos < 10)
      {
        lcd.print("0");
      }
      lcd.print(segundos);
      lcd.print("(");
      lcd.setCursor(9,0);
      lcd.print(decimas);
      lcd.print(")");
    }    
  }
