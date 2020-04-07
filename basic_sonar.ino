const int trigPin = 9;
const int echoPin = 10;
const int led=13;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(led, OUTPUT);// acts as Interrupt which when rover detects an objects , it acts as interrupt signal to stop the rover.
Serial.begin(9600); // Starts the serial communication
}
void loop() {
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
delay(100);
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print("\n");
Serial.println(distance);

if( distance <=30)
{
  digitalWrite(led, HIGH);
  Serial.print("OBSTACLE DETECTED");
  Serial.print("\n");
  Serial.print("__________________");
  Serial.print("\n");
  delay(3000);
}
     digitalWrite(led, LOW);
}
