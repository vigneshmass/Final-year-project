#include <GSM.h>
#include <GSM3CircularBuffer.h>
#include <GSM3MobileAccessProvider.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3MobileClientProvider.h>
#include <GSM3MobileClientService.h>
#include <GSM3MobileDataNetworkProvider.h>
#include <GSM3MobileMockupProvider.h>
#include <GSM3MobileNetworkProvider.h>
#include <GSM3MobileNetworkRegistry.h>
#include <GSM3MobileServerProvider.h>
#include <GSM3MobileServerService.h>
#include <GSM3MobileSMSProvider.h>
#include <GSM3MobileVoiceProvider.h>
#include <GSM3ShieldV1.h>
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1BandManagement.h>
#include <GSM3ShieldV1BaseProvider.h>
#include <GSM3ShieldV1CellManagement.h>
#include <GSM3ShieldV1ClientProvider.h>
#include <GSM3ShieldV1DataNetworkProvider.h>
#include <GSM3ShieldV1DirectModemProvider.h>
#include <GSM3ShieldV1ModemCore.h>
#include <GSM3ShieldV1ModemVerification.h>
#include <GSM3ShieldV1MultiClientProvider.h>
#include <GSM3ShieldV1MultiServerProvider.h>
#include <GSM3ShieldV1PinManagement.h>
#include <GSM3ShieldV1ScanNetworks.h>
#include <GSM3ShieldV1ServerProvider.h>
#include <GSM3ShieldV1SMSProvider.h>
#include <GSM3ShieldV1VoiceProvider.h>
#include <GSM3SMSService.h>
#include <GSM3SoftSerial.h>
#include <GSM3VoiceCallService.h>

// libraries
#include <GSM.h>

#define PINNUMBER ""

// initialize the library instance
GSM gsmAccess; // include a 'true' parameter for debug enabled
GSM_SMS sms;
GSMVoiceCall vcs;

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 6;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup()
{
 // initialize the LED pin as an output:
 pinMode(ledPin, OUTPUT);    
 // initialize the pushbutton pin as an input:
 pinMode(buttonPin, INPUT);    
 // initialize serial communications
 Serial.begin(9600);

 Serial.println("SMS Messages Sender");

 // connection state
 boolean notConnected = true;

 // Start GSM shield
 // If your SIM has PIN, pass it as a parameter of begin() in quotes
 while(notConnected)
 {
   if(gsmAccess.begin(PINNUMBER)==GSM_READY)
     notConnected = false;
   else
   {
     Serial.println("Not connected");
     delay(1000);
   }
 }

 Serial.println("GSM initialized");
}

void loop()
{

if (buttonState == HIGH) {  
   // turn LED on:  
   digitalWrite(ledPin, HIGH);

 if(vcs.voiceCall("8523916603"))
       {
         Serial.println("Call Established. Enter line to end");
         // Wait for some input from the line
         while(Serial.read()!='\n' && (vcs.getvoiceCallStatus()==TALKING));
         // And hang up
         vcs.hangCall();
       }
       Serial.println("Call Finished");
 }
 }
