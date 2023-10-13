module alu (a,b,aluc,s,z,lz);
   input [31:0] a,b;
   input [3:0] aluc;
   output [31:0] s;
   output        z;
   output        lz;
   
   /*
   wire z;
   wire [31:0] s;
   assign  s = (aluc == 4'b0000)? a + b: 
               (aluc == 4'b1000)? a - b:
               (aluc == 4'b0111)? a & b:
               (aluc == 4'b0110)? a | b:
               (aluc == 4'b0100)? a ^ b:
               (aluc == 4'b0010)? b    :
               (aluc == 4'b0001)? a << b:
               (aluc == 4'b0101)? a >> b:
               (aluc == 4'b1101)? a >>> b:
               0;
  assign z = (s == 0); 
 */ 
// /* 
   reg [31:0] s;
   integer tmp = 32'hffffffff;
   integer i;
   reg [31:0] x;
   reg        z;
   reg       lz;
   always @ (a or b or aluc) 
      begin                                 
             casex (aluc)  //   
               4'b0000: s = a + b;             //0000 ADD
               4'b1000: s = a - b;             //1000 SUB
               4'b0111: s = a & b;            //0111 AND
               4'b0110: s = a | b;              //0110 OR
               4'b0100: s = a ^ b;             //0100 XOR
               4'b0010: s = b;                 //0010 LUI:{lui_imm ,12'b0}             
               4'b0001: s = a << b;            //0001 SLL: rd <- (rs1 << rs2)
               4'b0101: s = a >> b;            //0101 SRL: rd <- (rs1 >>rs2) (logical)
               4'b1111:  
                    begin
                    s = 0;
                    x = a ^ b;
//                    while(x!=32'b0) begin
//                        if((x & 32'b1) == 32'b1)
//                            begin
//                                s = s + 1;
//                            end
//                            x = x >> 1;
//                        end
//                     end
                    for (i = 1;i <= 32; i = i + 1) begin
                        if (x & 8'b1) 
                            begin
                                s = s + 1;
                            end
                         x = x >> 1;
                         end
                     end
                    
               4'b1101: // initial tmp:  32'hffffffff;
                    begin
                    if (a[31] == 0) begin
                        s = a >> b;
                    end
                    else begin 
                        s = a >> b;
                        tmp  = tmp << (32 - b);
                        s = s | tmp;
                        tmp = 32'hffffffff;
                    end
                    end       //1101 SRA: rd <- (rs1 >> rs2) (arithmetic)
               default: s = 0;
             endcase 
             if (s == 0 )  z = 1;
             else z = 0;  
             if (a < b) lz = 1;
             else lz = 0;       
      end     
//      */
       
endmodule 