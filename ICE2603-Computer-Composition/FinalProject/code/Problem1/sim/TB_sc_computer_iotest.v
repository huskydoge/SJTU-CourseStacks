`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/03 16:11:01
// Design Name: 
// Module Name: TB_sc_computer_iotest
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////



module TB_sc_computer_iotest(
output [7:0]   seg_cs_pin,
   output [0:7] seg_data_0_pin,seg_data_1_pin );

 wire [15:0] led_pin;
   
sc_cpu_iotest sc_computer_iotest_instance(
    sys_rst_n,
    sys_clk_in,
    sw_pin,//SW9,SW8,SW7,SW6,SW5,
    dip_pin,//SW4,SW3,SW2,SW1,SW0,
    seg_data_0_pin, //output A0,B0,C0,D0,E0,F0,G0,DP0,
    seg_data_1_pin,  //output A1,B1,C1,D1,E1,F1,G1,DP1,
    seg_cs_pin,
    led_pin
   ); 
  
parameter CYC = 5;
reg sys_clk_in;
//reg mem_clk;
reg sys_rst_n;
reg [4:0]  sw_pin,dip_pin;

initial
begin

 sw_pin = 5'b0;
 dip_pin = 5'b0;
 
sys_clk_in = 1'b0;
//mem_clk = 1'b1;
sys_rst_n =1'b0;
#(5*CYC) sys_rst_n = 1'b0;
#(5*CYC) sys_rst_n= 1'b1;

#(5*CYC) sw_pin = 5'b00001;
dip_pin = 5'b00010;

#(230*CYC) sw_pin = 5'b00010;
dip_pin = 5'b00011;

 #(200*CYC) sw_pin = 5'b00011;
dip_pin = 5'b00100;

#(1000*CYC)

$finish;
end

always #(2*CYC) sys_clk_in = ~ sys_clk_in;

//always #CYC mem_clk = ~ mem_clk;
      
endmodule

