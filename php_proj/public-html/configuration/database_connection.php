<?php
	define('DB_HOST', 'db');
	define('DB_USER', '1twoBucklemYshOe');
	define('DB_PASS', 'xT6By=0VzQxYju8es4i00t;ef.dc');
	define('DB_NAME', 'docker_db');

	//Create connection

	$connection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);

	//check connection
	if($connection->connect_error){
		die("Conncetion Failed $connection->connect_error");
	}
?>
