<?php include 'configuration/database_connection.php';?>
<?php
	$sql = "SELECT cookie_stored FROM login_stuff;";
	$database_cookie_data = mysqli_query($connection, $sql);
	$database_cookie = mysqli_fetch_all($database_cookie_data, MYSQLI_ASSOC)[0]['cookie_stored'];
	if((isset($_COOKIE['temp']) && $_COOKIE['temp'] === $database_cookie)){
		header("Location: progress_admin.php");
	}
	$incorrect_login = false;
if(isset($_POST['login'])){

//	else{
		$sql = "SELECT password FROM login_stuff;";
		$database_passwords = mysqli_query($connection, $sql);
		$database_password = mysqli_fetch_all($database_passwords, MYSQLI_ASSOC)[0]['password'];



		$sql = "SELECT username FROM login_stuff;";
		$database_users = mysqli_query($connection, $sql);
		$database_user = mysqli_fetch_all($database_users, MYSQLI_ASSOC)[0]['username'];

		if(password_verify($_POST['pass'], $database_password) && $database_user === $_POST['username']  ){
			$my_hash = md5(uniqid());
			$my_cookie_name = "temp";
			$my_cookie_value = $my_hash;
			$my_cookie_exp = time() + 60000;
			$my_cookie_path = "/";
			$domain = "";
			$is_cookie_secure = false;
			$is_cookie_httponly = true;

			$sql = "UPDATE login_stuff SET cookie_stored = '$my_hash' WHERE username = '$database_user'";


			mysqli_query($connection, $sql);

			setcookie($my_cookie_name, $my_cookie_value, $my_cookie_exp, $my_cookie_path, $domain, $is_cookie_secure, $is_cookie_httponly);
			header("Location: progress_admin.php");	
		}
		else{
			$incorrect_login = true;
			sleep(1);
		}
//	}
}

	
?>
<?php include 'inc/head.php';?>

<h1>Login</h1>

<?php if($database_cookie != ""):?>
	<h2> Another user is already logged in, please wait</h2>
<?php else: ?>
	<h3>To access admin page, please login.</h3>
	<div class = "loginContainer">
		<form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>" method = "POST">
			<div class = "inputContainer">
				Enter Username:<br><input type = "text" name = "username" required>			
			</div>

			<div class = "inputContainer">
				Enter Password:<br><input type = "password" name = "pass" required>
			</div>
			<div class = "inputContainer">
				<input type = "submit" class = "submit" name = "login" value = "login">
			</div>
		</form>
	</div>
	<?php if($incorrect_login) :?>
		<p>Incorrect Login! Please try again</p>
	<?php endif ?>
<?php endif ?>
	
<?php include 'inc/footer.php';?>

