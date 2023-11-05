<?php
$ProfID = $_POST["ProfID"];
$ProfName = $_POST["ProfName"];
$ProfPhone = $_POST["ProfPhone"];
$ProfEmail = $_POST["ProfEmail"];


$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
} else {
	$sql = "INSERT INTO P_Lecturer (ProfID, ProfName, ProfPhone, ProfEmail)
		VALUES ('$ProfID', '$ProfName', '$ProfPhone', '$ProfEmail');";
	$res = mysqli_query($mysqli, $sql);
	echo "$sql";
	
	if ($res === TRUE) {
		echo "<p>A record has been inserted successfully.";
	} else {
		printf("Could not insert record: %s\n", mysqli_error($mysqli));
	}
	mysqli_close($mysqli);
}
?>
