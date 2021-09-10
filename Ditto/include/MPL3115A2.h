/**
 * @brief Slave driver for MPL3115A2 altimeter
 * 
 * @file MPL3115A2.h
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

#ifndef MPL3115A2_H
#define MPL3115A2_H

#include <Arduino.h>
#include <Wire.h>
#include <SlaveDriver.h>

#define CHIP_INFO 0x00


class MPL3115A2 : public SlaveDriver {
    public:
        MPL3115A2();
        void passData(uint8_t);

    private:
        uint8_t PRESSURE_MSB;
        uint8_t PRESSURE_CSB;
        uint8_t PRESSURE_LSB;
        uint8_t SYS_MODE;
    
};


#endif

