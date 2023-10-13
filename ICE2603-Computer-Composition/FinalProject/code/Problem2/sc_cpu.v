module sc_cpu (clock,resetn,inst,mem,pc,wmem,aluout,data);
   input [31:0] inst,mem;
   input clock,resetn;
   output [31:0] pc,aluout,data;
   output wmem;
  
   wire [31:0]   p4,branchpc,jalrpc,npc,immediate;
   wire [31:0]   ra,rb,regf_din;//regfile output a,b, input data
   wire [31:0]   alua,alub,alu_mem;
   wire [3:0]    aluc;
   wire [1:0]    pcsource;// 00 normal; 01 beq,bne;10 jalr;11 jal
   wire          zero,less_zero,wmem,wreg,m2reg,aluimm,sext,i_lui,i_sw,shift;
  //pc register unit ,dff32
   dff32 ip (npc,clock,resetn,pc);  // define a D-register for PC
    assign data = rb; // output 

  //immedate data extent unit ,   immext
   immext ImmGen(inst,pcsource,sext,i_lui,i_sw,shift,immediate);// generate ext immediate,
  
  
  //register file,   mux2x32 , regfile
    regfile rf (
      .rna(inst[19:15]),
      .rnb(inst[24:20]),
      .d(regf_din),
      .wn(inst[11:7]),
      .we(wreg),
      .clk(clock),
      .clrn(resetn),
      .qa(ra),
      .qb(rb)
   );
    
  //control unit ,sc_cu
   sc_cu cu (inst,zero,wmem,wreg,m2reg,aluc,aluimm,pcsource,sext,i_lui,i_sw,shift,less_zero);


  //alu unit   , mux2x32, alu
    assign alua = ra;
    mux2x32 alu_b(rb, immediate, aluimm,alub);
    alu al_unit(alua, alub, aluc, aluout, zero,less_zero);
    mux2x32 link(aluout, mem, m2reg, alu_mem);


  //next pc generate ,   cla32 ,mux4x32
    cla32 pcplus4(pc, 32'h4, 32'b0, p4);
    cla32 branch_adr (
        .pc(pc),
        .x1(immediate),
        .x2(32'b0),
        .p4(branchpc)
    );
    cla32 genjalrpc (ra,immediate,32'b0,jalrpc);
    mux4x32 nextpc(p4,branchpc, jalrpc, branchpc, pcsource[1:0], npc);

   
  //write back register file,   mux2x32 

    mux2x32 result(alu_mem, p4, pcsource[1], regf_din);
    


   
   endmodule