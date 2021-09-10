/**
 * @brief Parent class for slave drivers
 * 
 * @file SlaveDriver.h
 * @author Alex Necakov
 * @date 2020-2-23
 */

#ifndef SLAVEDRIVER_H
#define SLAVEDRIVER_H

#include <Arduino.h>
#include <Wire.h>

using namespace std;

class SlaveDriver {
 public:
  SlaveDriver();
  SlaveDriver(uint8_t);

  virtual void passData(uint8_t){};
  bool checkAddr(uint8_t);

  uint8_t slaveAddr;
  
};


#endif
