# remote-temp-sensor

this is a basic project showcasing my dabbling in multi-hardware communication project.

the goal:

to send analog sensor data from a lm-35 temperature sensor to an Raspberry Pi via an Arduino Uno and a ESP8266 module.

steps:

1.sending the data from the sensor to Arduino Uno via i/o pins.

2.sending the data from the Arduino Uno to the ESP8266 module via serial communication protocol.

3.sending the data from the ESP8266 module to the Raspberry Pi 4 via MQTT communication protocol.

4.displaying the incoming sensor data on the screen.

note:

do install mqtt on the Raspberry Pi 4 and configure the setup and modify the login id such as username and passwords.
