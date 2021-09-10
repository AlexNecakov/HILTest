set_property SRC_FILE_INFO {cfile:C:/Users/alexn/OneDrive/Documents/Projects/HILTest/Rotom/HILConstraints.xdc rfile:../../../HILConstraints.xdc id:1} [current_design]
set_property src_info {type:XDC file:1 line:42 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN M3    IOSTANDARD LVCMOS33 } [get_ports { SDIMaster  }]; #IO_L8N_T1_AD14N_35 Sch=pio[01]
set_property src_info {type:XDC file:1 line:43 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN L3    IOSTANDARD LVCMOS33 } [get_ports { SDOMaster  }]; #IO_L8P_T1_AD14P_35 Sch=pio[02]
set_property src_info {type:XDC file:1 line:44 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN A16   IOSTANDARD LVCMOS33 } [get_ports { SDISlave  }]; #IO_L12P_T1_MRCC_16 Sch=pio[03]
set_property src_info {type:XDC file:1 line:45 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN K3    IOSTANDARD LVCMOS33 } [get_ports { SDOSlave  }]; #IO_L7N_T1_AD6N_35 Sch=pio[04]
set_property src_info {type:XDC file:1 line:46 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN C15   IOSTANDARD LVCMOS33 } [get_ports { SCL  }]; #IO_L11P_T1_SRCC_16 Sch=pio[05]
set_property src_info {type:XDC file:1 line:79 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN U2    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[6] }]; #IO_L9N_T1_DQS_34 Sch=pio[42]
set_property src_info {type:XDC file:1 line:80 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN W6    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[5] }]; #IO_L13N_T2_MRCC_34 Sch=pio[43]
set_property src_info {type:XDC file:1 line:81 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN U3    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[4] }]; #IO_L9P_T1_DQS_34 Sch=pio[44]
set_property src_info {type:XDC file:1 line:82 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN U7    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[3] }]; #IO_L19P_T3_34 Sch=pio[45]
set_property src_info {type:XDC file:1 line:83 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN W7    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[2] }]; #IO_L13P_T2_MRCC_34 Sch=pio[46]
set_property src_info {type:XDC file:1 line:84 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN U8    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[1] }]; #IO_L14P_T2_SRCC_34 Sch=pio[47]
set_property src_info {type:XDC file:1 line:85 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict { PACKAGE_PIN V8    IOSTANDARD LVCMOS33 } [get_ports { slaveAddr[0] }]; #IO_L14N_T2_SRCC_34 Sch=pio[48]
set_property src_info {type:XDC file:1 line:133 export:INPUT save:INPUT read:READ} [current_design]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets SDIMaster_IBUF]