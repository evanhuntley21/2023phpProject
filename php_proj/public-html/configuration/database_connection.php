<?php
//Add own credentials that matches your database info
	define('DB_HOST', '');
	define('DB_USER', '');
	define('DB_PASS', '');
	define('DB_NAME', '');

	//Create connection

	$connection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);

	//check connection
	if($connection->connect_error){
		die("Conncetion Failed $connection->connect_error");
	}
?>
