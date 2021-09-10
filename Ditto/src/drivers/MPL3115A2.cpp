/**
 * @brief Slave driver for MPL3115A2 altimeter
 * 
 * @file MPL3115A2.cpp
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

#include <MPL3115A2.h>

MPL3115A2::MPL3115A2() : SlaveDriver(0x60) {

    //these are random values
    PRESSURE_MSB = 0xAD;
    PRESSURE_CSB = 0x73;
    PRESSURE_LSB = 0xE3;
    SYS_MODE = 0x20;
}

void MPL3115A2::passData(uint8_t dataAddr){
    switch(dataAddr){
        case 0x00://sensor status register
            Wire.write(CHIP_INFO);
            break;

        case 0x01://pressure data MSB
            Wire.write(PRESSURE_MSB);
            break;

        case 0x02://pressure data CSB
            Wire.write(PRESSURE_CSB);
            break;
        
        case 0x03://pressure data LSB
            Wire.write(PRESSURE_LSB);
            break;

        case 0x11://system mode register
            Wire.write(SYS_MODE);

        default:
            Wire.write(0x00);

    }
}