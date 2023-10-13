module out_port_hex2dec(in,out1,out0);
	input [31:0] in;
	output [3:0] out1,out0;
	
	reg [3:0] num1,num0;

	assign out1 = num1;
	assign out0 = num0;
	always @ (in)
	begin
		num1 = ( in / 10 ) % 10;
		num0 = in % 10;
	end
	
endmodule