#include <Servo.h> //Include the Servo library
#include <LiquidCrystal.h>//Include the Liquid Crystal library

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo servo; // Declare the name of the Servo motor

#define trigPin 10 // Define the Trigger pin
#define echoPin 9 // Define the Echo pin
 
float duration, distance; // Declare the variables: distance and duration
 
void setup() {
  Serial.begin (9600); // Start the Serial Monitor
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  servo.attach(8); // Declare the pin in which the servo motor is attached
  pinMode(trigPin, OUTPUT); // Define that the trigPin is for output
  pinMode(echoPin, INPUT); // Define that the echoPin is for input
  lcd.print(" Safely Dispose");
  lcd.setCursor(2, 1);
  lcd.print(" Your Waste");
  servo.write(0);// Close the lid of the dustbin
}
 
void loop() {
  //  Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance = (duration / 2) * 0.0343;

  Serial.println(distance);
  if (distance <= 20 && distance >= 2) { // Check if the distance is lesser than 20 cm and greater than 2 cm and,
                                         //if yes open the lid of the dustbin and print the message "Thanks For Keeping Our Environment Clean".
   lcd.clear(); 
   servo.write(90);
   delay(3000);
   lcd.print("Thanks For Using");
   delay(2000);
   lcd.clear();
   lcd.print(" Safely Dispose");
   lcd.setCursor(2, 1);
   lcd.print(" Your Waste");
  }
  else { // Else close the lid of the dustbin
    servo.write(0);
  }
  delay(200);
}
