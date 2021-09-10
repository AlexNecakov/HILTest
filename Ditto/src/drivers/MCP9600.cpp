/**
 * @brief Slave driver for MCP9600 Thermocouple chip
 * 
 * @file MCP9600.cpp
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

#include <MCP9600.h>

MCP9600::MCP9600() : SlaveDriver(0x67){
    HOT_TEMP = 100;
    HOT_COLD_DELTA = 10;
    COLD_TEMP = 90;
    RAW = 3;
    STATUS = 3;
    ID = 1;
}

void MCP9600::passData(uint8_t dataAddr){
    switch(dataAddr){
        case MCP9600_HOTJUNCTION:
            Wire.write(HOT_TEMP);
            break;
        
        case MCP9600_JUNCTIONDELTA:
            Wire.write(HOT_COLD_DELTA);
            break;

        case MCP9600_COLDJUNCTION:
            Wire.write(COLD_TEMP);
            break;

        case MCP9600_RAWDATAADC:
            Wire.write(RAW);
            break;

        case MCP9600_STATUS:
            Wire.write(STATUS);
            break;

        case MCP9600_DEVICEID:
            Wire.write(ID);
            break;

        default:
            Wire.write(0x00);
            break;
    }
}