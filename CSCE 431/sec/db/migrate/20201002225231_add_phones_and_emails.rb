class AddPhonesAndEmails < ActiveRecord::Migration[6.0]
  def change
    add_column :users, :alternative_email, :string
    add_column :users, :home_phone_number, :string
    add_column :users, :work_phone_number, :string
  end
end
