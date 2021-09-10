`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/20/2019 06:20:37 PM
// Design Name: Rotom Testbench
// Module Name: tb_i2cAddrSwitch
// Project Name: HIL
// Target Devices: 
// Tool Versions: Vivado 2019.2
// Description: testbench for i2cAddrSwitch module
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb_i2cAddrSwitch(
    
    );
    reg SDIMaster, SDISlave;
    reg SCL;
    wire [3:0] state;
    wire SDOMaster, SDOSlave;
    wire [6:0] slaveAddr;
    
    i2cAddrSwitch test(SDIMaster, SDISlave, SCL, state[3:0], SDOMaster, SDOSlave, slaveAddr[6:0]);
    
    initial begin//test a wire.write()
        SCL = 0;
        SDIMaster = 0;
        SDISlave = 0;
        
        #10 SCL = 1;//test start
        #10 SCL = 0;
        #10 SCL = 1;
        #10 SCL = 0;
        
        #10 SCL = 1;
        #5 SDIMaster = 1;//start bit
        SDISlave = 1;//see if this messes anything up
        #5 SCL = 0;
        
        SDIMaster = 1;//start slave addr
        #10 SCL = 1;
        #10 SCL = 0;
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;//end slave addr
        
        SDIMaster = 0;//start rw bit
        #10 SCL = 1;
        #10 SCL = 0;//end rw bit
        
        SDISlave = 0;//nack bit to test ack loop
        #10 SCL = 1;
        #10 SCL = 0;
        SDISlave = 1;//actual ack bit
        SDIMaster = 1;
        #10 SCL = 1;
        #10 SCL = 0;
        
        #10 SCL = 1;//test stop bit
        #5 SDIMaster = 0;
        #5 SCL = 0;
        
        #10 SCL = 1;//idle test
        #10 SCL = 0;
        #10 SCL = 1;
        #10 SCL = 0;
        
    end
    
endmodule
