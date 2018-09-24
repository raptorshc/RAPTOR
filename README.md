# RAPTOR

The Ram-Air Parafoil Targeted Object Return (RAPTOR) system is an autonomous payload designed for the simplification of high-altitude balloon payload recovery.

The project aims to alter final landing location by deflecting an attached parafoil. An Arduino Uno will control two servos that can trim the parafoil's brake lines to change course.  

This repository contains all of the flight code used for the project, along with data collected and analyzed to gauge flight success.

## 1. Payload Design Overview

to be written

## 2. Flight Software Design

to be written

## 3. Payload Iterations

### **Kestrel**

'Kestrel' is part of the naming convention chosen for RAPTOR as it goes through various design and developement stages. Kestrel is the smallest raptor in North America, and was chosen to represent RAPTOR's first iteration, or the '0.5' version of the project.

Kestrel was designed and built to be a testing payload, where we could fly our environmental sensors, continuous servos and solenoids to test their reliability and power consumption on a high altitude flight.

### **Falcon**

'Falcon' is the '1.0' version of the project. Falcon began when we made a completely new payload, with the plan of making our first real guided flight in mind. This is the first iteration of the payload with the parafoil attached, where all of the major flight goals for the project will be achieved. These goals include cut down, parafoil deployment, and guided descent.

## 4. Flight Reports

### **April 21, 2018** (UAH Space Hardware Club BalloonSat Flight 75)

Our first flight took the Kestrel payload up to 100,000ft, where the components performed nearly perfectly, with only one measured failure of a solenoid. The following graphs are constructed from the data collected during the flight.



### **August 31, 2018** (UAH Space Hardware Club BalloonSat Flight 77)

For our second flight we gathered additional data using the Kestrel payload. A major issue during the flight was that the Arduino power cycled while near the apogee of the flight. Due to a mistake in the code, a baseline pressure is taken when the board initializes, so the altitude during descent tended into the negative values. The following graphs show adjusted data from the flight for ascent.


### **September 29, 2018** (UAH Space Hardware Club BalloonSat Flight 78)

//

## 5. Project Progress

to be written

## 6. Members

to be written

## 7. Software Use

Found under libraries/ are the classes utilized in the main .ino section. Some of these are completely custom written, some are adapted from other's code. Where applicable, the source has been noted.

Helpful link for installing libraries: <https://www.arduino.cc/en/hacking/libraries>

**Summary:**
Copy the contents of the 'libraries' folder into Documents\Arduino\libraries.
The RAPTOR.ino file should then happily compile in the Arduino IDE.