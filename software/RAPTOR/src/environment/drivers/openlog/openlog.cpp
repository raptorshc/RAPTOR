#include "openlog.h"

Openlog::Openlog(int rx, int tx) : SoftwareSerial (rx, tx) {
   //int resetOpenLog = 4; //This pin resets OpenLog. Connect pin 4 to pin GRN on OpenLog.

   pinMode(resetOpenLog, OUTPUT);
   OpenLog.begin(9600);

   //Reset OpenLog
   digitalWrite(resetOpenLog, LOW);
   delay(100);
   digitalWrite(resetOpenLog, HIGH);

   uint8_t count = 0;
      
   //Wait for OpenLog to respond with '<' to indicate it is alive and recording to a file
   while (count++ < 5 || !(OpenLog.available() && OpenLog.read() == '<'));
 }
 

 //This function pushes OpenLog into command mode
 void Openlog::command(void) {
   //Send three control z to enter OpenLog command mode
   //Works with Arduino v1.0
   OpenLog.write(26);
   OpenLog.write(26);
   OpenLog.write(26);

   //Wait for OpenLog to respond with '>' to indicate we are in command mode
   while (count++ < 5 || !(OpenLog.available() && OpenLog.read() == '<'));
 }

char[] Openlog::read(char *request) {

   OpenLog.print("disk");
   OpenLog.write(13); //This is \r

   //New way
   //OpenLog.print("read ");
   //OpenLog.println(filename); //regular println works with OpenLog v2.51 and above

   //The OpenLog echos the commands we send it by default so we have 'disk\r' sitting 
   //in the RX buffer. Let's try to not print this.
   while (count++ < 5 || !(OpenLog.available() && OpenLog.read() == '<'));  
 }
