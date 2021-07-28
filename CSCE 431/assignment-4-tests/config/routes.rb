Rails.application.routes.draw do
  get 'books/index'
  get 'books/new'
  get 'books/create'
  get 'books/show'
  get 'books/edit'
  get 'books/update'
  get 'books/destroy'
  get 'books/delete'
  resources :books
  root to:'books#index'
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
end
