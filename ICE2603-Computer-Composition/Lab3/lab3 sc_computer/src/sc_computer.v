/////////////////////////////////////////////////////////////
//                                                         //
// School of SEIEE of SJTU                              //
//                                                         //
/////////////////////////////////////////////////////////////

module sc_computer (resetn,clock,mem_clk,pc,inst,memout,imem_clk,dmem_clk);
   
   input resetn,clock,mem_clk;
   output [31:0] pc,inst,memout;
   output        imem_clk,dmem_clk;
   wire   [31:0] data,aluout;
   wire          wmem; // all these "wire"s are used to connect or interface the cpu,dmem,imem and so on.
//sc_cpu ,CPU module.
   sc_cpu cpu(
   .clock(clock),
   .resetn(resetn),
   .inst(inst),
   .mem(memout),
   .pc(pc),
   .wmem(wmem),
   .aluout(aluout),
   .data(data));
   
//  sc_instmem, instruction memory.  
   sc_instmem  imem (
   .addr(pc),
   .inst(inst),
   .clock(clock),
   .mem_clk(mem_clk),
   .imem_clk(imem_clk));
   
//sc_datamem, data memory.      
   sc_datamem  dmem (aluout,data,memout,wmem,clock,mem_clk,dmem_clk ); 

endmodule



