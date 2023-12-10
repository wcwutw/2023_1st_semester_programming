// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

//if key pressed(RAM[24576]==1) fill(16384, 24575, -1)
//else fill(16384, 24575, 0)

@i
M=0

(LOOP)
@24576
D=M
@FILLBLACK
D;JNE
@FILLWHITE
D;JEQ
0;JMP

(FILLBLACK)
@i
D=M
@8192
D=D-A
@LOOP
D;JGE
@i
D=M
@16384
A=A+D
M=-1
@i
M=M+1
@LOOP
0;JMP


(FILLWHITE)
@i
D=M
@LOOP
D;JLT
@i
D=M
@16384
A=A+D
M=0
@i
M=M-1
@LOOP
0;JMP

