/**
 * @brief Slave driver for BNO055 imu
 * 
 * @file BNO055.h
 * @author Alex Necakov
 * @date 2020-2-23
 */

#ifndef BNO055_H
#define BNO055_H

#include <Arduino.h>
#include <Wire.h>
#include <SlaveDriver.h>

class BNO055 : public SlaveDriver{

  public:
    BNO055();
    void passData(uint8_t);

  private:
    uint8_t BNO055_I2C_ADDR = 0x28;
    uint8_t BNO055_CHIP_ID_ADDR = 0xA0;
    uint8_t BNO055_OPR_MODE_ADDR = 0X00;

    uint8_t CHIP_ID = 0x50;

    //Change these values to change the data you are simulating
    uint8_t BNO055_ACCEL_DATA_X_LSB;
    uint8_t BNO055_ACCEL_DATA_X_MSB;
    uint8_t BNO055_ACCEL_DATA_Y_LSB;
    uint8_t BNO055_ACCEL_DATA_Y_MSB;
    uint8_t BNO055_ACCEL_DATA_Z_LSB;
    uint8_t BNO055_ACCEL_DATA_Z_MSB;
};

#endif
