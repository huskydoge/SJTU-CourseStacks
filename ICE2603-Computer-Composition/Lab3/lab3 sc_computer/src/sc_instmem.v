module sc_instmem (addr,inst,clock,mem_clk,imem_clk);
   input  [31:0] addr;
   input         clock;
   input         mem_clk;
   output [31:0] inst;
   output        imem_clk;
   
   wire          imem_clk;

   assign  imem_clk = clock & ( ~ mem_clk );      
   
// 32*64word irom

lpm_rom_irom irom (
  .addra(addr[7:2]),  // input wire addr[7 : 2] 
  .clka(imem_clk),    // input wire imem_clk
  .douta(inst),  // output wire inst[31 : 0] 
  .ena(1'b1)
);

endmodule 