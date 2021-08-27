#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);
int sen = A0;

int pm=0, m=10;

void setup(){
  pinMode(A0,INPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);

String str = "AIR PURIFICATION SYSTEM";
lcd.print(str);

for(int i=0; i<str.length(); i++)
{
  lcd.scrollDisplayLeft();
  delay(100);
  
}
lcd.clear();

  
}

void loop(){
  sen = analogRead(A0);
  pm = sen/4;
  
lcd.setCursor(0,0);
lcd.print("VALUE:");
lcd.print(pm);
delay(1500);
lcd.clear();


if(pm>150){
  lcd.print("AIR SHOULD BE PURIFIED");
  analogWrite(10,255);
  delay(1000);
  lcd.clear();
}
else{
lcd.print("PERFECT");
delay(1000);
lcd.clear();
analogWrite(10,0);
delay(1000);
  
  
} 
}
