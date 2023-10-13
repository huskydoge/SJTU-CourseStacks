module sc_cu (inst, z, wmem, wreg,  m2reg, aluc, 
              aluimm, pcsource, sext,i_lui,i_sw,shift,lz);
   input  [31:0] inst;
   input        z;
   input        lz; //  blt 
   output       wreg,m2reg,aluimm,sext,wmem,i_lui,i_sw,shift;
   output [3:0] aluc;
   output [1:0] pcsource;
   wire [6:0] op = inst[6:0];
   wire [2:0] func3 = inst[14:12];
   wire [6:0] func7 = inst[31:25];
   
   wire r_type = (op == 7'b0110011);
   wire i_type = (op == 7'b0010011);
   //R type
   wire i_add = r_type &  (func3 == 3'b000 ) & ~inst[30];           //000ï¼?0
   wire i_sub = r_type &  (func3 == 3'b000 )& inst[30];             //000ï¼?1
   
   
   // hamd instruction
   wire i_hamd = r_type & (func3 == 3'b111) & (func7 == 7'b0100000);

   //  please complete the deleted code.
   wire i_and = r_type & (func3 == 3'b111 );          //111
   wire i_or  = r_type & (func3 == 3'b110 );          //110
   wire i_xor = r_type & (func3 == 3'b100 );          //100
   wire i_sll = r_type & (func3 == 3'b001 );//001
   wire i_srl = r_type &( func3 == 3'b101 ) & ~inst[30];          //101ï¼?0
   wire i_sra = r_type & (func3 == 3'b101 ) & inst[30];          //101,1

   //I type
   wire i_addi = i_type & (func3 == 3'b000 );          //000
   wire i_andi = i_type & (func3 == 3'b111 );          //111
   wire i_ori  = i_type & (func3 == 3'b110 );          //110      
   wire i_xori = i_type & (func3 == 3'b100 );          //100
   wire i_slli = i_type & (func3 == 3'b001 );          //001
   wire i_srli = i_type & (func3 == 3'b101 ) & ~inst[30];          //101ï¼?0
   wire i_srai = i_type & (func3 == 3'b101 ) & inst[30];          //101,1

   wire i_lw   = (op == 7'b0000011) & (func3 == 3'b010);
   wire i_jalr = (op == 7'b1100111) & (func3 == 3'b000);     

   //S type
   wire i_sw   = (op == 7'b0100011) & (func3 == 3'b010);
   //SB type 
   wire i_beq  =  (op == 7'b1100011) & (func3 == 3'b000)  ;
   wire i_bne  =  (op == 7'b1100011) & (func3 == 3'b001)  ;
   wire i_blt =   (op == 7'b1100011) & (func3 == 3'b100)  ; // new inst
   //U type 
   wire i_lui  =  (op == 7'b0110111);
   //UJ type
   wire i_jal  =  (op == 7'b1101111);  
  
   assign pcsource[1] = i_jalr | i_jal;
   assign pcsource[0] = ( i_beq & z ) | (i_bne & ~z) | (i_blt & lz) | i_jal ;
   
   assign wreg = i_add | i_sub | i_and | i_or   | i_xor  |
                 i_sll | i_srl | i_sra | i_addi | i_andi |
                 i_ori | i_xori | i_srli | i_slli | i_srai | i_lw | i_jalr | i_lui  | i_jal | i_hamd;
   
 
   assign aluc[3] = i_sub | i_srai | i_beq | i_bne | i_hamd | i_blt;
   assign aluc[2] = i_and | i_or | i_xor | i_srl | i_sra | i_andi | i_ori| i_xori | i_srli | i_srai | i_hamd; 
   assign aluc[1] = i_and | i_or | i_andi | i_ori |i_lui | i_hamd;
   assign aluc[0] = i_and | i_sll | i_srl | i_sra | i_andi| i_slli | i_srli | i_srai | i_hamd;
  
   assign aluimm  = i_addi | i_andi | i_ori | i_xori| i_slli| i_srli | i_srai | i_lw | i_jalr |i_sw |i_lui ;
   // Here srai is included simply because its inst[31] has been considered
   assign sext    = i_addi | i_lw | i_jalr | i_sw | i_beq | i_bne | i_blt | i_jal | i_andi |i_ori |i_xori |i_slli |i_srli |i_srai; //add itype
   assign wmem    = i_sw;
   assign m2reg   = i_lw;
   assign shift   = i_sll | i_srl | i_sra | i_slli | i_srai| i_srli;
   endmodule