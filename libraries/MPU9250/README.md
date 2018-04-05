SparkFun MPU-9250 9 DOF IMU Arduino Library
========================================

![MPU-9250 Breakout](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/4/1/8/LSM303C_BOB.jpg)

[*MPU-9250 Breakout (BOB-13303)*](https://www.sparkfun.com/products/13303)

This is an arduino IDE library to control the MPU-9250.  It can be configured to use I<sup>2</sup>C or SPI.

This has been tested with Arduino Pro Mini.

Repository Contents
-------------------

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE.
* **/src** - Source files for the library (.cpp, .h).
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE.
* **library.properties** - General library properties for the Arduino package manager.

Example Briefs
--------------

* MinimalistExample - The **easiest** configuration.  Prints out sensor data with some sane default configuration parameters
* ConfigureExample - Same as MinimalistExample, except all of the configuration is exposed with easy to change options all spelled out

Documentation
--------------

* **[Installing an Arduino Library Guide](https://learn.sparkfun.com/tutorials/installing-an-arduino-library)** - Basic information on how to install an Arduino library.
* **[Product Repository](https://github.com/sparkfun/MPU-9250_6_DOF_IMU_Breakout)** - Main repository (including hardware files) for the MPU-9250 Breakout.
* **[Hookup Guide](https://learn.sparkfun.com/tutorials/MPU-9250-hookup-guide)** - Basic hookup guide for the MPU-9250 Breakout.

Products that use this Library
---------------------------------

* [BOB-13303](https://www.sparkfun.com/products/13339)- MPU-9250 Breakout board

Version History
---------------

* [V 1.0.0](https://github.com/sparkfun/SparkFun_MPU-9250_6_DOF_IMU_Breakout_Arduino_Library/releases/tag/V_1.0.0) -- Initial commit of Arduino 1.5+ compatible library.

SparkFun IMU Interface
---
Arduino libraries that implement this interface are guaranteed to to work interchangeably in sketches. If a project is started with 6-DOF IMU, but one realizes that the project really needs a 9-DOF sensor, the change is simple.  Include the new header file, & change the type of the IMU object(s).  All of the code written to the interface will still function.  Here is a list of the functions provided by this interface:
* `status_t begin()` - initialize IMU to sane default values
* `float readGyroX()` - read value from the gyroscope about x-axis
* `float readGyroY()` - read value from the gyroscope about y-axis
* `float readGyroZ()` - read value from the gyroscope about z-axis
* `float readAccelX()` - read value from the accelerometer in x-axis
* `float readAccelY()` - read value from the accelerometer in y-axis
* `float readAccelZ()` - read value from the accelerometer in z-axis
* `float readMagX()` - read value from the magnetometer in x-axis
* `float readMagY()` - read value from the magnetometer in y-axis
* `float readMagZ()` - read value from the magnetometer in z-axis
* `float readTempC()` - read temperature of sensor in ˚C
* `float readTempF()` - read temperature of sensor in ˚F
* `status_t getStatus()` - read the status code of the previous operation

All functions other than `getStatus()` will update the status code depending on how their operation went.  Errors in the read functions can be detected by them returning `NAN` or calling `getStatus()`.

If an IMU doesn't support a set of functions, they will always return `NAN` and set the status to `IMU_NOT_SUPPORTED`.

Other, more advanced features may be available depending on the sensor.  See the documentation for the particular sensor for information on advanced feature support.

Using as a Template
---

* Create your repo
* pull [/src/SparkFunIMU.h](https://github.com/sparkfun/SparkFun_MPU-9250_6_DOF_IMU_Breakout_Arduino_Library/blob/master/src/SparkFunIMU.h) into it

License Information
-------------------

This product is _**open source**_!

Please review the LICENSE.md file for license information.

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.
