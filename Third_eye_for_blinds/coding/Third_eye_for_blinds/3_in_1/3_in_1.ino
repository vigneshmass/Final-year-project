

  const int pingTrigPin1 = 12;    
  const int pingEchoPin1 = 10; 
   const int pingTrigPin2 = 2;    
  const int pingEchoPin2 = 2; 
  int buz1=5; 
  int buz2=2;
  void setup() 
  {   
  Serial.begin(9600);   
  pinMode(buz1, OUTPUT);   
  pinMode(buz2, OUTPUT);   
  }   
  void loop()   
  {   
  long duration, cm;   
  pinMode(pingTrigPin1, OUTPUT);   
   pinMode(pingTrigPin2, OUTPUT);  
  digitalWrite(pingTrigPin1, LOW);   
  digitalWrite(pingTrigPin2, LOW); 
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin1, HIGH); 
  digitalWrite(pingTrigPin2, HIGH);  
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin1, LOW);   
  digitalWrite(pingTrigPin2, LOW); 
  pinMode(pingEchoPin1, INPUT);   
   pinMode(pingEchoPin2, INPUT);  
  duration = pulseIn(pingEchoPin1, HIGH); 
  duration = pulseIn(pingEchoPin2, HIGH);     
  cm = microsecondsToCentimeters(duration);   
  if(cm<=50 && cm>0)   
  {   
  int d= map(cm, 1, 100, 20, 2000);   
  digitalWrite(buz1, HIGH);   
   digitalWrite(buz2, HIGH);  
  delay(100);   
  digitalWrite(buz1, LOW);
   digitalWrite(buz2, LOW);     
  delay(d);  
  }   
  Serial.print(cm);    
  Serial.print("cm");   
  Serial.println();   
  delay(100);   
  }   
  long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  }   
