/**
 * @brief Slave driver for BMP388 altimeter
 * 
 * @file BMP388.cpp
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

#include <BMP388.h>

BMP388::BMP388() : SlaveDriver(0x76){

    PRESS_MSB_23_16 = 0xFF;
    PRESS_LSB_15_8 = 0xFF;
    PRESS_XLSB_7_0 = 0xFF;
    TEMP_MSB_23_16 = 0x00;
    TEMP_LSB_15_8 = 0x00;
    TEMP_XLSB_7_0 = 0x00;
}

void BMP388::passData(uint8_t dataAddr){
    switch (dataAddr) {
        case 0x00:
            Wire.write(CHIP_ID);
            break;
            
        case 0x04:
            Wire.write(PRESS_XLSB_7_0);
            break;
        
        case 0x05:
            Wire.write(TEMP_LSB_15_8);
            break;

        case 0x06:
            Wire.write(TEMP_MSB_23_16);
            break;

        case 0x07:
            Wire.write(TEMP_XLSB_7_0);
            break;
        
        case 0x08:
            Wire.write( TEMP_LSB_15_8);
            break;

        case 0x09:
            Wire.write(TEMP_MSB_23_16); 
            break;

        default:
            Wire.write(0x00);
        }
    
}