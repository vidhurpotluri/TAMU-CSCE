class AddGradYear < ActiveRecord::Migration[6.0]
  def change
    add_column :users, :grad_year, :string
  end
end
