`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/10/29 14:57:06
// Design Name: alu_test_top
// Module Name: alu_test_top
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


module alu_test_top(
    input sys_rst_n, //globle reset,active low, 
    input sys_clk_in, //board system clock,100MHz
    input [4:0] sw_pin,//sw_pin4 to sw_pin0
    input [4:0] dip_pin,//dip_pin4 to dip_pin0
    output [7:0] seg_data_0_pin, //output DP1,G1,F1,E1,D1,C1,B1,A1, left
    output [7:0] seg_data_1_pin, //output DP0,G0,F0,E0,D0,C0,B0,A0,  right
    output [7:0] seg_cs_pin, //DN1_K4,DN1_K3,DN1_K2,DN1_K0,DN0_K4,DN0_K3,DN0_K2,DN0_K1 left to right
    output [0:15] led_pin
     );

wire clock_1s,zero;
wire [31:0] aluout;

wire[31:0] alub = {27'b0,sw_pin[4:0]};
wire [3:0] aluc = dip_pin[3:0]; 



//例化alu





//例化display
display display(
  .clk(sys_clk_in),
  .reset(sys_rst_n),
  .s(aluout),
  .seg0(seg_data_0_pin),
  .seg1(seg_data_1_pin),
  .ans(seg_cs_pin)
    );


endmodule
