#define buzzer 12
#define LED 13
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);


void setup() {
  pinMode(LED,OUTPUT);//OUT PUT puls voltage
  pinMode(buzzer,OUTPUT);//Buzzer OUT put
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
}

void loop() {  

  digitalWrite(buzzer,LOW);//Turn Off Buzzer

  for(int i=0; i<1501; i++){
    lcd.clear();
    lcd.print(i,DEC);
    digitalWrite(LED,HIGH);
    delay(50);
    digitalWrite(LED,LOW);
    delay(50);
  }

  delay(6000);

  for(int i=1501; i<2501; i++){
    lcd.clear();
    lcd.print(i,DEC);
    digitalWrite(LED,HIGH);
    delay(25);
    digitalWrite(LED,LOW);
    delay(25);
  }
  
  while(digitalRead(1)==HIGH){
    digitalWrite(buzzer,HIGH);
  }
} 
