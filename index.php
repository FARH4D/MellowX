<?php


session_start();

    include("connection.php");
    include("functions.php");

    $user_data = check_login($con);

// Farhad this is the page where user will be taken upon succesful log in, the html part is just basic code so replace all that with what you have and that will become the new index.html. This php part needs to be included so just add this to the top of your index.html and we will change the files so after logging in it goes to the home page you have made.

?> 



<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>MellowX</title>
</head>
<body>

    <a href="logout.php">Logout</a>
    <h1>MellowX index page</h1>

    <br>
    Hello, <?php echo $user_data['user_name']; // This part takes users name from database so include this in your index too. ?>
</body>
</html>