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
   wire          zero,wmem,wreg,m2reg,aluimm,sext,i_lui,i_sw,shift;
  //pc register unit ,dff32
   dff32 ip (npc,clock,resetn,pc);  // define a D-register for PC


  //immedate data extent unit ,   immext
   immext ImmGen(inst,pcsource,sext,i_lui,i_sw,shift,immediate);// generate ext immediate,
  
  
  //register file,   mux2x32 , regfile
  
  
  

  //control unit ,sc_cu
   sc_cu cu (inst,zero,wmem,wreg,m2reg,aluc,aluimm,pcsource,sext,i_lui,i_sw,shift);


  //alu unit   , mux2x32,alu




  //next pc generate ,   cla32 ,mux4x32


   
  //write back register file,   mux2x32 



   
   endmodule