/* 
Drive Test
             Test to Drive Breadboard bot forward
*/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
      // Define constants
      
  Adafruit_MotorShield AFMS = Adafruit_MotorShield();
  
  int count =20;
  
#define TESTTIME 5000

const byte SPEED = 255;   // default speed for motors
      // Define 'ports' for motors.
const byte LEFTMOTORPORT = 3;
const byte RIGHTMOTORPORT = 1;
      // Create pointers to motor control objects
Adafruit_DCMotor *motorLeft = AFMS.getMotor(LEFTMOTORPORT);
Adafruit_DCMotor *motorRight = AFMS.getMotor(RIGHTMOTORPORT);
  
void setup() {
AFMS.begin();   // Create with default frequenchy 1.6KHz  
                // turn off all motors to start
motorLeft->run(RELEASE);
motorRight->run(RELEASE);

}

void loop() {

//delay(2000); // Delay for two sec to give time to place the bot down  
  
motorLeft->setSpeed(SPEED);
motorRight->setSpeed(SPEED);
motorLeft->run(FORWARD);
motorRight->run(BACKWARD);
delay(TESTTIME);   // run for 1 sec.
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(800);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(300);              // wait for a second
  digitalWrite(13, HIGH);  // LED on
  delay(300);                // delay 
  digitalWrite(13, LOW);    // LED off
  delay(800);
}
