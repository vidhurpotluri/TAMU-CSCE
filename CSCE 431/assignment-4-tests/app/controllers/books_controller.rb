class BooksController < ApplicationController
  def index
    @books1 = Book.all
  end

  def new
    @book = Book.new
  end

  def create
    @book = Book.create(params.require(:book).permit(:title, :author, :genre, :price, :published))
    redirect_to books_path
    flash[:notice] = "Book '#{@book.title}' created succesfully."
  end

  def show
    @book = Book.find(params[:id])
  end

  def edit
    @book = Book.find(params[:id])
  end

  def update
    @book = Book.find(params[:id])
    @book.update(params.require(:book).permit(:title, :author, :genre, :price, :published))
    redirect_to books_path(@books1)
    flash[:notice] = "Book '#{@book.title}' updated succesfully."
  end

  def destroy
    @book = Book.find(params[:id])
    @book.destroy
    redirect_to books_path
    flash[:notice] = "Book '#{@book.title}' deleted succesfully."
  end
end
