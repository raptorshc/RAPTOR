/*

*/
#include "openlog.h"
#include "Arduino.h"

#define SD_GRN 4 // OpenLog Reset pin


/* Public Methods */
/*
 *	turn will rotate the servos to a certain configuration, based on the set time to rotate (TTR),
 * 		if reset is given as true, the servo will rotate in the opposite direction for the same amount of time.
 */
void OpenLog::init(void){
    pinMode(SD_GRN, OUTPUT);
    this->begin(9600);

    // Reset OpenLog
    digitalWrite(SD_GRN, LOW);
    delay(100);
    digitalWrite(SD_GRN, HIGH);

    delay(10);
}
/*
 *	turn will rotate the servos to a certain configuration, based on the set time to rotate (TTR),
 * 		if reset is given as true, the servo will rotate in the opposite direction for the same amount of time.
 */
void OpenLog::command(void){
      //Send three control z to enter OpenLog command mode
  //Works with Arduino v1.0
  this->write(26);
  this->write(26);
  this->write(26);

  //Wait for OpenLog to respond with '>' to indicate we are in command mode
  while(1) {
    if(this->available())
      if(this->read() == '>') break;
  }
}
/*
 *	turn will rotate the servos to a certain configuration, based on the set time to rotate (TTR),
 * 		if reset is given as true, the servo will rotate in the opposite direction for the same amount of time.
 */
void OpenLog::create_file(String fname){
  //New way
  this->print("new ");
  this->println(fname); //regular println works with OpenLog v2.51 and above

  //Wait for OpenLog to return to waiting for a command
  while(1) {
    if(this->available())
      if(this->read() == '>') break;
  }

  this->print("append ");
  this->print(fname);
  this->write(13); //This is \r

  //Wait for OpenLog to indicate file is open and ready for writing
  while(1) {
    if(this->available())
      if(this->read() == '<') break;
  }

  //OpenLog is now waiting for characters and will record them to the new file  
}

/*
 *	turn will rotate the servos to a certain configuration, based on the set time to rotate (TTR),
 * 		if reset is given as true, the servo will rotate in the opposite direction for the same amount of time.
 */
void OpenLog::read_file(String fname){
 //New way
  this->print("read ");
  this->println(fname); //regular println works with OpenLog v2.51 and above

  //The OpenLog echos the commands we send it by default so we have 'read log823.txt\r' sitting 
  //in the RX buffer. Let's try to not print this.
  while(1) {
    if(this->available())
      if(this->read() == '\r') break;
  }

  //This will listen for characters coming from OpenLog and print them to the terminal
  //This relies heavily on the SoftSerial buffer not overrunning. This will probably not work
  //above 38400bps.
  //This loop will stop listening after 1 second of no characters received
  for(int timeOut = 0 ; timeOut < 1000 ; timeOut++) {
    while(this->available()) {
      char tempString[100];
      
      int spot = 0;
      while(this->available()) {
        tempString[spot++] = this->read();
        if(spot > 98) break;
      }
      tempString[spot] = '\0';
      this->write(tempString); //Take the string from OpenLog and push it to the Arduino terminal
      timeOut = 0;
    }

    delay(1);
  }
  //This function leaves OpenLog in command mode
}