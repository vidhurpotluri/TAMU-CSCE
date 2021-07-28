// File name: projects/04/mult/Div.asm
// Name: Vidhur Potluri

// Computes the quotient of R1/R2

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

	@END
	D;JLT

	@2
	M = M + 1

	@b
	D = M

	@a
	M = M - D

	@MAIN
	0;JMP

(END)
	@END
	0;JMP
