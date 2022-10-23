#include <Servo.h>
#include <LiquidCrystal.h> 
LiquidCrystal LCD(11,10,9,2,3,4,5);


Servo myservo; // create servo object to control a servo

const int trigPin = 7;

const int echoPin = 6;

void setup() {
  
   LCD.begin(16,2); 
  LCD.setCursor(0,0);
  LCD.print("Please Wait");
    delay(250);



// initialize serial communication:

Serial.begin(9600); // establishes serial communication between your Arduino board and computer

myservo.attach(8); // attaches the servo on pin 9 to the servo object
 
	
}

void loop() {


 
long duration, cm;

pinMode(trigPin, OUTPUT);    // sets trig pin as output

digitalWrite(trigPin, LOW);  // sets trig pin off

delayMicroseconds(2); // waits for 2 ms

digitalWrite(trigPin, HIGH); // sets trig pin on

delayMicroseconds(20);   // waits for 20 ms 

digitalWrite(trigPin, LOW); 

pinMode(echoPin, INPUT);   // determines the time the object was detected by the sensor 

duration = pulseIn(echoPin, HIGH);   // determines the time the object was detected by the sensor 

cm = microsecondsToCentimeters(duration); // convert the time into a distance
// the condition for the distance

if ( cm > 7 && cm < 14)  // the condition for the distance

{

LCD.setCursor(0,1);
  LCD.print("You may go"); 
  delay(250);
  


myservo.write(145); // sets the servo position according to the scaled value

delay(4000);

}

else if ( cm < 8)

{

myservo.write(40); // sets the servo position according to the scaled value

delay(100);

}

else

{

myservo.write(40); // sets the servo position according to the scaled value

delay(100);

}

Serial.print(cm);

Serial.print("cm");

Serial.println();

delay(100);

}

long microsecondsToCentimeters(long microseconds) {

// The speed of sound is 340 m/s or 29 microseconds per centimeter.

// The ping travels out and back, so to find the distance of the

// object we take half of the distance travelled.

return microseconds / 29 / 2;

}