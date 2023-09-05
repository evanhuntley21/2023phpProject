<?php include 'configuration/database_connection.php';?>
<?php
#error_reporting(E_ERROR | E_PARSE);
	$sql = "SELECT cookie_stored FROM login_stuff;";
	$database_cookie_data = mysqli_query($connection, $sql);
	$database_cookie = mysqli_fetch_all($database_cookie_data, MYSQLI_ASSOC)[0]['cookie_stored'];
	if(!(isset($_COOKIE['temp']) && $_COOKIE['temp'] === $database_cookie)){
		header("Location: progress.php");
	}
	if(isset($_POST["submit"])){
			$new_progress = filter_input(INPUT_POST,"newProgress");
			$sql = "INSERT INTO storage (html_text) VALUES ('$new_progress')";

			if(mysqli_query($connection, $sql)){
				//successful query
				header("Location: progress_admin.php");
			}
			else{
				//connection error
				echo "Error: " . mysqli_error($connection);
			}

	}
	else if(isset($_POST["update"])){
		$new_progress = filter_input(INPUT_POST,"newProgress");
		$sql = "UPDATE storage SET html_text='".$new_progress."'WHERE log_num='".$_POST['index']."'";
		if(mysqli_query($connection, $sql)){
			//successful query
			header("Location: progress_admin.php");
			}
			else{
				//connection error
				echo "Error: " . mysqli_error($connection);
			}
	}
	else if(isset($_POST["delete"])){
		$sql = "DELETE FROM storage WHERE log_num='".$_POST['index']."'";
		if(mysqli_query($connection, $sql)){
			//successful query
				header("Location: progress_admin.php");
			}
			else{
				//connection error
				echo "Error: " . mysqli_error($connection);
			}
	}
	else if(isset($_POST['logout'])){
		setcookie("temp", "", time()-1);
		unset($_COOKIE['temp']);

		$sql = "SELECT username FROM login_stuff;";
		$database_users = mysqli_query($connection, $sql);
		$database_user = mysqli_fetch_all($database_users, MYSQLI_ASSOC)[0]['username'];
		$sql = "UPDATE login_stuff SET cookie_stored = '' WHERE username = '$database_user'";


		mysqli_query($connection, $sql);


		header("Location: login.php");
	}
		$table = mysqli_query($connection, "SELECT * FROM storage");
		$result_arr = mysqli_fetch_all($table, MYSQLI_ASSOC);
?>
<?php include 'inc/head.php';?>



<h1>Progress Log</h1>
	<?php if(isset($_POST["edit"])): ?>
		<?php foreach($result_arr as $item): ?>
			<?php if(isset($_POST[(int)$item['log_num']])): ?>
				<form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>"method = 'POST'>
					<div class = 'inputContainer'>
						<textarea class = 'textInput' name ='newProgress'><?php echo $item['html_text']; ?></textarea>
					</div>
						<input type = "hidden" name = "index" value = "<?php echo (int)$item['log_num']; ?>">
					<div class = 'inputContainer'>
						<input type = 'submit' class = 'submit' name = 'update'
						value = "Update">
					</div>
				</form>

			<?php else : ?>
				<div class = 'progressContainer'><?php echo $item['html_text'];?></div>
			<?php endif ;?>
		<?php endforeach ;?>
	<?php else: ?>
		<?php foreach($result_arr as $item): ?>
			<form id='edit_delete' action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']) ?>" method = 'POST'>
				<div class = 'progressContainer' id ="<?php echo $item['log_num'];?>"><?php echo $item['html_text']; ?></div>
				<div class = 'inputContainer'>
				<input type = 'hidden' name = "index" value = "<?php echo $item['log_num'];?>"></input>
				<input type = 'hidden' name = "<?php echo $item['log_num'];?>"></input>
				</div>
				<div class = 'inputContainer'>
					<input type = 'submit' class = 'submit' name ='edit' value = "Edit">
					<input type = 'submit' class = 'submit' name ='delete' value = "Delete">
				</div>

			</form>
		<?php endforeach; ?>
	<?php endif ;?>




<form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>" method = "POST">
	<div class = "inputContainer">
		<textarea class = "textInput" name = "newProgress" placeholder = 
		"Enter new html or text for progress log"></textarea>
	</div>
	<div class = "inputContainer">
		<input type = "submit" class = "submit" name = "submit" value = "Add new log">
	</div>
</form>
<form action = <?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?> method = "POST">
<input id ="logout" type = "submit" value = "logout" name = "logout">
</form>
<?php include 'inc/footer.php';?>

