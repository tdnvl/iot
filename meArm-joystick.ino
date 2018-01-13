/* Joystick code inspired by Arduino - Multiple Servo Control With Joystick by MertArduino: http://www.instructables.com/id/Arduino-Multiple-Servo-Control-With-Joystick/ */

#include <Servo.h> 
 
// define servos
Servo middle, left, right, claw ;

// define joystick pins (analog)
int joyX = 0;
int joyY = 1;
int joyZ = 2;
int joyW = 3;

// variable to read the values from the analog pins
int joyVal;
 
void setup() 
{ 
  Serial.begin(9600);
  middle.attach(11);  // attaches the servo on pin 11 to the middle object
  left.attach(10);  // attaches the servo on pin 10 to the left object
  right.attach(9);  // attaches the servo on pin 9 to the right object
  claw.attach(6);  // attaches the servo on pin 6 to the claw object
} 
 
void loop() 
{ 
    Serial.println("#########");
  // read the value of the joystick (0-1023)
  joyVal = analogRead(joyX);
  joyVal = map (joyVal, 0, 1023, 0, 180); // maps servo value between 0-180
  Serial.print("Middle = ");
  Serial.println(joyVal);
  middle.write(joyVal);
  
  joyVal = analogRead(joyY);
  joyVal = map (joyVal, 0, 1023, 0, 180); // maps servo value between 0-180
  Serial.print("Left = ");
  Serial.println(joyVal);
  left.write(joyVal); // does the same
  
  joyVal = analogRead(joyZ);
  joyVal = map (joyVal, 0, 1023, 0, 180); // maps servo value between 0-180
  Serial.print("Right = ");
  Serial.println(joyVal);
  right.write(joyVal); // does the same
  
  joyVal = analogRead(joyZ);
  joyVal = map (joyVal, 0, 1023, 0, 75); // maps servo value between 0-75
  Serial.print("Claw = ");
  Serial.println(joyVal);
  claw.write(joyVal); // does the same

 // right.write(90); // and again
//   claw.write(75); // yes you've guessed it
  
  delay(1000); // doesn't constantly update the servos which can fry them
} 
