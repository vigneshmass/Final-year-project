/* Code Written by DPV TECHNOLOGY. WE have explained all the code in the grey comments.
we recommend you to go over the code, examine it, play with it, improve it and modify it according to your needs. 
SUBSCRIBE DPV TECHNOLOGY: 
https://www.youtube.com/dpvtechnology?sub_confirmation=1

*/
 
 #include <SoftwareSerial.h>
int pushbuttn=7;
int value,i;
SoftwareSerial mySerial(9, 10);//(Rx TX) of arduino;  Tx of gsm should be connected to pin 9 of arduino and Rx should be at 10; 

void setup()
{

Serial.begin(9600);
pinMode( pushbuttn,INPUT);

}

void loop() 
{
  
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
}//end of void loop  
