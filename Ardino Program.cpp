#include <Servo.h>
const int ledPin=3;
const int buzzerPin=2;
const int gasPin=A1;
//const int gasPinout=12;
const int servoPIN=10;
Servo myServo;

void setup()
{
  Serial.begin(9600);
  pinMode(gasPin,INPUT);
 // pinMode(gasPinout,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  //pinMode(motorPIN,INPUT);
  myServo.attach(servoPIN);
 
}
 
void loop()
{
  //digitalWrite(gasPinout,HIGH);
    int gasValue = analogRead(gasPin);  // Read the analog value from the gas sensor

  
  Serial.print("Gas sensor reading = ");
  Serial.println(gasValue);
  if(gasValue>282){
    activateAlarm();
  }
  else{
    deactivateAlarm();
  }
  delay(2000);
}
void activateAlarm() {
  digitalWrite(ledPin, LOW);        
  tone(buzzerPin,1000,200);
  Serial.print("GAS LEAK");
  myServo.write(120);
}

void deactivateAlarm() {
  digitalWrite(ledPin, HIGH);         
  noTone(buzzerPin);    
  myServo.write(0);
}
