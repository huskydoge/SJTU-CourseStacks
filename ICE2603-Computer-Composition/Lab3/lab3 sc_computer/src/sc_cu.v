module sc_cu (inst, z, wmem, wreg,  m2reg, aluc, 
              aluimm, pcsource, sext,i_lui,i_sw,shift);
   input  [31:0] inst;
   input        z;
   output       wreg,m2reg,aluimm,sext,wmem,i_lui,i_sw,shift;
   output [3:0] aluc;
   output [1:0] pcsource;
   wire [6:0] op = inst[6:0];
   wire [2:0] func3 = inst[14:12];
   wire [6:0] func7 = inst[31:25];
   
   wire r_type = (op == 7'b0110011);
   wire i_type = (op == 7'b0010011);
   //R type
   wire i_add = r_type &  (func3 == 3'b000 ) & ~inst[30];           //000，0
   wire i_sub = r_type &  (func3 == 3'b000 )& inst[30];             //000，1
      


   //  please complete the deleted code.
   
   
   wire i_and = r_type & (func3 == 3'b111 );          //111
   wire i_or  =    ;          //110
   wire i_xor =    ;          //100
   wire i_sll =    ;          //001
   wire i_srl = r_type &( func3 == 3'b101 ) & ~inst[30];          //101，0
   wire i_sra =    ;          //101,1

   //I type
   wire i_addi = i_type & (func3 == 3'b000 );          //000
   wire i_andi =   ;          //111
   wire i_ori  =   ;          //110      
   wire i_xori =   ;          //100
   wire i_slli =   ;          //001
   wire i_srli = i_type & (func3 == 3'b101  ) & ~inst[30];          //101，0
   wire i_srai =   ;          //101,1

   wire i_lw   =    ;
   wire i_jalr = (op == 7'b1100111) & (func3 == 3'b000) ;     

   //S type
   wire i_sw   =    ;
   //SB type 
   wire i_beq  =    ;
   wire i_bne  =    ;
   //U type 
   wire i_lui  =  (op == 7'b0110111);
   //UJ type
   wire i_jal  =     ;  
  
   assign pcsource[1] = i_jalr | i_jal;
   assign pcsource[0] = ( i_beq & z ) | (i_bne & ~z) | i_jal ;
   
   assign wreg = i_add | i_sub | i_and | i_or   | i_xor  |
                 i_sll | i_srl | i_sra | i_addi | i_andi |
                 i_ori | i_xori | i_srli | i_slli | i_srai | i_lw | i_jalr | i_lui  | i_jal;
   
 
   assign aluc[3] =   ;
   assign aluc[2] =   ; 
   assign aluc[1] =   ;
   assign aluc[0] =   ;
  
   assign aluimm  =   ;
   assign sext    =   ;
   assign wmem    = i_sw;
   assign m2reg   =     ;
   assign shift   =     ;
   endmodule