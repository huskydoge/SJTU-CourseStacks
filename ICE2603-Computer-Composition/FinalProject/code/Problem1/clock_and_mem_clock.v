module clock_and_mem_clock(
	sys_clk_in,
	clock_out,imem_clock,dmem_clock
);

	input sys_clk_in;
	output reg clock_out; 
	output imem_clock,dmem_clock;
	

	 assign imem_clock = clock_out & ~sys_clk_in;
	 assign dmem_clock = ~clock_out & ~sys_clk_in;
	 
	initial
	begin
		clock_out <= 0;
	end
	
	always @ (posedge sys_clk_in)
	begin
		clock_out <= ~clock_out;
	end
	
endmodule
	
	