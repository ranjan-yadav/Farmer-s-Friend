#include <Servo.h>
const int trigPin = 6;
const int echoPin = 10;
const int led_left=13;
const int led_right=11;
// defines variables
long duration;
int distance;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(led_left, OUTPUT);// acts as Interrupt which when rover detects an objects , it acts as interrupt signal to stop the rover.
  pinMode(led_right, OUTPUT);// acts as Interrupt which when rover detects an objects , it acts as interrupt signal to stop the rover.
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  Serial.begin(9600); // Starts the serial communication
}

void loop() 
{
        for (pos = 0; pos <= 180; pos += 1)
          {                                                                            // goes from 0 degrees to 180 degrees
                                                                                     // in steps of 1 degree
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                   delay(15);                       // waits 15ms for the servo to reach the position

                                                       // Clears the trigPin
                    digitalWrite(trigPin, LOW);
                      delayMicroseconds(2);
                                                                 // Sets the trigPin on HIGH state for 10 micro seconds
                    digitalWrite(trigPin, HIGH);
                      delayMicroseconds(10);
                    digitalWrite(trigPin, LOW);
                                                           // Reads the echoPin, returns the sound wave travel time in microseconds
                    duration = pulseIn(echoPin, HIGH);
                                                                              // Calculating the distance
                    distance= duration*0.034/2;
                                                                              // Prints the distance on the Serial Monitor
                    Serial.print("Distance: ");
                    Serial.print("\n");
                    Serial.println(distance);
                    Serial.print("\n");
 
                              if( distance <=15)
                                    {  
                                      if( pos<=90 && pos>=0)
                                         {
                                               digitalWrite(led_right, HIGH);
                                               Serial.print("OBSTACLE DETECTED\n");
                                               Serial.print("MOVE RIGHT\n");
                                                delay(1000);
                                               digitalWrite(led_right, LOW);
                                         }
                                        else 
                                          {
                                                digitalWrite(led_left, HIGH);
                                                 Serial.print("OBSTACLE DETECTED\n");
                                                 Serial.print("MOVE LEFT\n");
                                                 delay(1000);
                                                digitalWrite(led_left, LOW);
                                          }
                                       }
           }
                         
                         
                         
              for (pos = 180; pos >= 0; pos -= 1) 
           { // goes from 180 degrees to 0 degrees
                                              myservo.write(pos);              // tell servo to go to position in variable 'pos'
                                               delay(15);  // waits 15ms for the servo to reach the position
                                               // Clears the trigPin
                                                  digitalWrite(trigPin, LOW);
                                                    delayMicroseconds(2);
                                                        // Sets the trigPin on HIGH state for 10 micro seconds
                                                    digitalWrite(trigPin, HIGH);
                                                    delayMicroseconds(10);
                                                    digitalWrite(trigPin, LOW);
                                                    // Reads the echoPin, returns the sound wave travel time in microseconds
                                                    duration = pulseIn(echoPin, HIGH);
                                                        // Calculating the distance
                                                      distance= duration*0.034/2;
                                                            // Prints the distance on the Serial Monitor
                                                        Serial.print("Distance: ");
                                                          Serial.print("\n");
                                                        Serial.println(distance);
                                                        Serial.print("\n");

                                                  if( distance <=15)
                                    {  
                                      if( pos<=90 && pos>=0)
                                         {
                                               digitalWrite(led_right, HIGH);
                                               Serial.print("OBSTACLE DETECTED\n");
                                               Serial.print("MOVE RIGHT\n");
                                                delay(1000);
                                               digitalWrite(led_right, LOW);
                                         }
                                        else 
                                          {
                                                digitalWrite(led_left, HIGH);
                                                 Serial.print("OBSTACLE DETECTED\n");
                                                 Serial.print("MOVE LEFT\n");
                                                 delay(1000);
                                                digitalWrite(led_left, LOW);
                                          }
                                       }
 

           }
}


