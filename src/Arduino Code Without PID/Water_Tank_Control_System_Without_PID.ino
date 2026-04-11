#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// PWM pins in Arduino Uno:3,5,6,9,10,11

// Define pins for LCD
#define Rs 2
#define En 3
#define d4 4
#define d5 5
#define d6 6
#define d7 7
LiquidCrystal lcd(Rs,En,d4,d5,d6,d7);
// Define Pins for Ultrasonic Sensor
#define echo 8
#define trig 9

// Temperature sensor pin
#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);

// Pump Speed Control Pin
#define enable 11

// Pump Control Pin
#define Pump_Control 12

// Temperature Control pin 
#define Temp_Control 13

DallasTemperature sensors(&oneWire);
float Celcius=0;
//float Fahrenheit=0;
//int_values for temp_sensor
float temp;
// Variables for Ultrasonic sensor
float duration;
float distance;
//float distancem;
float Height;
//float Heightm;

void setup() {

      // Start serial port
      Serial.begin(9600);
      pinMode(trig,OUTPUT);
      pinMode(echo,INPUT);
      pinMode(Pump_Control,OUTPUT);
      pinMode(Temp_Control,OUTPUT);
      pinMode(enable,OUTPUT);
      lcd.begin(16,2);
      // Start up the library for ds18b20 sensor 
      sensors.begin();
}

void loop() {
  // Ultrasonic Measuring duration to get distance
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  duration=duration/2;
  distance=duration*0.034;
  //distancem=duration*0.00034;
  Height=11.8-distance;
  //Heightm=0.118-distancem;

  // Temperature sensor Measuring Temperature
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  //Fahrenheit=sensors.getTempFByIndex(0);

  //Controlling Pump 
  if(Height<=8)
  {
    digitalWrite(Pump_Control,HIGH);
    analogWrite(enable,255);
  }
  else
  {
    digitalWrite(Pump_Control,LOW);
    analogWrite(enable,255);
  }

  //Controlling Heater
  if(Celcius>30)
  {
    digitalWrite(Temp_Control,HIGH);
  }
  else
  {
    digitalWrite(Temp_Control,LOW);
  }
  
  Serial.print("T=");
  Serial.print(Celcius);
  Serial.print(" ");
  
  lcd.setCursor(0,0); 
  lcd.print("T=");
  lcd.print(Celcius);
  lcd.print("C");
  lcd.write(223);

  //lcd.setCursor(9,0); 
  //lcd.print(Fahrenheit);
  //lcd.print("F");
  //lcd.write(223);

  
  lcd.setCursor(0,1); 
  lcd.print("H=");
  lcd.print(Height);
  lcd.print("Cm");

  //lcd.setCursor(9,1); 
  //lcd.print(Heightm);
  //lcd.print("m");

  delay(1000);
}
