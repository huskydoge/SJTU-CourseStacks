module immext(inst,pcsource,sext,i_lui,i_sw,shift,out_immediate);
input [31:0] inst;
input sext,i_lui,i_sw,shift;
input [1:0] pcsource;  
output [31:0] out_immediate;

wire e= sext &inst[31];   // positive or negative sign at sext signal
wire [19:0] imm = {20{e}};    // high 20 sign bit
wire [31:0] itype_imm = {imm,inst[31:20]};
wire [31:0] lui_imm =   ;//请补充完整
wire [31:0] sw_imm =    ;//请补充完整
wire [31:0] shift_imm =    ;//请补充完整
wire [31:0] bpc_offset =     ;//请补充完整
wire [31:0] jpc_offset = {{12{e}},inst[19:12],inst[20],inst[30:21],1'b0};

assign out_immediate =  i_lui?lui_imm:         ;//请补充完整


endmodule