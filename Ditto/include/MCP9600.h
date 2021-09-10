/**
 * @brief Slave driver for MCP9600 Thermocouple chip
 * 
 * @file MCP9600.h
 * @author Ryuichi Ohhata
 * @date 2020-2-23
 */

#ifndef MCP9600_H
#define MCP9600_H

#include <Arduino.h>
#include <Wire.h>
#include <SlaveDriver.h>

#define MCP9600_HOTJUNCTION     0x00 ///< Hot junction temperature T_H
#define MCP9600_JUNCTIONDELTA   0x01 ///< Hot/Cold junction delta
#define MCP9600_COLDJUNCTION    0x02 ///< Hot junction temperature T_C
#define MCP9600_RAWDATAADC      0x03 ///< The 'raw' uV reading
#define MCP9600_STATUS          0x04 ///< Current device status
#define MCP9600_DEVICEID        0x20 ///< Device ID/Revision


class MCP9600 : public SlaveDriver {
    public:
        MCP9600();
        void passData(uint8_t);

    private:
        uint8_t HOT_TEMP;
        uint8_t HOT_COLD_DELTA;
        uint8_t COLD_TEMP;
        uint8_t RAW;
        uint8_t STATUS;
        uint8_t ID;
        uint8_t RegAddr;
};

#endif