/**
 * @brief Serial parser to communicate to Simulink controls models
 * 
 * @file SerialSimulink.cpp
 * @author Alex Necakov
 * @date 2020-01-24
 */
#include <SerialSimulink.h>

//packets are 3 bytes big, sensor address+rw bit, reg addr, reg data (think i2c)    
uint8_t currentDevice;
uint8_t currentReg;
uint8_t currentData;

SimulinkParser::SimulinkParser(DriverManager manager){
    dm = manager;
}

void SimulinkParser::readSerial(){
    int count = 0;

    int currentByte[3];
    while (Serial.available() && count <3){
        currentByte[count++] = Serial.read();
    }

    currentDevice = currentByte[0];
    currentReg = currentByte[1];
    currentData = currentByte[2];
}

void SimulinkParser::writeSerial(){
    Serial.write(1);
}


void SimulinkParser::masterCmd(uint8_t cmdType){
    switch (cmdType){
    case 0x01://add driver
        dm.addDriver(currentData);
        break;
    
    default:
        break;
    }
}


void SimulinkParser::serialLoop(){

    readSerial();

    switch(currentDevice){
        case(0xFF)://reserved for uc wide commands
            masterCmd(currentReg);
            break;
        case 0x01 ... 0xEE:
            //driverManager(call this device and pass in regaddr and data)
        default:
            delay(500);
            break;
    }
    
}