// Define Motor1 pins
const int Motor1Pos = 9;
const int Motor1Neg = 5;

// Define Motor2 pins
const int Motor2Pos = 10;
const int Motor2Neg = 11;

// Define Ultrasonic Sensor pins 
const int trigPin = 13;
const int echoPin = 12;

// Define Pushbuttons pins
const int putton1 = 0;
const int putton2 = 4;
const int putton3 = 6;
const int putton4 = 7;

// Define Encoders pins
const int Enc1A = 2;
const int Enc2A = 3;


// Define variables
long duration;
int distance;
volatile long Enc1Pos = 0;
volatile long Enc2Pos = 0;


void setup() {
  // Initialize Motors pins as OUTPUT
  pinMode(Motor1Pos,OUTPUT);
  pinMode(Motor1Neg,OUTPUT);
  pinMode(Motor2Pos,OUTPUT);
  pinMode(Motor2Neg,OUTPUT);
  // Initialize pushbuttons pins as INPUT
  pinMode(putton1,INPUT);
  pinMode(putton2,INPUT);
  pinMode(putton3,INPUT);
  pinMode(putton4,INPUT);  
  // Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT); 
  // Sets the echoPin as an Input
  pinMode(echoPin, INPUT);
  // Sets Encoders pins as INPUT
  pinMode(Enc1A,INPUT_PULLUP);
  pinMode(Enc2A,INPUT_PULLUP);
  // Interrupt settings
  attachInterrupt(digitalPinToInterrupt(Enc1A), count1, RISING);
  attachInterrupt(digitalPinToInterrupt(Enc2A), count2, RISING);
  // Starts the serial communication
  Serial.begin(9600); 
}

void loop() { 
 stop();
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
 Serial.println(distance);
 // Read the pushbuttons status
 int val1 = digitalRead(putton1);
 int val2 = digitalRead(putton2);
 int val3 = digitalRead(putton3);
 int val4 = digitalRead(putton4);
  
  if (val1 == LOW) {         
    Forward();
  } 
  else if (val2 == LOW) {         
    Backward();
  } 
  else if (val3 == LOW) {         
    Left();
  } 
  else if (val4 == LOW) {         
    Right();
  } 
}

void Forward(){
 Serial.println("Forward");
 while( Enc1Pos<360 || Enc2Pos<360 ){
 digitalWrite(Motor1Pos, LOW);
 digitalWrite(Motor1Neg, HIGH);
 digitalWrite(Motor2Pos, LOW);
 digitalWrite(Motor2Neg, HIGH);
 }
 delay(1000);
 stop();
 Enc1Pos = 0;
 Enc2Pos = 0;
}

void Backward(){
 Serial.println("Backward");
 while( Enc1Pos<360 || Enc2Pos<360 ){
 digitalWrite(Motor1Pos, HIGH);
 digitalWrite(Motor1Neg, LOW);
 digitalWrite(Motor2Pos, HIGH);
 digitalWrite(Motor2Neg, LOW);
  }
 delay(1000);
 stop();
 Enc1Pos = 0;
 Enc2Pos = 0; 
}

void Left(){
 Serial.println("Left");
 while( Enc1Pos<360 || Enc2Pos<360 ){
 digitalWrite(Motor1Pos, LOW);
 digitalWrite(Motor1Neg, HIGH);
 digitalWrite(Motor2Pos, HIGH);
 digitalWrite(Motor2Neg, LOW);
 }
 delay(1000);
 stop();
 Enc1Pos = 0;
 Enc2Pos = 0;
}

void Right(){
 Serial.println("Right");
 while( Enc1Pos<360 || Enc2Pos<360 ){
 digitalWrite(Motor1Pos, HIGH);
 digitalWrite(Motor1Neg, LOW);
 digitalWrite(Motor2Pos, LOW);
 digitalWrite(Motor2Neg, HIGH);
 }
 delay(1000);
 stop();
 Enc1Pos = 0;
 Enc2Pos = 0;
}

void stop(){
 digitalWrite(Motor1Pos, LOW);
 digitalWrite(Motor1Neg, LOW);
 digitalWrite(Motor2Pos, LOW);
 digitalWrite(Motor2Neg, LOW);
}

void count1() {
   Enc1Pos++;
}

void count2() {
   Enc2Pos++;
}
