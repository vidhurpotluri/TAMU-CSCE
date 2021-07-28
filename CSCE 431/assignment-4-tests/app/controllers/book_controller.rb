
class BookController < ApplicationController
  def index
    @books1 = Book.all
  end

  def new
    @books1 = Book.new
  end

  def create
    @books1 = Book.create(params.require(:Book).permit(:title, :author, :genre, :price, :published))
    if @books1.valid?
      redirect_to posts_path
    else
      flash[:errors] = @books1.errors.full_messages
      redirect_to new_posts_path
    end
  end

  def show
  end

  def edit
  end

  def update
  end

  def destroy
  end
end
