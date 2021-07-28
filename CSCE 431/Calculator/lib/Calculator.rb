# Ruby Calculator

# Calculator class with instance variables
class Calculator
	#class variable - can be accessed by subclasses
	@@result = 0 #result of operation

	attr_accessor :result # to access result variable

	def initialize(a, b, r)
		#class variables
		@@a = a 			#first number
		@@b = b				#second number
		@@r = r 			#circle radius
	end

	def calculate
	end

	def displayResult
		puts ('Result:')
		puts @@result
	end
end

