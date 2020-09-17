  const int pingTrigPin = 12;    
  const int pingEchoPin = 9; 
  int buz=13; 
  void setup() 
  {    
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
  if(cm>50){
  Serial.print(cm); 
  Serial.print(" cm"); 
  Serial.print(" --->OFF"); 
  }else{
    Serial.print(cm); 
  Serial.print(" cm");  
  Serial.print(" --->ON");  
  }
  Serial.println();   
  delay(100);   
  }   
  long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  }   
