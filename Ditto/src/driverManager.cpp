/**
 * @brief Adds all function handlers from drivers to main
 * 
 * @file driverManager.cpp
 * @author Alex Necakov
 * @date 2019-11-22
 */

#include <driverManager.h>

DriverManager::DriverManager(){
    numDrivers = 0;
}

void DriverManager::addDriver(uint8_t slaveAddr){
    switch (slaveAddr){//these need to be made dynamically to survive the function call
        case 0x28:{
            BNO055* bno = new BNO055();
            driverList[numDrivers] = bno;
            numDrivers++;
        }
            break;
        case 0x76:{
            BMP388* bmp = new BMP388();
            driverList[numDrivers] = bmp;
            numDrivers++;
        }
            break;
        case 0x67:{
            MCP9600* mcp = new MCP9600();
            driverList[numDrivers] = mcp;
            numDrivers++;
        }
            break;
        case 0x60:{
            MPL3115A2* mpl = new MPL3115A2();
            driverList[numDrivers] = mpl;
            numDrivers++;
        }
            break;
        default:
            break;
    }
}

void DriverManager::requestEvent(){//check list of open drivers vs the slave addr
    i2cSlaveAddr = readSlaveAddr();
    for (int i = 0; i < numDrivers; i++){
        if(driverList[numDrivers]->checkAddr(i2cSlaveAddr)){
            driverList[numDrivers]->passData(i2cReadAddr);
            break;
        }
    }
}

void DriverManager::receiveEvent(int numBytes){//store last byte
    while (Wire.available()){
        i2cReadAddr = Wire.read();
    }
}

uint8_t DriverManager::readSlaveAddr(){//read digital pins as byte for slave address
    uint8_t addr = 0x00;
    for (int i = 7; i > 0; i--){
        bitWrite(addr,i,digitalRead(i));
    }
    
    return addr;
}
