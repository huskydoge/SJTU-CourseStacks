module sc_datamem (addr,datain,dataout,we,clock,mem_clk,dmem_clk);
 
   input  [31:0]  addr;
   input  [31:0]  datain;
   
   input          we, clock,mem_clk;
   output [31:0]  dataout;
   output         dmem_clk;
   
   wire           dmem_clk;    
   wire           write_enable; 
   assign         write_enable = we & ~clock; 
   
   assign         dmem_clk = ~mem_clk & (~clock) ; 
   
//32X32word dataram

lpm_ram_dq_dram dram (
  .clka(dmem_clk),    // input wire clka
  .wea(write_enable),      // input wire [0 : 0] wea
  .addra(addr[6:2]),  // input wire [4 : 0] addra
  .dina(datain),    // input wire [31 : 0] dina
  .ena(1'b1),
  .douta(dataout)  // output wire [31 : 0] douta
);

endmodule 