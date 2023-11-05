<?php
$stdID = $_POST["stdID"];
$newstdID = $_POST["newstdID"];
$StdName = $_POST["StdName"];
$Phone = $_POST["Phone"];
$Email = $_POST["Email"];

$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "UPDATE P_Student ";
	$sql .= " SET stdID='".$newstdID."', StdName='".$StdName."', Phone='".$Phone."', Email='".$Email."'";
	$sql .= " WHERE stdID='".$stdID."'";
	echo $sql;
	$res = mysqli_query($mysqli, $sql); 
 	
	if ($res === TRUE) {
		echo "<p>Your Privacy has been updated successfully.";
	} else {
		printf("Could not update record: %s\n", mysqli_error($mysqli));
	}
	mysqli_close($mysqli);	
}
?>