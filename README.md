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

![alt text](https://lh3.googleusercontent.com/yJp7Rl4tlh0OgynnB0pwqxiqb4GSry8reSSILUXDwRd5CED4hvreXAOTxB36PlfS6nvmWq1V5MiOyp7Bis8rF3g8JE0Oqanw4t9SUEjYtItWJUzEscm9GlXeQy7c87zzbjJ_WzJdIuUwWjhM93PkIns-0FYcOpU8xDzCH6Ze0wD2_3bIjE-ypP3AcKUHbIJy4IUB86maOxbvp_ImD1bnjD6u1Gk7OkCzfXJR9hdCCMFqlngcm56nwWZbPGF4-TE0t63B0GotCJmi-IbmLTaqOmXq_UMarg7PiEs0iMEoNK_E3CIcfkmG6do2ifHMahkhrlXl-hDUADyxodFllPnLSKQCDogX26wtK_2kbTWECWZgkv6bbQi-hTY4Z7aDev4EhqDO0LPZ4bpZMD6goSjPPxSNEnR5Et_jjw9HPDWlF-xWUBQAuQz-VHXZf1wwIPo4YJ-hfvKorc5dKjW8jGdo93sgWYhCdh1y8_lIsHr_W2Ll5liXtCqrEy8m_VX4kIWQMELzsu1o07mh7myIgIqpDSEzJ60L7k321RNn8hDGWb2Y82E0vZ5qvwWa8ZqKYH6OXC4CJ-Vjt-3qjoJtlSXHhQlk1cRW6SRVriCUeESZMsNHbSpocSI1EeN2J4-sQ-jB=w640-h480-no "Pressure vs Time, with Solenoid Failure Markings")

![alt text]( https://lh3.googleusercontent.com/o0mIxF9JpTCW6p4-lqHFurN032vhSwak0O-0916o6F6O7LAnJ_aOQhJlaf2M4cd4pFyrAL5t6rdUJKfMR4ZkQsk-fCoIFAWFzNFy1YEiZ4ywFi4ZQsuEcB9D1KTloZXDjF0vYvFdRT8I6whbH9eXGDMrW1pF8fU-ode9iUjT89ON-45uyWiq1O6yWPkVVu-d5cUqWAT0grQv5DsArr3dlqi4KNMW4X2lQBzKB5s9GIfAufiF1Di9rTAAF0E3c74gfjZwB-d6Ytg9FaDoTxDn2MhPcVrfUKBEtZKRTLo8erD8Vgq89sy1f4834WoS8XgF5q_Wi7MSM2GpKTmqX_B2gydXwuPWlM3H_2TrWNvwGbhPs-MXHr6mVQXRII_N9rgdHwJk_Zw4FyJ0VciDm9MFl3ktjZEayzCG4I1Irl8m6_wDF_QWiISo4ycMos6EsyfTj1rtdBza8v9ezVyRnK6vijcEkrmjineadoEkculacf6ZdSMiAklYv6Ft1EMe6fH91DpYTu-vJQEyVPyUjGvEnvXAZhmuQV4eM_kY-27H0Y-Ny4zwNg4yrA3Hd2eUDqEm4s_CRX5Cdk5N-sFd7zbHQK70AVQ9KG8g7XHPbRM0v_tN7a6QpNNvVbvWWc_uqCJJ=w640-h480-no "Pressure vs Time, with Solenoid Failure Markings")

![alt text](https://lh3.googleusercontent.com/yJp7Rl4tlh0OgynnB0pwqxiqb4GSry8reSSILUXDwRd5CED4hvreXAOTxB36PlfS6nvmWq1V5MiOyp7Bis8rF3g8JE0Oqanw4t9SUEjYtItWJUzEscm9GlXeQy7c87zzbjJ_WzJdIuUwWjhM93PkIns-0FYcOpU8xDzCH6Ze0wD2_3bIjE-ypP3AcKUHbIJy4IUB86maOxbvp_ImD1bnjD6u1Gk7OkCzfXJR9hdCCMFqlngcm56nwWZbPGF4-TE0t63B0GotCJmi-IbmLTaqOmXq_UMarg7PiEs0iMEoNK_E3CIcfkmG6do2ifHMahkhrlXl-hDUADyxodFllPnLSKQCDogX26wtK_2kbTWECWZgkv6bbQi-hTY4Z7aDev4EhqDO0LPZ4bpZMD6goSjPPxSNEnR5Et_jjw9HPDWlF-xWUBQAuQz-VHXZf1wwIPo4YJ-hfvKorc5dKjW8jGdo93sgWYhCdh1y8_lIsHr_W2Ll5liXtCqrEy8m_VX4kIWQMELzsu1o07mh7myIgIqpDSEzJ60L7k321RNn8hDGWb2Y82E0vZ5qvwWa8ZqKYH6OXC4CJ-Vjt-3qjoJtlSXHhQlk1cRW6SRVriCUeESZMsNHbSpocSI1EeN2J4-sQ-jB=w640-h480-no "Pressure vs Time, with Solenoid Failure Markings")



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