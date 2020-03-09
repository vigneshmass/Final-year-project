  //LEFT US 
  const int pingTrigPin = 2;    
  const int pingEchoPin = 3; 
  int buz=4; 
  //RIGHT US 
  const int pingTrigPin1 = 5;    
  const int pingEchoPin1 = 6; 
  int buz1=7;
  // MID US
  const int pingTrigPin2 = 8;    
  const int pingEchoPin2 = 9; 
  int buz2=10;
  //PIR
  
int ledPin =13 ; 
int inputPin = 11; 
int pirState = LOW; 
int val = 0;
  
  void setup() 
  {    
  Serial.begin(38400);   
  pinMode(buz, OUTPUT);   
  pinMode(buz1, OUTPUT);
  pinMode(buz2, OUTPUT);
  pinMode(ledPin, OUTPUT); 
  pinMode(inputPin, INPUT); 
  
  }   
  void loop()   
  {   
 // Declare the functions
   LeftUs();
   RightUs();
   MidUs();
   PIRSensor();

   
  }   
  long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  
  }   

//------------------------------------------- Define the functioons-------------------------------
  void LeftUs(){
    //Left Ultrasonic Sensor
    long duration, cm;   
  pinMode(pingTrigPin, OUTPUT);   
  digitalWrite(pingTrigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);   
  pinMode(pingEchoPin, INPUT);   
  duration = pulseIn(pingEchoPin, HIGH);   
  cm = microsecondsToCentimeters(duration);   
  if(cm<=50 && cm>0)   
  {   
  int d= map(cm, 1, 100, 20, 2000);   
  digitalWrite(buz, HIGH); 
     
  delay(100);   
  digitalWrite(buz, LOW);  
 
  delay(d);  
  }
  if(cm < 50){
      Serial.print(cm );
      Serial.print(" cm -- LEFT US ON..."); 
      Serial.println();   }   

    }
 //-----------------------------------------------------------------   
void RightUs(){
   // Right Ultrasonic Sensor
   long duration1, cm1;   
  pinMode(pingTrigPin1, OUTPUT);   
  digitalWrite(pingTrigPin1, LOW);
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin1, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin1, LOW);   
  pinMode(pingEchoPin1, INPUT);   
  duration1 = pulseIn(pingEchoPin1, HIGH);   
  cm1 = microsecondsToCentimeters(duration1);   
  if(cm1<=50 && cm1>0)   
  {   
  int d1= map(cm1, 1, 100, 20, 2000);   
  digitalWrite(buz1, HIGH); 
     
  delay(100);   
  digitalWrite(buz1, LOW);  
 
  delay(d1);  
  }  
   if(cm1 < 50){
      Serial.print(cm1 );
      Serial.print(" cm -- RIGHT US ON..."); 
      Serial.println();   }  
  }    
  //----------------------------------------------------------------
  void MidUs(){
    // Midle Ultrasonicsensor
  long duration2, cm2;   
  pinMode(pingTrigPin2, OUTPUT);   
  digitalWrite(pingTrigPin2, LOW);
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin2, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin2, LOW);   
  pinMode(pingEchoPin2, INPUT);   
  duration2 = pulseIn(pingEchoPin2, HIGH);   
  cm2 = microsecondsToCentimeters(duration2);   
  if(cm2<=50 && cm2>0)   
  {   
  int d2= map(cm2, 1, 100, 20, 2000);   
  digitalWrite(buz2, HIGH); 
     
  delay(100);   
  digitalWrite(buz2, LOW);  
 
  delay(d2);  
  }   
   if(cm2 < 50){
      Serial.print(cm2 );
      Serial.print(" cm -- MID US ON..."); 
      Serial.println();   }   
    
    }  

//-------------------------------------------------------------------------------
void PIRSensor(){
  // Passive Infrared Sensor
  val = digitalRead(inputPin); 
if (val == HIGH) {
digitalWrite(ledPin, HIGH); 
if (pirState == LOW) {
Serial.println("Motion detected!...");
pirState = HIGH;
}
} else {
digitalWrite(ledPin, LOW);
if (pirState == HIGH){
Serial.println("Motion ended!...");
pirState = LOW;
}
}

  
  }    
