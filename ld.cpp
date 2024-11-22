4 bit ADDER


module adder_four_bit(
output [3:0]sum,
output cout,
input [3:0]a,b);
wire c1, c2, c3, c4;
full_3 ad0( .a(a[0]), .b(b[0]),.cin(0), .s(sum[0]), .cout(c1));
full_3 ad1( .a(a[1]), .b(b[1]),.cin(c1), .s(sum[1]), .cout(c2));
full_3 ad2( .a(a[2]), .b(b[2]),.cin(c2), .s(sum[2]), .cout(c3));
full_3 ad3( .a(a[3]), .b(b[3]),.cin(c3), .s(sum[3]), .cout(c4));
assign cout= c4;
endmodule
module full_3(a,b,cin,s,cout);
input a,b,cin;
output s, cout;
assign s=a^b^cin;
assign cout = (a&b) | (b&cin) | (cin&a);
endmodule


BCD
module Bcd_excess3(b,e);
input [3:0] b;
output [3:0] e;
assign e[3]=b[3]|b[2]&b[1]|b[2]&b[0];
assign e[2]=~b[2]&b[1]|~b[2]&b[0]|b[2]&~b[1]&~b[0];
assign e[1]=b[1]&b[0]|~b[1]&~b[0];
assign e[0]=~b[0];
endmodule



BINARY TO GRAY

module Binary_to_Gray(
 input [3:0] b,
 output [3:0] g
 );
assign g[0]=b[1]^b[0];
assign g[1]=b[2]^b[1];
assign g[2]=b[3]^b[2];
assign g[3]=b[3];
endmodule


HDL

module decoder24 (en,a,b,y);
input en,a,b;
output reg [3:0]y;
 always @(en,a,b)
 begin
 if(en==0)
 begin
 if(a==1'b0 & b==1'b0) y=4'b1110;
 else if(a==1'b0 & b==1'b1) y=4'b1101;
 else if(a==1'b1 & b==1'b0) y=4'b1011;
 else if(a==1 & b==1) y=4'b0111;
 else y=4'bxxxx;
 end
 else
 y=4'b1111;
 end
endmodule


ALU

module ALU(x,y,sel,z);
input [7:0]x,y;
output reg [15:0]z;
input [2:0]sel;
parameter ADD=3'b000;
parameter SUB=3'b001;
parameter MUL=3'b010;
parameter DIV=3'b011;
parameter AND=3'b100;
parameter OR=3'b101;
parameter NOT1 =3'b110;
parameter NOT2 =3'b111;
always@(*)
case(sel)
ADD: z=x+y;
SUB: z=x-y;
MUL: z=x*y;
DIV: z=x/y;
AND: z=x&y;
OR: z=x|y;
NOT1: z=!x;
NOT2: z=!y;
endcase
endmodule 



PISO AND SIPO

PISO Program
module Shiftregister_PISO(Clk, Parallel_In,load, Serial_Out);
input Clk,load;
input [3:0]Parallel_In;
output reg Serial_Out;
reg [3:0]tmp;
always @(posedge Clk)
begin
if(load)
tmp<=Parallel_In;
else
begin
Serial_Out<=tmp[3];
tmp<={tmp[2:0],1'b0};
end
end
endmodule

module sipo_shift_register_design(input clk,b,output[3:0]q);
d_ff dut1(.clk(clk),.d(b),.q(q[3]),.rst());
d_ff dut2(.clk(clk),.d(q[3]),.q(q[2]),.rst());
d_ff dut3(.clk(clk),.d(q[2]),.q(q[1]),.rst());
d_ff dut4(.clk(clk),.d(q[1]),.q(q[0]),.rst());
endmodule
// d flip flop
module d_ff (
 input clk,
 input d,
 input rst,
 output reg q);
 always @(posedge clk)
 begin
 if (rst)
 q <= 1'b0;
 else
 q <= d;
 end
endmodule





MODULUS COUNTER 

module ALU(x,y,sel,z);
input [7:0]x,y;
output reg [15:0]z;
input [2:0]sel;
parameter ADD=3'b000;
parameter SUB=3'b001;
parameter MUL=3'b010;
parameter DIV=3'b011;
parameter AND=3'b100;
parameter OR=3'b101;
parameter NOT1 =3'b110;
parameter NOT2 =3'b111;
always@(*)
case(sel)
ADD: z=x+y;
SUB: z=x-y;
MUL: z=x*y;
DIV: z=x/y;
AND: z=x&y;
OR: z=x|y;
NOT1: z=!x;
NOT2: z=!y;
endcase
endmodule 
