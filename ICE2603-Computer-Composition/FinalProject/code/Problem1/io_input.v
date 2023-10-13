module io_input(
	addr,io_clk,io_read_data,in_port0,in_port1,in_port2
);
	input 	[31:0] 	addr;
	input 			io_clk;
	input 	[31:0] 	in_port0,in_port1,in_port2;
	output 	[31:0] 	io_read_data;
	
	reg 	[31:0] 	in_reg0;
	reg 	[31:0] 	in_reg1;
	reg     [31:0]  in_reg2;
	
	io_input_mux io_imput_mux2x32(in_reg0,in_reg1,in_reg2,addr[7:2],io_read_data);
	
	always @(posedge io_clk)
	begin
		in_reg0 <= in_port0;
		in_reg1 <= in_port1;
		in_reg2 <= in_port2;
	end
endmodule

module io_input_mux(a0,a1,a2,sel_addr,y);
	input 	[31:0]	a0,a1,a2;
	input 	[ 5:0]	sel_addr;
	output 	[31:0]	y;
	reg 	[31:0] 	y;
	always @ *
		case (sel_addr)
			6'b100000: y = a0;  // inport0 byte address ox80
			6'b100001: y = a1;  // inport1 byte address ox84
			6'b100010: y = a2;  // inport2 byte address ox88
			default: y = 32'h0;
		endcase
endmodule