
<?php include 'inc/head.php';?>


<?php 
		$c_arr =  array("./aoc2017/d1.c","./aoc2017/d1p2.c","./aoc2017/d2.c","./aoc2017/d3.c","./aoc2017/d3p2.c","./aoc2017/d4p2.c","./aoc2017/d5.c","./aoc2017/d5p2.c","./aoc2017/d6.c","./aoc2017/d6p2.c","./aoc2017/d7.c","./aoc2017/d7p2.c","./aoc2017/d8.c","./aoc2017/d8p2.c","./aoc2017/d9.c","./aoc2017/d9p2.c","./aoc2017/d10.c","./aoc2017/d10p2.c","./aoc2017/d11.c","./aoc2017/d11p2.c","./aoc2017/d12.c","./aoc2017/d12p2.c","./aoc2017/d13.c","./aoc2017/d13p2.c");

		$input_arr = [];
		foreach($c_arr as $item){
			$new_item = str_replace("./aoc2017/", "", $item);
			$new_item = str_replace("d", "Day ", $new_item);
			$new_item = str_replace("p", " Part ", $new_item);
			$new_item = str_replace(".c", "", $new_item);
			array_push($input_arr, $new_item);
		}

?>


<?php
		if(isset($_POST["run"])){
		

	echo "<a href = aoc_showcase.php><button>Go Back to Showcase Navigation</button></a><br><br>"; 
		$c_path = $c_arr[$_POST['index']];
		$c_path = str_replace(" ", "", $c_path);
		$input_path = str_replace(".c", "input.txt", $c_path);	
		$input_path = str_replace("p2", "", $input_path);
		$instructions_path = str_replace(".c", ".txt", $c_path);
		$answer_path = str_replace(".txt", "answer.txt", $instructions_path);
		if(file_exists($c_path)){
			$myfile = fopen($instructions_path, "r");
			echo '<div class = "aocContainer">';
			echo "<h3>Problem:</h3>";
			echo "<p>";
			while(!feof($myfile)){
				echo (fgets($myfile))."<br>";
			}
			fclose($myfile);
			echo "</p>";
			echo "</div>";
			$myfile = fopen($c_path, "r");

			echo "<div class = aocContainer>";
			echo "<h3>My Code:</h3>";
			echo "<pre>";
			while(!feof($myfile)){
				echo htmlspecialchars(fgets($myfile))."<br>";
			}
			fclose($myfile);
			echo "</pre>";
			echo "<p>My Solution: <div class = 'revealText'><strong>". htmlspecialchars(file_get_contents($answer_path)) . "</div></p></strong>";
			echo "</div>";
			echo "<div class = 'aocContainer'>";
			echo "<h3>Puzzle Input:</h3>";
			echo '<p class = "inputText">';
			echo htmlspecialchars(file_get_contents($input_path));
			echo "</p>";
			echo "</div>";
		}
	}
	else {
		echo"
<h1>Advent of Code 2017 Showcase</h1>
<h2>This page will showcase the problems I completed in the summer of 2022 while learning c for the first time.</h2>
<p>
	Notes (Please read):
</p>
<ul>
	<li>
		Day 2 currently only has part 1 working
	</li>
	<li>
		Day 4 only has part 2 working
	</li>
</ul>";
		
		foreach($input_arr as $i => $item){
		echo "<form action =". htmlspecialchars($_SERVER['PHP_SELF']) . ' method = "POST">';
		echo '<input type = "hidden" name = "index" value =' . $i . '>';
		echo "<input id =\"aocSelect\" type = \"submit\" value = '". $item. "' name = \"run\">";
		echo '</form>';

		}
	}
?>

<?php include 'inc/footer.php';?>

