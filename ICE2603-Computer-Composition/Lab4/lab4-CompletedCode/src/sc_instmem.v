module sc_instmem (addr,inst,clock,imem_clock);
   input  [31:0] addr;
   input         clock;
   input         imem_clock;
   output [31:0] inst;


//   assign  imem_clk = clock & ( ~ mem_clk );      
   
//   lpm_rom_irom irom (addr[7:2],imem_clk,inst); 
   

lpm_rom_irom irom (
  .clka(imem_clock),    // input wire imem_clk
  .addra(addr[7:2]),  // input wire addr[7 : 2] 
  .douta(inst),  // output wire inst[31 : 0] 
  .ena(1'b1)
);

endmodule 