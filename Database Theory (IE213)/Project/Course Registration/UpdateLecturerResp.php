<?php
$ProfID = $_POST["ProfID"];
$newProfID = $_POST["newProfID"];
$ProfName = $_POST["ProfName"];
$ProfPhone = $_POST["ProfPhone"];
$ProfEmail = $_POST["ProfEmail"];

$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "UPDATE P_Lecturer ";
	$sql .= " SET ProfID='".$newProfID."', ProfName='".$ProfName."', ProfPhone='".$ProfPhone."', ProfEmail='".$ProfEmail."'";
	$sql .= " WHERE ProfID='".$ProfID."'";
	echo $sql;
	$res = mysqli_query($mysqli, $sql); 
 	
	if ($res === TRUE) {
		echo "<p>A record has been updated successfully.";
	} else {
		printf("Could not update record: %s\n", mysqli_error($mysqli));
	}
	mysqli_close($mysqli);	
}
?>



