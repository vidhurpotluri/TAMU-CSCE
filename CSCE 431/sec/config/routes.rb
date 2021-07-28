Rails.application.routes.draw do
  resources :password_resets
  resources :passwords, controller: "clearance/passwords", only: [:create, :new]
  resource :session, controller: "clearance/sessions", only: [:create]

  resources :users, only: :create do
    resource :password,
      controller: "clearance/passwords",
      only: [:create, :edit, :update]
  end

  match 'users/mail/:users', to: 'users#mail', via: :post, as: 'users_mail'

  get "/sign_in" => "clearance/sessions#new", as: "sign_in"
  delete "/sign_out" => "clearance/sessions#destroy", as: "sign_out"
  get "/sign_up" => "clearance/users#new", as: "sign_up"
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html

  constraints Clearance::Constraints::SignedIn.new do
    # match '/users/:user_id/edit', to: 'users#edit', via: :get, as: :edit_user
    # match '/users/:user_id', to: 'users#show', via: :get, as: :user
    # match '/users/:user_id', to: 'users#update', via: [:put, :patch]
    # get '/users/index', to: 'users#index', as: :users

    match 'users/search/:query', to: 'users#search', via: :get, as: 'users_search'

    root to: "users#edit", as: :signed_in_root
  end

  constraints Clearance::Constraints::SignedOut.new do
    
    # get '/users/index', to: 'users#index'

    root to: "clearance/users#new", as: :signed_out_root
  end

  # root 'clearance/users#new'
  resources :users, controller: :users, only: [:create, :show, :index, :edit, :update]


end
