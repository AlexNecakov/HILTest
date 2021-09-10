/**
 * @brief Slave driver for BNO055 imu
 * 
 * @file BNO055.cpp
 * @author Alex Necakov
 * @date 2020-2-23
 */

#include <BNO055.h>


BNO055::BNO055():SlaveDriver(0x28){
  BNO055_ACCEL_DATA_X_LSB = 0b00000000;
  BNO055_ACCEL_DATA_X_MSB = 0b00000000;
  BNO055_ACCEL_DATA_Y_LSB = 0b00000000;
  BNO055_ACCEL_DATA_Y_MSB = 0b00000000;
  BNO055_ACCEL_DATA_Z_LSB = 0b00000000;
  BNO055_ACCEL_DATA_Z_MSB = 0b00000000;
}

void BNO055::passData(uint8_t dataAddr){
  switch (dataAddr)
  {
  //Driver begin checks this address to see if it is talking to the right kind of chip
  case 0x00:
    Wire.write(BNO055_CHIP_ID_ADDR);
    break;
  //Driver begin checks this address to see what mode chip is on
  case 0x3D:
    Wire.write(BNO055_OPR_MODE_ADDR);
    break;
  //get vector accel checks these 6 addresses in order and puts them in an array, just increments from 0x08
  case 0x08:
    Wire.write(BNO055_ACCEL_DATA_X_LSB);
    Wire.write(BNO055_ACCEL_DATA_X_MSB);
    Wire.write(BNO055_ACCEL_DATA_Y_LSB);
    Wire.write(BNO055_ACCEL_DATA_Y_MSB);
    Wire.write(BNO055_ACCEL_DATA_Z_LSB);
    Wire.write(BNO055_ACCEL_DATA_Z_MSB);
    break;

  default:
    Wire.write(0xA0);
    break;
  }
}