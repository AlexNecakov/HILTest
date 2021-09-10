/**
 * @brief Test main for slave
 * 
 * @file testSlave.cpp
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

// #include <Wire.h>

// void receiveEvent(int);

// void setup(){
//   Wire.begin(4);
//   Wire.onReceive(receiveEvent);

//   Serial.begin(9600); //for testing
// }

// uint8_t x = 0x70;

// void loop(){
//   Wire.beginTransmission(4); //change as needed, check with slave
//   Wire.write(x);
//   Wire.endTransmission();

// }

// void receiveEvent(int num){
//   while (Wire.available()){
//     double val = Wire.read();//read as double
//     Serial.print(val);
//   }
// }
