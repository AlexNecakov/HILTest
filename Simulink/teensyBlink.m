function teensyBlink()%test file for simulink comms
    teensy = serialport("COM6",9600);
    configureTerminator(teensy, "CR/LF");
    
    write(teensy,0,"uint8");
    write(teensy,0,"uint8");
    write(teensy,0,"uint8");
end
