
int trigPin1=13;
int echoPin1=12;

int trigPin2=9;
int echoPin2=8;

#define buzzer 6

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   if (distance1 >= 500 || distance1 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
  }
  if (distance1 < 30) { // This is where the LED On/Off happens

digitalWrite(buzzer,HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(redLED,LOW);
delay(distance1*10);
digitalWrite(buzzer,LOW); 
delay(distance1*12);

} else {

digitalWrite(buzzer,LOW); 

}

  delay(50);
long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;

   if (distance2 >= 500 || distance2 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
  }
  if (distance2 < 30) { // This is where the LED On/Off happens

digitalWrite(buzzer,HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(redLED,LOW);
delay(distance2*10);
digitalWrite(buzzer,LOW); 
delay(distance2*12);

} else {

digitalWrite(buzzer,LOW); 

}


}
