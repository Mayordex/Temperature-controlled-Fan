# Temperature-controlled-Fan
In this project, the fan worked based on the temperature measured by the temperature sensor. As the temperature increases, the speed of the fan also increases.
Below are components needed for the project

Components:
Arduino Uno Board
10k potentiometer
DHT11 Temperature and Humidity Sensor
12V DC Motor (Fan)
Grove LCD RGB Backlight
500 ohm resistor
NPN transistor (e.g., 2N3904)
Diode (e.g., 1N4001)
Breadboard and jumper wires

Connections procedure:

DHT11 Temperature and Humidity Sensor:
VCC to 5V on Arduino
Data to digital pin (e.g., D2 on Arduino)
GND to GND on Arduino
10k Potentiometer:

Connect one leg to 5V on Arduino
Connect the other leg to GND on Arduino
Connect the middle leg to an analog pin (e.g., A0 on Arduino)
Grove LCD RGB Backlight:

Connect the I2C interface to the corresponding pins on the Arduino (SDA to A4, SCL to A5 on Arduino)(Grooven LED was used in the Project to disolay the reading of the temperature sensor used and the sped of the fan).
12V DC Motor (Fan) with Transistor:

Connect the collector of the NPN transistor to the positive terminal of the motor.
Connect the emitter of the NPN transistor to GND on Arduino.
Connect the base of the NPN transistor through the 500 ohm resistor to a digital pin (e.g., D3 on Arduino).
Connect a diode (1N4001) across the motor terminals, with the cathode connected to the positive terminal of the motor. This protects against back EMF when the motor turns off.
