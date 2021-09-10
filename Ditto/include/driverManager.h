/**
 * @brief Adds all function handlers from drivers to main
 * 
 * @file driverManager.h
 * @author Alex Necakov
 * @date 2019-11-22
 */

#ifndef DRIVERMANAGER_H
#define DRIVERMANAGER_H

#include <Arduino.h>
#include <SlaveDriver.h>
#include <BMP388.h>
#include <BNO055.h>
#include <MCP9600.h>
#include <MPL3115A2.h>

class DriverManager{
    public:
        DriverManager();
        void requestEvent();
        void receiveEvent(int);
        void addDriver(uint8_t);
        uint8_t readSlaveAddr();

        SlaveDriver* driverList[256];
        uint8_t numDrivers;
        uint8_t i2cReadAddr;
        uint8_t i2cSlaveAddr;

};


#endif