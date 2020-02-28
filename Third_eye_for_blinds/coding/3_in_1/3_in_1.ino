  const int pingTrigPin = 6;    
  const int pingEchoPin = 10; 
  int buz=11; 
  //PIR
int ledPin = 13; 
int inputPin = 2; 
int pirState = LOW; 
int val = 0;
//
  void setup() 
  { 
  pinMode(ledPin, OUTPUT); 
  pinMode(inputPin, INPUT);    
  Serial.begin(9600);   
  pinMode(buz, OUTPUT);   
  }   
  void loop()   
  {   
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
  Serial.print(cm +" ");    
  Serial.print("cm  ");   
  Serial.println();   
  delay(100);   
  //PIR
val = digitalRead(inputPin); 
if (val == HIGH) {
digitalWrite(ledPin, HIGH); 
if (pirState == LOW) {
Serial.println("Motion detected!");
pirState = HIGH;
}
} else {
digitalWrite(ledPin, LOW);
if (pirState == HIGH){
Serial.println("Motion ended!");
pirState = LOW;
}
}
  } 
    
  long microsecondsToCentimeters(long microseconds)   
  {   
    //

return microseconds / 29 / 2; 
  }   

  
