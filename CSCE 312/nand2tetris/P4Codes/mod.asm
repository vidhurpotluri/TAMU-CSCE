// File name: projects/04/mult/Div.asm
// Name: Vidhur Potluri

// Computes the modulus of R0/R1

// Initializes R2
@2
M = 0

// assigns the value of R0 to a
@0
D = M
@a
M = D

// assigns the value of R1 to b
@1
D = M
@b
M = D


(MAIN)
	@a
	D = M

	@b
	D = D - M

	@LOOP
	D;JLT

	@b
	D = M

	@a
	M = M - D

	@MAIN
	0;JMP

// Assigns the LCD to R2
(LOOP)
	@a
	D = M

	@2
	M = D

	@END
	0;JMP

(END)
	@END
	0;JMP