module sc_datamem (resetn,addr,datain,dataout,we,clock,dmem_clock,	
out_port0,out_port1,out_port2,in_port0,in_port1);

   input  [31:0]  addr;
   input  [31:0]  datain;
   input [31:0] in_port0,in_port1;
   input          we, clock,dmem_clock,resetn;
   output [31:0]  dataout;
   output [31:0] out_port0,out_port1,out_port2;
   wire [31:0] io_read_data;
   
   wire write_enable; 
   wire [31:0] dataout;
   wire [31:0] mem_dataout;
   wire write_data_enable;
   wire write_io_enable;
   wire [31:0] in_port0,in_port1,out_port0,out_port1,out_port2;

	//control signal for write dram or IO space
   assign         write_enable = we & ~clock; 
  
//Here: set 0x80~0xff as IO space byte address, 0~0x7f as data_mem space byte address. addr[7] can be used to seperate them
//That means I/O space is in word address addr[7:2]=100000~111111;data_mem space is in 000000-011111
//Think: if set 0xd0000000 ~0xdfffffff as IO byte address,0xc0000000~0xcfffffff as data_mem space,how to decode
	assign write_data_enable = write_enable & (~addr[7]);
	assign write_io_enable = write_enable & addr[7];

 //mux of mem_dataout and io_read_data
	mux2x32 io_data_mux(mem_dataout,io_read_data,addr[7],dataout);
  
     
//  dram 
lpm_ram_dq_dram dram (
  .clka(dmem_clock),    // input wire clka
  .wea(write_data_enable),      // input wire [0 : 0] wea
  .addra(addr[6:2]),  // input wire [4 : 0] addra
  .dina(datain),    // input wire [31 : 0] dina
  .ena(1'b1), 
  .douta(mem_dataout)  // output wire [31 : 0] douta
);

//IO output , io_output ,add here
io_output io_output_reg (
    .resetn(resetn),
    .addr(addr),
    .datain(datain),
    .io_clk(dmem_clock),
    .write_io_enable(write_io_enable),
    .out_port0(out_port0),
    .out_port1(out_port1),
    .out_port2(out_port2)
);


//IOinput ,	io_input ,add here
io_input io_input_reg (
    .addr(addr),
    .io_clk(dmem_clock),
    .io_read_data(io_read_data),
    .in_port0(in_port0),
    .in_port1(in_port1)
);


endmodule