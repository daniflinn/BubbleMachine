//#include <AFMotor.h>

#include <Servo.h>

/*servo pan tilt using motor shield from Adafruit. Separate motor with 
 propellar uses its own simple power source for this sketch.
 
 By Bernard Katz 4/24/10
 www.bernardkatzglass.com
 */

Servo panServo;
Servo tiltServo;
int motor = 4;

//AF_DCMotor motor(4, MOTOR12_1KHZ); // create motor #4, 1 KHZ

byte pos = 0; // variable to store starting servo position

void setup() {
  panServo.attach(9); //pan servo on pin 9
  tiltServo.attach(10); //tilt servo on pin 10
 // panServo.write(90); //added this for second sketch 
  //tiltServo.write(90); // hoping to halt wild start up swing
  //motor.setSpeed(230); // set dc motor speed to 254 of 0-255 range
   pinMode(motor, OUTPUT); 
}

void loop() {
  
   panServo.write(180);             
    delay(4000); ////stops motor for 8 seconds 
  for(pos = 180; pos>=10; pos-=1)// goes from 180 degrees to 0 degrees
  {                                
    panServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); // waits 15ms for the servo to reach the position 

  } 
 // panServo.detach();
  

 /* for(pos = 0; pos < 180; pos += 1) { //servo moves 0 degrees to 180 degrees in steps of 1 degree
    panServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15); 
  }
  delay(1000);      //wait for motor to run before going back
  
  for(pos = 0; pos < 90; pos += 1) { //tilt servo moves 45 degrees down
    tiltServo.write(pos);
    delay(15); // waits 15ms for servo to reach 90 degrees
    //delay(500); // holds in bubble solution half second
  }
  for(pos = 90; pos >= 1; pos -= 1) { // tilt servo raises and levels off
    tiltServo.write(pos);
    delay(15);
  }*/
  
  motorOnThenOff();    //run motor befor panServo goes back
  
 panServo.write(10);              
    //delay(4000); //stops motor for 4 seconds   
  for(pos = 10; pos <= 179; pos +=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    panServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);      // waits 15ms for the servo to reach the position

  }  
/*for(pos = 180; pos >=1; pos -= 1) { // pan servo swings wand around towards fan
    panServo.write(pos);
    delay(15);
  }*/
  delay(1000);
 
//Pulse width Moduelation, Arduino servo hold position 

}
void motorOnThenOff(){
  int onTime = 2500;  //the number of milliseconds for the motor to turn on for
  int offTime = 1000; //the number of milliseconds for the motor to turn off for
  
  digitalWrite(motor, HIGH); // turns the motor On
  delay(onTime);                // waits for onTime milliseconds
  digitalWrite(motor, LOW);  // turns the motor Off
 // delay(offTime);               // waits for offTime milliseconds
}


  //motor.run(FORWARD); //turn on dc motor

 // delay(3000); // pan servo hold at fan for a couple of seconds

  //Servo refresh(); //refresh and begin again

  //motor.run(RELEASE); // dc motor to stop







