/**
 * @brief Main arduino setup and loop for Ditto
 * 
 * @file main.cpp
 * @author Alex Necakov
 * @date 2020-2-23
 */

#include <Arduino.h>
#include <driverManager.h>
#include <SerialSimulink.h>

DriverManager slaveDrivers;
SimulinkParser simulinkComm = SimulinkParser(slaveDrivers);

void requestEvent(){
  slaveDrivers.requestEvent();
}

void receiveEvent(int numBytes){
  slaveDrivers.receiveEvent(numBytes);
}

void setup(){

  Wire.begin(0x08); //change as needed
  Wire.onRequest(requestEvent);//change as needed
  Wire.onReceive(receiveEvent);//everytime slave receives, call receiveEvent
}

void loop() {
  simulinkComm.serialLoop();
  delay(500);//change as needed
}
