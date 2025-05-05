# Smart Distance Measurer with LCD Display

This project is a smart distance measuring system that uses an ultrasonic sensor to measure distance and display it on an LCD. It is ideal for small prototypes, DIY projects, and educational purposes.

## Features
- Accurate distance measurement (in cm or inches)
- Real-time data display on LCD
- User-friendly design
- Low power consumption

## Components Used (Hardware)
- Arduino UNO or Nano
- HC-SR04 Ultrasonic Sensor
- 16x2 I2C LCD Display
- Jumper Wires
- Breadboard
- 5V Power Supply or USB

## Circuit Connections
- HC-SR04 VCC → Arduino 5V  
- HC-SR04 GND → Arduino GND  
- HC-SR04 Trig → Arduino Pin 9  
- HC-SR04 Echo → Arduino Pin 10  
- LCD VCC → Arduino 5V  
- LCD GND → Arduino GND  
- LCD SDA → Arduino A4 (for UNO/Nano)  
- LCD SCL → Arduino A5 (for UNO/Nano)

## How It Works
1. The ultrasonic sensor sends out a sound wave.
2. It detects the time taken for the echo to return after hitting an object.
3. The Arduino calculates the distance based on the time.
4. The result is shown on the 16x2 LCD in real-time.

## Code
You can upload the Arduino sketch from the `/code` folder (if available) or write your own using the `LiquidCrystal_I2C` and `NewPing` libraries.


## License
VoltACDC.Lab License
