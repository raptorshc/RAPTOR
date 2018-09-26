/*
  ContinuousServo.h - 
  Library written for use with continuous rotation servos.
  Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef OPENLOG_H_
#define OPENLOG_H_

#include "Arduino.h"
#include <SoftwareSerial.h>

class OpenLog : public SoftwareSerial
{
public:
    OpenLog(SoftwareSerial &s) : SoftwareSerial(&s);
    
    void init(void);
    void command(void);
    void create_file(String fname);
    void read_file(String fname);
};

#endif
