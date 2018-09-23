/*
 * imu.h - 
 * Library written for use with Adafruit BNO055 sensor.
 * Utilizes Adafruit BNO055 library.
 * Part of the RAPTOR project, authors: Sean Widmier, Colin Oberthur
*/
#ifndef IMU_H_
#define IMU_H_

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

class BNO : public Adafruit_BNO055{
    public:
        BNO() : Adafruit_BNO055(55){}
        bool init(void);
        void update(void);

        sensors_event_t data;
};

#endif