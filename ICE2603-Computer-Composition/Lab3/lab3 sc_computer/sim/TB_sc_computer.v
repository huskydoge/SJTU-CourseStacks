`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/10/20 15:57:30
// Design Name: 
// Module Name: TB_sc_computer
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


module TB_sc_computer(pc,inst,memout,imem_clk,dmem_clk);

output [31:0] pc,inst,memout;
output imem_clk,dmem_clk;

parameter CYC = 5;
reg clock;
reg mem_clk;
reg resetn;

initial
begin
clock = 1'b0;
mem_clk = 1'b1;
resetn =1'b0;
#(5*CYC) resetn = 1'b0;
#(5*CYC) resetn= 1'b1;
#(400*CYC)
$finish;
end

always #(2*CYC) clock = ~ clock;

always #CYC mem_clk = ~ mem_clk;

 sc_computer computer (resetn,clock,mem_clk,pc,inst,memout,imem_clk,dmem_clk);

endmodule
