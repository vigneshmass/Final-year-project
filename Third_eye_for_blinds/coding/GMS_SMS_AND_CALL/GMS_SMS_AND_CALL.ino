int state = 0;
const int pin = 2;


#include <SoftwareSerial.h>
int pushbuttn=7;
int value,i;
SoftwareSerial mySerial(9, 10);



void setup() {
 Serial.begin(9600);
 pinMode( pushbuttn,INPUT);

}

void loop() {
  Message();
  
 VoiceCall();

}
void VoiceCall(){
   value=digitalRead(pushbuttn);
  Serial.println(value);
  
  while( value==HIGH)
  {
    if(i==0)//i variable to ensure that only one call request will be sent by gsm during pressing and holding the pushbutton;
        {
          Serial.println("Calling through GSM Modem");
          mySerial.begin(9600);//setting baudrate at 9600;
          delay(1000);
          mySerial.println("ATD8523916603;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
          Serial.println("Called ATD8523916603");
          delay(1000);
          if (mySerial.available())
          Serial.write(mySerial.read());
          i++;
         }//end of if
         value=digitalRead(pushbuttn);
  }//end of while
   i=0;
  
  }

void Message(){
  if (digitalRead(pin) == HIGH && state == 0) {
    Serial.print("\r");
    delay(1000);
    Serial.print("AT+CMGF=1\r");
    delay(1000);
    /*Replace XXXXXXXXXX to 10 digit mobile number & ZZ to 2 digit country code*/
    Serial.print("AT+CMGS=\"+918523916603\"\r");
    delay(1000);
    //The text of the message to be sent.
    Serial.print("hi i am vignesh");
    delay(1000);
    Serial.write(0x1A);
    delay(1000);
    state = 1;
  }
 if (digitalRead(pin) == LOW && state == 1) {
    state = 0;
  }
  
  }
