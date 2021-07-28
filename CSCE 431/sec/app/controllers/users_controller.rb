class UsersController < Clearance::UsersController

  def index
    @users = User.all
  end

  def search
    @users = User.search(params[:search])
  end

  def mail
	#@user = current_user
	#@users = User.where(id: params[:users])
	params[:users].split('/').each do |id|
		user = User.find(id)
		UserMailer.update_email(user).deliver_now
	end


	
  end

  def show
    @user = User.find(params[:id])
    # @user = current_user
  end

  def edit
    # @user = User.find(params[:id])
  end

  def update
    @user = User.find(params[:id])
    if @user.update(user_params_safe)
      # issue complete message      
    else
      # issue error message
    end
  end
  
  def user_from_params
    email = user_params.delete(:email)
    password = user_params.delete(:password)
	first_name = user_params.delete(:first_name)
	last_name = user_params.delete(:last_name)
	phone_number = user_params.delete(:phone_number)
	grad_year = user_params.delete(:grad_year)

    Clearance.configuration.user_model.new(user_params).tap do |user|
      user.email = email
      user.password = password
	  user.first_name = first_name
	  user.last_name = last_name
	  user.phone_number = phone_number
	  user.grad_year = grad_year
    end
  end

  def create
    @user = user_from_params

    if @user.save
	  sign_in @user
      UserMailer.welcome_email(@user).deliver_now
      redirect_back_or url_after_create
	else
	  render template: "users/new"
	end
  end





  private
    def user_params_safe
      params.require(:user).permit(:email, :alternative_email, :first_name, :last_name, :phone_number, :home_phone_number, :work_phone_number, :company, :role, :major, :grad_year, :is_alumni, :is_visible)
    end

end