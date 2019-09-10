#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial myserial(5,6); // RX, TX

const int rs=7, en=8, d4=10, d5=11, d6=12, d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup ()  
{   
  Serial.begin (9600); 
  lcd.begin(16,2);
  myserial.begin(9600); 
   
}

void loop ()  
{  
  
while (Serial.available()){
  lcd.home();
  lcd.clear();
  int mm = Serial.readStringUntil(59).toInt();
 lcd.print(mm);

lcd.print("Decibel");
    lcd.setCursor (1,0);

     if(mm<40)
  {
    lcd.setCursor(0,2);
    lcd.print("Intensity= Low");
  }

if(mm>40 && mm<65)
  {
   lcd.setCursor(0,2);
    lcd.print("Intensity=Medium");

 }

  if(mm>65)
{
   lcd.setCursor(0,2);
   lcd.print("Intensity= High");
}
 myserial.println(mm); 
}

}
