function teensyWrite()%write to teensy over serial bus

    write(teensy,0,"uint8");
    write(teensy,0,"uint8");
    write(teensy,0,"uint8");
end
