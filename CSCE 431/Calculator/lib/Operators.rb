require_relative 'Calculator.rb'

#Operator classes
class Addition < Calculator
	def calculate
		@@result = @@a + @@b
	end
end

class Subtraction < Calculator
	def calculate
		@@result = @@a - @@b
	end
end

class Division < Calculator
	def calculate
		@@result = @@a.to_f / @@b.to_f
	end
end

class Multiplication < Calculator
	def calculate
		@@result =  @@a.to_f * @@b.to_f
	end
end

class Circle < Calculator
	def calculate
		@pi = Math::PI #instance variable only used by this class
		@@result =	@pi * @@r * @@r 
	end
end