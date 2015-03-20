#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards

int pos =0;    // variable to store the servo position 

void setup() 
{ 

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void loop() 

{ 
  myservo.write(180);             
    delay(4000); ////stops motor for 8 seconds 
  for(pos = 180; pos>=10; pos-=1)// goes from 180 degrees to 0 degrees
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); // waits 15ms for the servo to reach the position 

  } 

    myservo.write(10);              
    delay(4000); //stops motor for 4 seconds   
  for(pos = 10; pos <= 179; pos +=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);      // waits 15ms for the servo to reach the position

  } 

} 
