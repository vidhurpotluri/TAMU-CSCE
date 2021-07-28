class UserMailer < ApplicationMailer
	def welcome_email(user)
		@user = user
		mail(to: @user.email, subject: 'Welcome to the SEC Center!')
	end

	def update_email(user)
		@user = user
		mail(to: @user.email, subject: 'Update - SEC Center')	
	end

	def forgot_password(user)
	  @user = user  
	  mail to: user.email, :subject => 'Reset password instructions'
	end
end



