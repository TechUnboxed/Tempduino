//tempduino (temperature and humidity display)
//by jeff clymer (jeff@techunboxed.com)
//2013.01.14 http://techunboxed.com
//version 3.1

#include "DHT.h"
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#define DHTPIN 2 //DHT22 is connected to digital pin 2
#define DHTTYPE DHT22   //set the type of sensor

DHT dht(DHTPIN, DHTTYPE);
Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
    dht.begin();
    matrix.begin(0x70);
    matrix.setBrightness(1);
}

void loop() {
  float h = dht.readHumidity(); //h = DHT humidity
  float t = dht.readTemperature(); //t = DHT temp

    matrix.print(t*1.8+32); //display temp in fahrenheit
    matrix.writeDisplay();
    delay(30000); //wait 30 seconds
    matrix.print(h); //display humidity percentage
    matrix.writeDisplay();
    delay(10000); //wait 10 seconds  
}
