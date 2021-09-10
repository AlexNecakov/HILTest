function teensyInit()
    teensy = serialport("COM6",9600);
    configureTerminator(teensy, "CR/LF");
    
    write(teensy,255,"uint8");
    write(teensy,1,"uint8");
    write(teensy,1,"uint8");
    
    write(teensy,255,"uint8");
    write(teensy,1,"uint8");
    write(teensy,1,"uint8");
    
    write(teensy,255,"uint8");
    write(teensy,1,"uint8");
    write(teensy,1,"uint8");
end
