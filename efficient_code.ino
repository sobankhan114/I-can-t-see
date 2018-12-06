///////////////////////////////////////////////////////

#define trigPin4 13
#define echoPin4 12
#define trigPin3 11
#define echoPin3 10                             //all the ultrasonic sensors pin configuration
#define trigPin2 9
#define echoPin2 8
#define trigPin1 7
#define echoPin1 6

///////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////
unsigned int time_now1 = 0;
unsigned int time_now2 = 0;
unsigned int time_now3 = 0;
unsigned int time_now4 = 0;                          // all the variables used in the program
long dur1,dur2,dur3,dur4,dist1,dist2,dist3,dist4;
float b=0;
//////////////////////////////////////////////////////////////////////////

void setup() {

Serial.begin (9600);

//////////////////////////////////////////////////////////////////////////  
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);                                     //ultrasonic pin setup
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
///////////////////////////////////////////////////////////////////////
  
}

void loop() 
{                                             /////////////////////
  dist1=dist(trigpin1,echopin1);
  dist2=dist(trigpin2,echopin2);
  dist3=dist(trigpin3,echopin3);
  dist4=dist(trigpin4,echopin4);                              //main function , preety small ha !
  print_dist();
}                                             /////////////////////



///////////////////////////////////////////////////////////////////////////
void print_dist()
{
    Serial.print ( "Sensor1  ");
    Serial.print ( dist1);
    Serial.println("cm");
    Serial.print ( "Sensor2  ");
    Serial.print ( dist2);
    Serial.println("cm");                                    // to serial print the distance
    Serial.print ( "Sensor3  ");
    Serial.print ( dist3);
    Serial.println("cm");
    Serial.print ( "Sensor4  ");
    Serial.print ( dist4);
    Serial.println("cm");
}
///////////////////////////////////////////////////////////////////////////////

float dist(int trigpin,int echopin)
{
  b=0;
    digitalWrite(trigPin,LOW);                            
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    dur1 = pulseIn(echoPin, HIGH);
    b = (dur1/2) / 29.1;
    return b;
 }





