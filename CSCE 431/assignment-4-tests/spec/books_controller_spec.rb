require 'rails_helper'
# test 1 - Checks if visiting the right page - index and if right content is displayed
RSpec.describe BooksController, type: :feature do
	scenario 'index page' do
		visit books_index_path
		expect(page).to have_content('Home Page - Book Collection')
	end	
end

# test 2 - Check if books is created with right variables
RSpec.describe Book, type: :model do
	describe 'book creation' do
		it 'can be created' do
			book = Book.create(title: "Harry", author: "JK", price: "50")
			expect(book).to be_valid
		end
	end
end

#test 3 - Checks navigation
RSpec.describe BooksController, type: :feature do
	scenario 'shows new page' do
		visit books_index_path
		click_button("Add new book")
		expect(page).to have_content('New Book')
		click_link("Return to Home Page")
		expect(page).to have_content('Home Page - Book Collection')
	end
end

# test 4 - Checks if data is pre-filled
RSpec.describe BooksController, type: :feature do
	scenario 'information pre-filled' do
		book = Book.create(title:"Harry", author: "JK", price: "50")
		visit books_index_path
		expect(page).to have_content("Harry")
	end
end
