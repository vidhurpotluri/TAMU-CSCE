require_relative 'Calculator'
require_relative 'Operators'

ui = "" #User input for type of operation
while true
	puts "What calculation would you like to do? (Add(a), Subtract(s), Multiply(m), Divide(d), area of circle(c)) To quit, press q. "
	ui = gets.chomp

	#Exit message
	if ui == "q"
		puts "Have a great day!!"
		break

	#Since area of circle only needs one input, it is a special case -
	elsif ui == "c"
		puts "Enter the radius of the circle: "
		r = gets.chomp.to_f
		cal = Circle.new(0,0,r)

	#All other operations need 2 numbers -
	else 
		puts "Enter the first number: "
		a = gets.chomp.to_f
		puts "Enter the second number: "
		b = gets.chomp.to_f

		#Addition
		if ui == "a"
			cal = Addition.new(a,b,0)
		#Subtraction
		elsif ui == "s"
			cal = Subtraction.new(a,b,0)
		#Multiplication
		elsif ui == "m"
			cal = Multiplication.new(a,b,0)
		#Division
		elsif ui == "d"
			cal = Division.new(a,b,0)

		end

	end
	cal.calculate
	cal.displayResult
end
