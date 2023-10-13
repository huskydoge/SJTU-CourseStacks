module io_output(resetn,
	addr,datain,write_io_enable,io_clk,out_port0,out_port1,out_port2 
);
	input 	[31:0] 	addr,datain;
	input 			write_io_enable,io_clk,resetn;
	output 	[31:0]	out_port0,out_port1,out_port2;
	
	reg [31:0]	out_port0;
	reg	[31:0]	out_port1;
	reg	[31:0]	out_port2;
	
	always @ (posedge io_clk or negedge resetn)
	begin
		if (resetn == 0)
		begin
		out_port0 = 0;out_port1 = 0;out_port2 = 0;
		end
		else if (write_io_enable == 1)
			case (addr[7:2])
				6'b100000: out_port0 = datain; //outport0 byte address ox80 same as in_port0
				6'b100001: out_port1 = datain; //outport1 byte address ox84 , you can change the address
				6'b100010: out_port2 = datain; //outport2 byte address ox88  ,as output
			endcase
	end
endmodule