#include "openlog.h"

//Connect TXO of OpenLog to pin 3, RXI to pin 2
SoftwareSerial OpenLog(3, 2); //Soft RX on 3, Soft TX out on 2
//SoftwareSerial(rxPin, txPin)

int resetOpenLog = 4; //This pin resets OpenLog. Connect pin 4 to pin GRN on OpenLog.

 //This function pushes OpenLog into command mode
 void Openlog::goToCommandMode(void) {
   //Send three control z to enter OpenLog command mode
   //Works with Arduino v1.0
   OpenLog.write(26);
   OpenLog.write(26);
   OpenLog.write(26);

   //Wait for OpenLog to respond with '>' to indicate we are in command mode
   while(1) {
     if(OpenLog.available())
       if(OpenLog.read() == '>') break;
   }
 }

 void Openlog::setupOpenLog(void) {
   pinMode(resetOpenLog, OUTPUT);
   OpenLog.begin(9600);

   //Reset OpenLog
   digitalWrite(resetOpenLog, LOW);
   delay(100);
   digitalWrite(resetOpenLog, HIGH);

   //Wait for OpenLog to respond with '<' to indicate it is alive and recording to a file
   while(1) {
     if(OpenLog.available())
       if(OpenLog.read() == '<') break;
   }
 }
 void Openlog::readDisk() {

   OpenLog.print("disk");
   OpenLog.write(13); //This is \r

   //New way
   //OpenLog.print("read ");
   //OpenLog.println(filename); //regular println works with OpenLog v2.51 and above

   //The OpenLog echos the commands we send it by default so we have 'disk\r' sitting 
   //in the RX buffer. Let's try to not print this.
   while(1) {
     if(OpenLog.available())
       if(OpenLog.read() == '\r') break;
   }  
 }

