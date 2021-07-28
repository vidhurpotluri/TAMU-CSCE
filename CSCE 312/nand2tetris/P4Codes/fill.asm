// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.
// Loop if a key is pressed

(START)
	@SCREEN
	D = A
	@var
	M = D // RAM[var] holds the address of a
	@a // Variable whose memory needs to be changed
	M = 0

// If no key is pressed
(RELEASE)
	@var
	D = M 

	@24576 // Highest display register address
	D = A - D

	@START
	D;JEQ

	@KBD
	D = M

	@PRESS // Checks if a key is pressed
	D;JNE 

	@var
	D = M

	@a
	A = D
	M = 0

	@var
	M = M + 1

	@RELEASE
	0;JMP

// If a key is pressed
(PRESS)
	@var
	D = M

	@24576 // Highest display register address
	D = A - D

	@START
	D;JEQ

	@KBD
	D = M

	@RELEASE // Checks if a key isn't pressed
	D;JEQ

	@var
	D = M

	@a
	A = D
	M = -1

	@var
	M = M + 1

	@PRESS
	0;JMP




