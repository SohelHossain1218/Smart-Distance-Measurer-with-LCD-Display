#include <Wire.h> // I2C communication
#include <LiquidCrystal_I2C.h> // I2C LCD library

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address to 0x27

#define trigPin 3
#define echoPin 5
#define selectButton 12

long duration;
float distance;
int program = 0;
int d = 0;
int unitSelect = 0;
String unit = "Centimeter";

unsigned long lastButtonPress = 0;
unsigned long debounceDelay = 300; // Debounce delay in milliseconds

void setup() {
  Wire.begin();
  lcd.init(); // Initialize LCD
  lcd.backlight(); // Turn on backlight
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(selectButton, INPUT_PULLUP);

  lcd.setCursor(3, 0);
  lcd.print("Welcome to "); 
  lcd.setCursor(3, 1);
  lcd.print("DIU Project");
  delay(3000);
  lcd.clear(); 

  lcd.setCursor(0, 0);
  lcd.print("Dhaka Int'l Univ");  
  lcd.setCursor(0, 1);
  lcd.print("Project Loading..");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(2, 0);
  lcd.print("DIU EEE Dept.");  
  lcd.setCursor(0, 1);
  lcd.print("Project Name......");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Digital Distance");  
  lcd.setCursor(0, 1);
  lcd.print("Measurement System");
  delay(3000);
  lcd.clear();
}

void loop() {
  switch (program) {
    case 0:  // Unit selection
      lcd.setCursor(0, 0);
      lcd.print("Select Unit: ");
      lcd.setCursor(0, 1);
      lcd.print("Unit: ");
      lcd.print(unit);
      lcd.print("  ");
      delay(30);
      
      if (millis() - lastButtonPress > debounceDelay) {
        if (digitalRead(selectButton) == 0) {
          lastButtonPress = millis(); // Update the last button press time
          unitSelect = (unitSelect + 1) % 4;
          if (unitSelect == 0) unit = "Centimeter";
          else if (unitSelect == 1) unit = "Inch";
          else if (unitSelect == 2) unit = "Metre";
          else if (unitSelect == 3) unit = "Feet";
          delay(500); // Debounce delay to prevent multiple presses
        }
        if (digitalRead(selectButton) == 0) {
          program = 1;
          lcd.clear();
          delay(500);
        }
      }
      break;

    case 1:  // Distance measurement
      distance = getDistance();
      lcd.setCursor(0, 0);
      lcd.print("Distance: ");
      lcd.setCursor(2, 1);
      lcd.print(distance, 2);
      lcd.setCursor(8, 1);
      lcd.print(unit);
      lcd.print("  ");
      delay(300);

      if (digitalRead(selectButton) == 0) {
        delay(500);
        if (digitalRead(selectButton) == 0) {
          program = 0;
          lcd.clear();
          delay(500);
        }
      }
      break;
  }
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  float dist = duration * 0.034 / 2;

  if (unitSelect == 0) return dist; // cm
  else if (unitSelect == 1) return dist * 0.393701; // inches
  else if (unitSelect == 2) return dist * 0.01; // meters
  else return dist * 0.0328; // feet
}
