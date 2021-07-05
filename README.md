# bmp280-rgb-thermometer
Control your RGB led using BMP280 sensor and Arduino

[Youtube video](https://youtu.be/rL-t3XhaOv4)

| BMP280 | Arduino |
| ------------- | ------------- |
| VCC  | 3.3 V  |
| GND  | GND  |
| SCL  | Analog 5 (A5)  |
| SDA  | Analog 4 (A4)   |



| RGB Led  | Arduino |
| ------------- | ------------- |
| Red (R) | Digital 1  |
| Green (G)  |Digital 3  |
| Blue (B) | Digital 2  |



If temperature is >30 led will be red





If temperature is 15> temp >30 led will be green




If temperature is <15 led will be blue



You need Adafruit BMP280 library to run this code
