/**
 * @brief Parent class for slave drivers
 * 
 * @file SlaveDriver.cpp
 * @author Alex Necakov
 * @date 2020-2-23
 */

#include <SlaveDriver.h>

SlaveDriver::SlaveDriver(){//default constructor, makes dummy sensor
  slaveAddr = 0x00;
}

SlaveDriver::SlaveDriver(uint8_t sAddress){
  slaveAddr = sAddress;
}

bool SlaveDriver::checkAddr(uint8_t address){//return true 
  return (address == slaveAddr) ? true : false;
}