#include <Servo.h>  // servo library

Servo servo_R;   //assign servos Right and Left Side of Robot
Servo servo_L;
Servo servo_B;

const int leftSensor = 10;     // Assign sensor pins for two down sensors
const int rightSensor = 9;
const int backSensor = 8;

int lsensorState = 0;          // Initialize sensor variable
int rsensorState = 0;
int bsensorState = 0;

void setup() { //do this setup once
  pinMode(leftSensor, INPUT);   // Declare assigned sensor pins as input
  pinMode(rightSensor, INPUT);
  pinMode(backSensor, INPUT);
  servo_R.attach(12);    	// attach two servos to pins 12 and 13
  servo_L.attach(13);
  Serial.begin(9600);           // set serial monitor baud rate for output sensor state testing

  while (!Serial);
  Serial.println("Speed 0 to 255");	}

void loop() {  // start infinite loop to run robot
  rsensorState = digitalRead(rightSensor);  //read right sensor
  lsensorState = digitalRead(leftSensor);   //read left sensor
  bsensorState = digitalRead(backSensor);   //read back sensor

  servo_R.write(0);   //right motor clockwise (Full Speed forward)
  servo_L.write(180); //left motor counterclockwise for forward

  if (rsensorState == LOW) { //If right sensor detects white
    servo_R.write(180); //right motor counterclockwise reverse
    servo_L.write(0);  //left motor Clockwise for reverse
    delay(250);  //  .25 second delay
    servo_L.write(0);  //left motor Clockwise for reverse
    servo_R.write(0);   //right motor clockwise forward
    delay(600);  //  .6 second delay
    Serial.println("Right Sensor"); 	  }

  else if (lsensorState == LOW) {         //If left sensor detects white
    servo_R.write(180); //right motor counterclockwise reverse
    servo_L.write(0);  //left motor Clockwise for reverse
    delay(250);  //  .25 second delay
    servo_R.write(180);    // spin right motor backwards
    servo_L.write(180);    // spin Left motor forwards
    delay(600);  //  .6 second delay
    Serial.println("Left Sensor") ;    }

  else if (bsensorState == LOW) {         //If back sensor detects white
    servo_R.write(0);    // spin right motor backwards
    servo_L.write(0);    // spin Left motor forwards
    delay(50);  //  .05 second delay
    Serial.println("Back Sensor") ;   }

  else  {   //drive forward green lights on both sensors LOW
    servo_R.write(0);   //right motor clockwise forward
    servo_L.write(180); //left motor counterClockwise forward
  }

delay(100);
}//end of void loop

