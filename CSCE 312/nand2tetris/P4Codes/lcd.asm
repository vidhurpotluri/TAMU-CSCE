// File name: projects/04/mult/Div.asm
// Name: Vidhur Potluri

// Computes the quotient of R1/R2

// Finding the larger of the two numbers
@0
D = M
@1
D = D - M
@temp
M = 0

@CHOOSE1
D;JLT

@CHOOSE2
D;JGE

// assigns a  to the larger number and b to the other
(CHOOSE1)
	@1
	D = M
	@a
	M = D
	@0
	D = M
	@b
	M = D
	@MAIN
	0;JMP

(CHOOSE2)
	@0
	D = M
	@a
	M = D
	@1
	D = M
	@b
	M = D
	@MAIN
	0;JMP

// Calculates a mod b
(MAIN)
	@b
	D = M

	@LCD
	D;JEQ // If b = 0, then a is the LCD

	@a
	D = M

	@b
	D = D - M

	@MOD
	D;JLT

	@b
	D = M

	@a
	M = M - D

// Changes a to the value of b and b to the value of a mod b
(MOD)
	@a
	D = M
	@temp
	M = D
	@b
	D = M
	@a
	M = D
	@temp
	D = M
	@b
	M = D

	@MAIN
	0; JMP

// Assigns the value of LCD to a 
(LCD)
	@a
	D = M
	@2
	M = D
	@END
	0;JMP

(END)
	@END
	0;JMP
