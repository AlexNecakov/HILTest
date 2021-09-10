`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Alex Necakov
// 
// Create Date: 11/04/2019 06:20:37 PM
// Design Name: Rotom
// Module Name: tb_i2cAddrSwitch
// Project Name: HIL
// Target Devices: CMod A7
// Tool Versions: Vivado 2019.2
// Description: Module to transform I2C Slave addresses for HIL testing
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////



module i2cAddrSwitch(
    input SDIMaster, SDISlave,
    input SCL,
    output reg SDOMaster, SDOSlave,
    output reg [6:0] slaveAddr//digital output of real Slave address
    );

    parameter [6:0] HILSlaveAddr = 7'b0001000;     //address to output as in reverse order
    parameter [3:0]
        BUSIDLE = 4'b0,                 //initial state
        GETSLAVEADDR = 4'b0001,         //getting 7-bit slave address
        GETRWBIT = 4'b0010,             //getting r/w bit
        ACKADDR = 4'b0011,              //send first ack
        GETREGADDR = 4'b0100,           //get reg to start at
        ACKREGADDR = 4'b0101,           //ack that transmission
        GETWRITE = 4'b0110,             //get data to write to reg
        SENDREGDATA = 4'b0111,          //send data for a read
        ACKREAD = 4'b1000,              //master acks or nacks the read
        PRESTOP = 4'b1001;              //master nacked the read, waiting for stop bit


    reg readwrite; //1 is MISO, 0 is MOSI
    reg commType; //1 is wire.read(), 0 is wire.write()
    
    reg [2:0] frameBitCounter; //keep track of where we are in a data frame (8-bits)
    (* KEEP = "TRUE" *) reg [3:0] state; 

    wire sdiWire;
    assign sdiWire = SDIMaster;

    reg start;//check start bit
    always @(negedge sdiWire)
        if(readwrite == 1'b0)//only in mosi mode
            start = SCL;
    
    reg stop;//check stop bit
    always @(posedge sdiWire)
        if(readwrite == 1'b0)
            stop = SCL;


    reg incycle;//check both start and stop
    always @(posedge start or posedge stop)
        if (start) begin
                incycle = 1'b1;
           end
        else if (stop) begin
                incycle = 1'b0;	
           end


    always @ (posedge SCL, negedge incycle) begin
        if(incycle == 1'b1) begin
            case(state)
                BUSIDLE: begin//before i2c has been opened
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave = SDIMaster;
                    slaveAddr = 7'b0;
                    frameBitCounter = 3'b0;
                    state = (incycle)?GETSLAVEADDR:BUSIDLE;
                end
                
                GETSLAVEADDR: begin//master sending 7bit slave addr to slave
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave  = HILSlaveAddr[frameBitCounter];
                    slaveAddr[frameBitCounter] = SDIMaster;
    
                    if(frameBitCounter == 3'b110) begin
                        frameBitCounter = 3'b0;
                        state = GETRWBIT;
                    end else begin
                        frameBitCounter = frameBitCounter + 1'b1;
                    end
                end
                
                GETRWBIT: begin//master sends one more bit to determine rw
                    readwrite = 1'b0;
                    SDOSlave = 1'bz;
                    SDOMaster = SDISlave;
                    commType = SDISlave;
                    state = ACKADDR;
                end
                
                ACKADDR: begin//bus "idle" till ack bit sent from slave
                    readwrite = 1'b1;
                    SDOSlave = 1'bz;
                    SDOMaster = SDISlave;
                    if(SDISlave) begin
                        state = GETREGADDR;
                    end
                end
                
                GETREGADDR: begin//master sends 8bit reg addr to slave
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave  = SDIMaster;
                    if(frameBitCounter == 3'b111) begin
                        frameBitCounter = 3'b0;
                        state = ACKREGADDR;
                    end else begin
                        frameBitCounter = frameBitCounter + 1'b1;
                    end
                end
                
                ACKREGADDR: begin//another ack bit has to be sent after reg addr or write command
                    readwrite = 1'b1;
                    SDOSlave = 1'bz;
                    SDOMaster = SDISlave;
                    if(SDISlave) begin
                        if(commType == 1'b0) begin
                            state = GETWRITE;
                        end else begin
                            state = SENDREGDATA;
                        end
                    end
                end
                
                GETWRITE: begin//if master is doing a write, it writes an 8bit piece of data
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave  = SDIMaster;
                    if(frameBitCounter == 3'b111) begin
                        frameBitCounter = 3'b0;
                        state = ACKREGADDR;
                    end else begin
                        frameBitCounter = frameBitCounter + 1'b1;
                    end
                end
                
                SENDREGDATA: begin//when master is doing a read, slave sends 8bits to master
                    readwrite = 1'b1;
                    SDOSlave = 1'bz;
                    SDOMaster = SDISlave;
                    if(frameBitCounter == 3'b111) begin
                        frameBitCounter = 3'b0;
                        state = ACKREAD;
                    end else begin
                        frameBitCounter = frameBitCounter + 1'b1;
                    end
                end
                
                ACKREAD: begin//master does an ack bit after a read is completed
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave = SDIMaster;
                    if(SDIMaster) begin
                       state = SENDREGDATA;
                    end else begin
                        state = PRESTOP;
                    end
                end
                
                PRESTOP: begin//if master nacked a read, bus is technically idle, and ready to turn off
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave  = SDIMaster;
                end
                
                default: begin
                    readwrite = 1'b0;
                    SDOMaster = 1'bz;
                    SDOSlave = SDIMaster;
                    slaveAddr = 7'b0;
                    state = BUSIDLE;
                end
            
            endcase
        end
        
        else begin //stop bit actually sent
            readwrite = 1'b0;
            SDOMaster = 1'bz;
            SDOSlave = SDIMaster;
            slaveAddr = 7'b0;
            state = BUSIDLE;
        end
    end


endmodule