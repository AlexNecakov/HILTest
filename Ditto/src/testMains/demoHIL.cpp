/**
 * @brief Proof of concept for Arduino based HIL for avionics testing
 * 
 * @file demoHIL.cpp
 * @author Alex Necakov
 * @date 2019-05-02
 */

// #include <Arduino.h>
// #include <Wire.h>

// uint8_t hilMISO = 12;
// uint8_t hilMOSI = 11;
// uint8_t hilSCK = 13;
// uint8_t SPImode = 8;

// uint8_t CS_baro = 10;

// //Last byte master "wrote" to slave
// uint8_t i2cReadAddr;
// uint8_t spiRegAddr;
// uint8_t spiRegData;

// //7 bit imu address
// uint8_t BNO055_I2C_ADDR = 0x28;
// uint8_t BNO055_CHIP_ID_ADDR = 0xA0;
// uint8_t BNO055_OPR_MODE_ADDR = 0X00;

// //Change these values to change the IMU accel data you are simulating
// uint8_t BNO055_ACCEL_DATA_X_LSB;
// uint8_t BNO055_ACCEL_DATA_X_MSB;
// uint8_t BNO055_ACCEL_DATA_Y_LSB;
// uint8_t BNO055_ACCEL_DATA_Y_MSB;
// uint8_t BNO055_ACCEL_DATA_Z_LSB;
// uint8_t BNO055_ACCEL_DATA_Z_MSB;

// //baro static registers
// uint8_t CHIP_ID = 0x50;

// //baro data registers
// uint8_t PRESS_MSB_23_16;
// uint8_t PRESS_LSB_15_8;
// uint8_t PRESS_XLSB_7_0;
// uint8_t TEMP_MSB_23_16;
// uint8_t TEMP_LSB_15_8;
// uint8_t TEMP_XLSB_7_0;


// //called when master does an i2c request, master reads whatever values you write here
// void requestEvent(){
//   switch (i2cReadAddr){
//     //Driver begin checks this address to see if it is talking to the right kind of chip
//     case 0x00:
//       Wire.write(BNO055_CHIP_ID_ADDR);
//       break;
//     //Driver begin checks this address to see what mode chip is on
//     case 0x3D:
//       Wire.write(BNO055_OPR_MODE_ADDR);
//       break;
//     //get vector accel checks these 6 addresses in order and puts them in an array, just increments from 0x08
//     case 0x08:
//       Wire.write(BNO055_ACCEL_DATA_X_LSB);
//       Wire.write(BNO055_ACCEL_DATA_X_MSB);
//       Wire.write(BNO055_ACCEL_DATA_Y_LSB);
//       Wire.write(BNO055_ACCEL_DATA_Y_MSB);
//       Wire.write(BNO055_ACCEL_DATA_Z_LSB);
//       Wire.write(BNO055_ACCEL_DATA_Z_MSB);
//       break;

//     default:
//       Wire.write(0xA0);
//       break;
//   }
  
// }

// //called when master does an i2c write
// void receiveEvent(int bytes){
//   while(Wire.available()){

//     //we don't acutally change registers on the hitl slave, but store the value we receive in case master is trying to do a read
//     i2cReadAddr = Wire.read();
//   }
// }

// //called when master does a begin transaction
// void spiEvent() {
//   uint8_t arr[0x7f];// initialized send array to something long to prevent spi transfer failure
//   Serial.print("Spi event start with reg addr: ");

//   //spiRegAddr = baro.popr() & 0x7f;//store the first byte from the master, this is reg. Only 7 bits of read addr are used, first is r/w bit so we bitwise and to strip it
//   //baro.pushr(0x00); //send dummy byte back, 

//   Serial.println(spiRegAddr, HEX);
//   switch (spiRegAddr){
//     case 0x00://asking for chip id
//       arr[0] = CHIP_ID;
//       break;
    
//     case 0x04://pressure and temp data are always called at the same time
//       arr[0] = PRESS_XLSB_7_0;
//       arr[1] = PRESS_LSB_15_8;
//       arr[2] = PRESS_MSB_23_16;
//       arr[3] = TEMP_XLSB_7_0;
//       arr[4] = TEMP_LSB_15_8;
//       arr[5] = TEMP_MSB_23_16;
//       break;

//     default://default to sending 0 byte
//       arr[0] = 0x50;
//       break;
//   }

//   uint8_t i = 0;
//   while ( baro.active() ) { //when baro cs pin is low start doing this spi emulation
//     if (baro.available()) { //while master has not ended transaction
//       Serial.print("Sending: ");
//       Serial.println(arr[i], HEX);

//       baro.pushr(arr[i]); //spi requests have a certain length of bytes in master drivers, we do transfers while master still has stuff to send
//       spiRegData = baro.popr();//store the last thing that was sent (this will either be the read addr we want or just a dont care)
      
//       i++;
      
//       Serial.print("Received: ");
//       Serial.println(spiRegData, HEX);
//     }
//   }
// }


// void setup(void)
// {

//   Wire.begin(BNO055_I2C_ADDR);
//   Wire.onRequest(requestEvent);
//   Wire.onReceive(receiveEvent);
//   //baro.onReceive(spiEvent);

//   //initialize imu data
//   BNO055_ACCEL_DATA_X_LSB = 0b00000000;
//   BNO055_ACCEL_DATA_X_MSB = 0b00000000;
//   BNO055_ACCEL_DATA_Y_LSB = 0b00000000;
//   BNO055_ACCEL_DATA_Y_MSB = 0b00000000;
//   BNO055_ACCEL_DATA_Z_LSB = 0b00000000;
//   BNO055_ACCEL_DATA_Z_MSB = 0b00000000;

//   //initialize baro data
//   PRESS_MSB_23_16 = 0b11111111;
//   PRESS_LSB_15_8 = 0b11111111;
//   PRESS_XLSB_7_0 = 0b11111111;
//   TEMP_MSB_23_16 = 0b00000000;
//   TEMP_LSB_15_8 = 0b00000000;
//   TEMP_XLSB_7_0 = 0b00000000;

//   i2cReadAddr = 0;
//   spiRegAddr = 0;
//   spiRegData = 0;
//   while (!Serial) {;}

//   Serial.println("Setup complete");
// }


// void loop(void)
// {
//   //arbitrary wait 
//   BNO055_ACCEL_DATA_Z_LSB++;
//   BNO055_ACCEL_DATA_Z_MSB++;
//   PRESS_MSB_23_16--;
//   PRESS_LSB_15_8--;
//   PRESS_XLSB_7_0--;
  
//   delay(100);
// }