/**
 * @brief Module to switch direction of bidirectional pins (SDA)
 * 
 * @file inoutDirector.v
 * @author Alex Necakov
 * @date 2019-11-20
 */


module inoutDirector(
    inout pin1, pin2    
);

    assign pin1 = 1'bz;
    assign pin2 = pin1;
    
endmodule
