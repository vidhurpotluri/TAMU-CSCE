class User < ApplicationRecord
  include Clearance::User


  def self.search(search)
    
    if search
      args = search.split(" ")
      #Person.find(:all, :include => [ :account, :friends ])
      #users = User.find(:email, :first_name, :last_name, :phone_number, :company, :major)
      if(args.size == 1)
        #Client.where("orders_count = ? AND locked = ?", params[:orders], false)
        users = User.where("first_name = ? OR last_name = ?", args[0], args[0])
      else
        users = User.where(first_name: args[0], last_name: args[1])
      end
    
      users
    else
      nil
    end
  end


  def name
    first_name + last_name
  end

  #  sends an e-mail with a link for the user to reset the password
  def send_password_reset
	  generate_token(:password_reset_token)
	  self.password_reset_sent_at = Time.zone.now
	  save!
	  UserMailer.forgot_password(self).deliver 
  end

  # This generates a random password reset token for the user
  def generate_token(column)
	  begin
		self[column] = SecureRandom.urlsafe_base64
	  end while User.exists?(column => self[column])
  end

end
