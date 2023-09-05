<?php include 'configuration/database_connection.php';?>
<?php include 'inc/head.php';?>

<h1>Progress Log</h1>

	<?php 
		$table = mysqli_query($connection, "SELECT * FROM storage");
		$result_arr = mysqli_fetch_all($table, MYSQLI_ASSOC);

	?>


	<?php foreach($result_arr as $item): ?>
		
		<div class = "progressContainer"><?php echo $item['html_text']; ?></div>
	<?php endforeach; ?>
<?php include 'inc/footer.php';?>

