module in_port (sw,out);
	input [4:0] sw;
	output [31:0] out;
	assign out = {27'h0,sw};
endmodule

