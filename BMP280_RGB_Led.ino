#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
const int hot = 30; 
const int cold = 15; 

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; 

void setup() {
  pinMode(2, OUTPUT); //blue
  pinMode(3, OUTPUT); //green
  pinMode(1, OUTPUT); //red
  Serial.begin(9600);

  //if (!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor"));
    while (1) delay(10);
  }

 
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,    
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500); 
}

void loop() {
  
    Serial.print(bmp.readTemperature());
 
    if (bmp.readTemperature() < cold) { //cold
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
Serial.println(" Cold");
}
else if (bmp.readTemperature() >= hot) { //hot
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
Serial.println(" Hot");
}
else { //fine
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
Serial.println(" Fine");
}
    Serial.println();
    delay(100);
}
