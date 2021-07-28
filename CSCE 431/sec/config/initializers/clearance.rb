Clearance.configure do |config|
  config.routes = false
  config.mailer_sender = "SECAlumniTracker@gmail.com"
  config.rotate_csrf_on_sign_in = true
  config.redirect_url = "/"
end
