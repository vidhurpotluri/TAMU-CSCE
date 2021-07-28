class AddExtraUserInfo < ActiveRecord::Migration[6.0]
  def change
    add_column :users, :first_name, :string
    add_column :users, :last_name, :string
    add_column :users, :phone_number, :string
    add_column :users, :company, :string
    add_column :users, :role, :string
    add_column :users, :major, :string
    add_column :users, :is_alumni, :boolean
    add_column :users, :is_visible, :boolean
  end
end