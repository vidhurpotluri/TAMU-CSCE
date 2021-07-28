require "rails_helper"
require "support/features/clearance_helpers"	

RSpec.describe UserMailer, type: :mailer do
    describe 'welcome email' do
		let(:user) { mock_model User, first_name: 'SEC', email: 'SEC@email.com' }
		let(:mail) { described_class.welcome_email(user).deliver_now }

		it 'renders the subject' do
		  expect(mail.subject).to eq('Welcome to the SEC Center!')
		end

		it 'renders the receiver email' do
		  expect(mail.to).to eq([user.email])
		end
	
		it 'renders the sender email' do
		  expect(mail.from).to eq(['from@example.com'])
		end

		it 'assigns @name' do
		  expect(mail.body.encoded).to match(user.first_name)
		end
	end

	describe 'update email' do
		let(:user) { mock_model User, first_name: 'SEC', email: 'SEC@email.com' }
		let(:mail) { described_class.update_email(user).deliver_now }

		it 'renders the subject' do
		  expect(mail.subject).to eq('Update - SEC Center')
		end

		it 'renders the receiver email' do
		  expect(mail.to).to eq([user.email])
		end
	
		it 'renders the sender email' do
		  expect(mail.from).to eq(['from@example.com'])
		end

		it 'assigns @name' do
		  expect(mail.body.encoded).to match(user.first_name)
		end
	end
end