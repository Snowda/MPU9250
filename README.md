MPU9250
======================

C++ MPU9250 Driver for Arduino

![MPU-9250 datasheet (PDF)](www.invensense.com/mems/gyro/documents/PS-MPU-9250A-01.pdf)

![MPU-9250 registry map (PDF)](store.invensense.com/Datasheets/invensense/RM-MPU-9250A-00.pdf)

======================
Installation
======================

Requires the Arduino Libraries
![Wire.h](http://arduino.cc/en/reference/wire) 
and 
![SPI.h](http://arduino.cc/en/Reference/SPI) 
depending on how you wish to interface with the chip.

*warning* SPI not supported yet!

Download the repo as a zip file and install throught the Arduino IDE and select:

Sketch -> Import Library -> Add Library

Make sure that if you are installing updates that you remove any pre-existing libraries called "MPU9250".

======================
Capibilities
======================

Reads accelerometer, gyroscopic and magnetic data in 3D giving 9 Degrees of Freedom.

More to be documented

======================
Disclaimer:
======================

I was not expecting this much attention this early in developement honestly. 

A large portion of this code is incomplete and broken. For now I just ask to be either patient, or fork it. 

Also, while I will now be reviewing the license agreement, the end result will both be allowed for private and public usage, just don't hold me to any commercial support. 

With this in mind please submit any pull requests and I will glady accept them once tested as I do like to end up with good code.