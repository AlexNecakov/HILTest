/**
 * @brief Serial parser to communicate to Simulink controls models
 * 
 * @file SerialSimulink.h
 * @author Alex Necakov
 * @date 2020-01-24
 */

#ifndef SERIALSIMULINK_H
#define SERIALSIMULINK_H

#include <Arduino.h>
#include <driverManager.h>

class SimulinkParser{
    public:
        SimulinkParser(DriverManager);
        void readSerial();
        void writeSerial();
        void masterCmd(uint8_t);
        void serialLoop();

        DriverManager dm;
};

#endif