#include "src/raptor.h"
#include <Streaming.h>
// #include <avr/wdt.h>
// #include "src/test/test.h"
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

Raptor *raptor;

void setup()
{
    // wdt_enable(WDTO_2S); // TODO MAKE SURE WE'RE PATTING THE DOG IN THE FINAL CODE
    raptor = new Raptor();

    // Serial.println("Adafruit GPS library basic test!");

    // GPS.begin(9600);
    // GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // RMC (recommended minimum), GGA (fix data) + altitude
    // GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);    // 1 Hz update rate
    // GPS.sendCommand(PGCMD_ANTENNA);               // Request updates on antenna status

    // // set up timer counter for interrupt
    // OCR0A = 0xAF;
    // TIMSK0 |= _BV(OCIE0A);

    // uint32_t timer = millis();
}

void loop()
{
    raptor->launch();
    // raptor->ascent();
    // raptor->descent();
    // raptor->landed();

    // if a sentence is received, we can check the checksum, parse it...
    // if (GPS.newNMEAreceived())
    // {
    //     // a tricky thing here is if we print the NMEA sentence, or data
    //     // we end up not listening and catching other sentences!
    //     // so be very wary if using OUTPUT_ALLDATA and trytng to print out data
    //     //Serial.println(GPS.lastNMEA());   // this also sets the newNMEAreceived() flag to false

    //     if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
    //         return;                     // we can fail to parse a sentence in which case we should just wait for another
    // }

    // // if millis() or timer wraps around, we'll just reset it
    // if (timer > millis())
    //     timer = millis();

    // // approximately every 2 seconds or so, print out the current stats
    // if (millis() - timer > 2000)
    // {
    //     timer = millis(); // reset the timer

    //     Serial.print("\nTime: ");
    //     Serial.print(GPS.hour, DEC);
    //     Serial.print(':');
    //     Serial.print(GPS.minute, DEC);
    //     Serial.print(':');
    //     Serial.print(GPS.seconds, DEC);
    //     Serial.print('.');
    //     Serial.println(GPS.milliseconds);
    //     Serial.print("Date: ");
    //     Serial.print(GPS.day, DEC);
    //     Serial.print('/');
    //     Serial.print(GPS.month, DEC);
    //     Serial.print("/20");
    //     Serial.println(GPS.year, DEC);
    //     Serial.print("Fix: ");
    //     Serial.print((int)GPS.fix);
    //     Serial.print(" quality: ");
    //     Serial.println((int)GPS.fixquality);
    //     if (GPS.fix)
    //     {
    //         Serial.print("Location: ");
    //         Serial.print(GPS.latitude, 4);
    //         Serial.print(GPS.lat);
    //         Serial.print(", ");
    //         Serial.print(GPS.longitude, 4);
    //         Serial.println(GPS.lon);
    //         Serial.print("Location (in degrees, works with Google Maps): ");
    //         Serial.print(GPS.latitudeDegrees, 4);
    //         Serial.print(", ");
    //         Serial.println(GPS.longitudeDegrees, 4);

    //         Serial.print("Speed (knots): ");
    //         Serial.println(GPS.speed);
    //         Serial.print("Angle: ");
    //         Serial.println(GPS.angle);
    //         Serial.print("Altitude: ");
    //         Serial.println(GPS.altitude);
    //         Serial.print("Satellites: ");
    //         Serial.println((int)GPS.satellites);
    //     }
    // }
}

// /*
//  *  interrupt each millisecond to read from the GPS.
//  */
// SIGNAL(TIMER0_COMPA_vect)
// {
//     // wdt_reset(); // pat the dog
//     // static int counter = 0;
//     // Serial << "reading gps " << counter++ << "\n";
//     char c = raptor->environment->gps->read();
//     // if (c)
//     //     UDR0 = c;
// }

// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
SIGNAL(TIMER0_COMPA_vect)
{
    char c = raptor->environment->gps->read();
}