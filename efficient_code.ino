#define trigPin1 13
#define echoPin1 12
#define trigPin2 9
#define echoPin2 8

#define buzzer 6
#define redLED 10

unsigned long time_now1 = 0;
unsigned long time_now2 = 0;
long dur1,dur2,dist1,dist2;
float b=0;


void setup() {

Serial.begin (9600);

pinMode(trigPin1, OUTPUT);

pinMode(echoPin1, INPUT);

pinMode(trigPin2, OUTPUT);

pinMode(echoPin2, INPUT);

pinMode(buzzer, OUTPUT);

pinMode(redLED, OUTPUT);

}

void loop() 
{                                             /////////////////////
  dist1=dist(1);
  dist2=dist(2);                              //main function , preety small ha !
  print_dist();
  buzz();
}                                             /////////////////////



////////////////////////////////////////////////
void print_dist()
{
 

 
 if (dist1 >= 150 && dist2 >=150)
 {
    Serial.println("Out of range");
 }
 else
 {
    Serial.print ( "Sensor1  ");
    Serial.print ( dist1);
    Serial.println("cm");
    Serial.print ( "Sensor2  ");
    Serial.print ( dist2);
    Serial.println("cm");
 }
 
}
////////////////////////////////////////////////
float dist(int c)
{
  b=0;
  if(c==1)                                                 //This function is used to calculate distance
  {                                                        //for both the ultrasonic sensors
    digitalWrite(trigPin1,LOW);
  
    delayMicroseconds(2);
  
    digitalWrite(trigPin1, HIGH);

    delayMicroseconds(5);

    digitalWrite(trigPin1, LOW);
  
    dur1 = pulseIn(echoPin1, HIGH);
  
  
    b = (dur1/2) / 29.1;
    return b; 
  }

  else if(c==2)
  {
    digitalWrite(trigPin2,LOW);
  
    delayMicroseconds(2);
  
    digitalWrite(trigPin2, HIGH);

    delayMicroseconds(5);

    digitalWrite(trigPin2, LOW);
  
    dur1 = pulseIn(echoPin2, HIGH);
  
  
    b = (dur1/2) / 29.1;
    return b; 
  }
  
}
//////////////////////////////////////////////////

void buzz()
{
  if(dist1<50||dist2<50)
  {
    if(dist1<dist2)
    {
      buzzdelay(dist1);                            //This function determines which object is more close to the ultrasonic
    }
    else if(dist2<dist1)
    {
      buzzdelay(dist2);
    }
  }
}

///////////////////////////////////////////////////

void buzzdelay(float a)
{
  a=a*10;
  if(millis()>a+time_now1)
  {
    digitalWrite(buzzer,HIGH);                         //This function buzzez
    time_now1=millis();
  }
  if(millis()>a/0.5+time_now2)
  {
    digitalWrite(buzzer,LOW);
    time_now2=millis();
  }
}




