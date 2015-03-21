#include <Servo.h>

/*servo pan tilt using motor shield from Adafruit. Separate motor with 
 propellar uses its own simple power source for this sketch.
 
 By Bernard Katz 4/24/10
 www.bernardkatzglass.com
 */

Servo panServo;
Servo tiltServo;
int motor = 4;
byte pos = 0; // variable to store starting servo position

void setup() {
  panServo.attach(9); //pan servo on pin 9
  tiltServo.attach(10); //tilt servo on pin 10
  panServo.write(90); //added this for second sketch 
  tiltServo.write(90); // hoping to halt wild start up swing
  pinMode(motor, OUTPUT);
}

void loop() {
  
  for(pos = 0; pos < 180; pos += 1) { //servo moves 0 degrees to 180 degrees in steps of 1 degree
    panServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15); 
  }
  for(pos = 0; pos < 90; pos += 1) { //tilt servo moves 45 degrees down
    tiltServo.write(pos);
    delay(15); // waits 15ms for servo to reach 90 degrees
    //delay(500); // holds in bubble solution half second
  }
  for(pos = 90; pos >= 1; pos -= 1) { // tilt servo raises and levels off
    tiltServo.write(pos);
    delay(15);
  }
  
  for(pos = 180; pos >=1; pos -= 1) { // pan servo swings wand around towards fan
    panServo.write(pos);
    delay(15);
  }

  digitalWrite(motor, HIGH);   // turns the motor On
  delay(1000);                // waits for one second
  digitalWrite(motor, LOW);  // turns the motor Off

  delay(3000); // pan servo hold at fan for a couple of seconds
}






