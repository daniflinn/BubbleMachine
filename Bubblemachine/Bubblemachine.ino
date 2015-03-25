#include <Servo.h>

/*servo pan tilt using motor shield from Adafruit. Separate motor with 
 propellar uses its own simple power source for this sketch.
 
 By Bernard Katz 4/24/10
 www.bernardkatzglass.com
 */

Servo panServo;                    //declares first servo
Servo tiltServo;                   //declares second servo
int motorFan = 4;                  //attaches motorFan to pin 4
byte pos = 0;                      // variable to store starting servo position

void setup() {
  panServo.attach(9);               //pan servo on pin 9
  tiltServo.attach(10);             //tilt servo on pin 10
  panServo.write(90);               //sends panservo to 90
  tiltServo.write(0);               //sends tiltservo to 0`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  pinMode(motorFan, OUTPUT);        //sets the motorfan as an output
}

void loop() {
  
  for(pos = 0; pos < 180; pos += 1) {   //servo moves 180 degrees form fan to bubble mix, in steps of 1 degree
    panServo.write(pos);                // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15ms between each run of the forloop
  }
  for(pos = 0; pos < 90; pos += 1) {   //tilt servo moves 90 degrees down, bringing wand into the bubble mix
    tiltServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                         // waits 15ms between each run of the forloop
  }

  for(pos = 90; pos >= 1; pos -= 1) {   // tilt servo raises and levels off, bringing wand up out of bubble mix
    tiltServo.write(pos);              // tell servo to go to position in variable 'pos'                    
    delay(15);                         // waits 15ms between each run of the forloop
  }
  
  for(pos = 180; pos >=1; pos -= 1) { // pan servo swings wand around towards fan
    panServo.write(pos);              // tell servo to go to position in variable 'pos'   
    delay(15);                        // waits 15ms between each run of the forloop
  }

  delay(1000);                        // pan servo holds wand at fan for 1 seconds
 
 analogWrite(motorFan, 140);        // turns the motor/fan On at a lower power, 140
 delay(600);                        // waits for 6 milliseconds, blowing bubbles!
 analogWrite(motorFan, 50);         // turns the motor Off

}






