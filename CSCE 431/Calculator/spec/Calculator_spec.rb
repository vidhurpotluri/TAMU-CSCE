require "Calculator"

#Calculator class rspec tests
describe "Calculator" do

	#test #1 - tests attr_accessor - checks if result is accessible for reading and writing
	describe 'attributes' do
		it "allows reading and writing for :result" do
			cal = Calculator.new(0,0,0)
			cal.result = 0
			expect(cal.result).to eq(0)
		end
	end
end

require "Operators"

#Operator classes rspec tests
describe "Addition" do

	#test #2 - adds 2 numbers
	describe '.calculate' do
		it "adds two regular integers and saves the value in :result" do
			cal = Addition.new(1005,3987,0)
			expect(cal.calculate).to eq(1005+3987)
		end
	end
end

describe "Subtraction" do

	#test #3 - subtract 2 numbers
	describe '.calculate' do
		it "subtracts two regular integers and saves the value in :result" do
			cal = Subtraction.new(1005,3987,0)
			expect(cal.calculate).to eq(1005-3987)
		end
	end
end

describe "Multiplication" do

	#test #4 - multiplies 2 numbers
	describe '.calculate' do
		it "multiplies two regular integers and saves the value in :result" do
			cal = Multiplication.new(23567,3987,0)
			expect(cal.calculate).to eq(23567*3987)
		end
	end

	#test #5 - returns 0 if input is invalid
	describe '.calculate' do
		it 'returns 0 if a string or any invalid input is given' do
			cal = Multiplication.new('asd','asds',0)
			expect(cal.calculate).to eq(0)
		end
	end
end

describe "Division" do

	#test #6 - divides 2 float numbers that are not perfectly divisible
	describe '.calculate' do
		it "divides two numbers and saves the value in :result" do
			cal = Division.new(23567.123,3987.33,0)
			expect(cal.calculate).to eq(23567.123.to_f/3987.33.to_f)
		end
	end

	#test #7 - divides a number by 0
	describe '.calculate' do
		it 'divides a number by 0 and returns infinity' do
			cal = Division.new(1000,0,0)
			expect(cal.calculate).to eq(Float::INFINITY)
		end
	end
end

describe "Circle" do

	#test #8 - calculates area of circle
	describe '.calculate' do
		it "calculates the area of a circle" do
			cal = Circle.new(0,0,1924.5)
			expect(cal.calculate).to eq(Math::PI*1924.5*1924.5)
		end
	end
end
