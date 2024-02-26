#include <Wire.h>
#include <rgb_lcd.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11  // Set this to the type of DHT sensor you are using
#define MOTOR_PIN 9
#define POT_PIN A0

DHT_Unified dht(DHTPIN, DHTTYPE);
rgb_lcd lcd;

void setup() {
  Serial.begin(9600);
  // Initializing device.
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  lcd.begin(16, 2);
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
 
  int sensorValue = analogRead(POT_PIN);
  int motorSpeed = map(sensorValue, 0, 1023, 0, 255);
  
   sensors_event_t event;
  dht.temperature().getEvent(&event);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Temperature: "));
  lcd.print(event.temperature);
  lcd.print(F("°C"));

  if (event.temperature > 15) {
       analogWrite(MOTOR_PIN, motorSpeed);
       Serial.println("Fan is on");
       Serial.println("Speed of the motor " + String(motorSpeed));
  } else {
    analogWrite(MOTOR_PIN, 0);
    Serial.println("Fan is off");
    Serial.println("the speed of the motor is " + String(motorSpeed));
  }

  delay(1000);
}