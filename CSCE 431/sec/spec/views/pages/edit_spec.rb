
require 'rails_helper'
require 'capybara/rspec'

xdescribe 'users/new.html.erb', type: :system do
    context 'Go to sign up page' do
        before :each do 
            visit signed_in_root_path
            fill_in 'Email', :with => 'john@doe.com'
            fill_in 'Password', :with => '123'
            click_button 'Sign up'
        end
        it 'renders the first name text field' do
            expect(page).to have_content('First Name')
        end

        it 'renders the last name text field' do
            expect(page).to have_content('Last Name')
        end

        it 'renders the email address text field' do
            expect(page).to have_content('Email')
        end

        it 'renders the alternative email address text field' do
            expect(page).to have_content('Alternative Email')
        end

        it 'renders the phone number text field' do
            expect(page).to have_content('Phone Number')
        end
        
        it 'renders the home phone number text field' do
            expect(page).to have_content('Home Phone Number')
        end

        it 'renders the work phone number text field' do
            expect(page).to have_content('Work Phone Number')
        end

        it 'renders the current company text field' do
            expect(page).to have_content('Current Company')
        end

        it 'renders the role text field' do
            expect(page).to have_content('Role')
        end

        it 'renders the major text field' do
            expect(page).to have_content('Major')
        end

        it 'renders the graduation year text field' do
            expect(page).to have_content('Graduation Year')
        end

        it 'renders the alumni check box' do
            expect(page).to have_content('I am an Alumni')
        end

        it 'renders the hide users check box' do
            expect(page).to have_content('Hide my profile')
        end
    end


    # context 'when it loads' do
        # before :each do 
        #     render
        # end

        # it 'renders the first name text field' do
        #     expect(rendered).to have_field('first_name', type: :text)
        # end

        # it 'renders the last name text field' do
        #     expect(rendered).to have_field('last_name', type: :text)
        # end

        # it 'renders the email address text field' do
        #     expect(rendered).to have_field('email', type: :text)
        # end

        # it 'renders the phone number text field' do
        #     expect(rendered).to have_field('phone_number', type: :text)
        # end

        # it 'renders the current company text field' do
        #     expect(rendered).to have_field('company', type: :text)
        # end

        # it 'renders the alumni check box' do
        #     expect(rendered).to have_field('is_alumni', type: :checkbox)
        # end

        # it 'renders the hide users check box' do
        #     expect(rendered).to have_field('is_visible', type: :checkbox)
        # end

        # it 'renders the save button' do
        #     expect(rendered).to have_field('save', type: :button)
        # end
    # end
    
    # context 'when user has already provided information' do

        # let(:users) do
        #     test_double = double('User')
        #     allow(test_double).to receive(:first_name) {'Bob'}
        #     allow(test_double).to receive(:last_name) {'Steve'}
        #     allow(test_double).to receive(:email) {'b_steve@mail.com'}
        #     allow(test_double).to receive(:phone_number) {'(214)-748-3647'}
        #     allow(test_double).to receive(:company) {'Business Corp.'}
        #     allow(test_double).to receive(:grad_year) {'1976'}
        #     allow(test_double).to receive(:major) {'Sports Management'}
        #     allow(test_double).to receive(:is_alumni) {true}
        #     allow(test_double).to receive(:is_visible) {true}
        #     test_double
        # end

    #     before :each do
    #         assign(:users, users)

    #         render
    #     end

    #     it 'displays the user\'s first name' do
    #         # i.e. expect rendered html to contain a tag with id='fname' and value=users.first_name
    #         expect(rendered).to have_field('fname', with: users.first_name)
    #     end

    #     it 'displays the user\'s last name' do
    #         expect(rendered).to have_field('lname', with: users.last_name)
    #     end

    #     it 'displays the user\'s email' do
    #         expect(rendered).to have_field('email', with: users.email)
    #     end

    #     it 'displays the user\'s phone number' do
    #         expect(rendered).to have_field('phone', with: users.phone_number)
    #     end

    #     it 'displays the user\'s current company' do
    #         expect(rendered).to have_field('company', with: users.company)
    #     end

    #     # it 'displays the user\'s graduation year' do
    #     #     expect(rendered).to have_field('year', with: users.grad_year)
    #     # end

    #     it 'displays the user\'s major' do
    #         expect(rendered).to have_field('major', with: users.major)
    #     end

    #     it 'displays whether the user is an alumni' do
    #         expect(rendered).to have_checked_field('alumni')
    #     end

    #     it 'displays whether the user wants to hide their users' do
    #         expect(rendered).to have_checked_field('hide_users')
    #     end

    # end

end
