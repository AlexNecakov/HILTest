/**
 * @brief Slave driver for BMP388 altimeter
 * 
 * @file BMP388.h
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

#ifndef BMP388_H
#define BMP388_H

#include <Arduino.h>
#include <Wire.h>
#include <SlaveDriver.h>

class BMP388 : public SlaveDriver {

    public:

        BMP388();
        void passData(uint8_t);

    private:
        //address here
        uint8_t BMP3XX_DEFAULT_ADDRESS = 0x77;
        uint8_t CHIP_ID = 0x50;
        
        //random numbers
        uint8_t PRESS_MSB_23_16;
        uint8_t PRESS_LSB_15_8;
        uint8_t PRESS_XLSB_7_0;
        uint8_t TEMP_MSB_23_16;
        uint8_t TEMP_LSB_15_8;
        uint8_t TEMP_XLSB_7_0;

};

#endif

