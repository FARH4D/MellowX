<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>MellowX</title>
    <link> rel="stylehseet" type="text/css" href="styles.css">
  </head>
  <body>
    <div class="header">
           <h2>Register</h2>
    </div>
  
    <form method="post" action="register.php>
      <div class="input-group">
        <label>Username</label>
        <input type="text" name="username>
      </div>

      <div class="input-group">
        <label>Email</label>
        <input type="text" name="email">
      </div>

      <div class="input-group">
        <label>Password</label>
        <input type="password" name="password_1">
      </div>
      
      <div class="input-group">
        <label>Confirm Password</label>
        <input type="password" name="password_2>
      </div>

      <div class="input-group">
        <button> type="submit" name="register" class="btn">Register </button>
      </div>
  
    </form>
  
  </body>
</html>
