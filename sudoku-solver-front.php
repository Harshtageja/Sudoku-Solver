<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body style="margin-left: 5%">
	<br><br>
	<form name='sudoku' method="post">
		<?php
		$c=1;
		$s="sudoku";
		for($i=0;$i<9;$i++){
			for($j=0;$j<9;$j++){
			?>
		<input  type="text" class="v" name="<?php echo $s.$c  ?>" style="width: 6%;height:50px;margin-left: -0.5rem;font-size: 50px;text-align: center;">
	<?php
	$c++;
}
echo "<br>";
}
?>
	</form>

</body>
</html>