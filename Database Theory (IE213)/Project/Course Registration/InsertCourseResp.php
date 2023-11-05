<?php
$Grade = $_POST["Grade"];
$CourseType = $_POST["CourseType"];
$CourseName = $_POST["CourseName"];
$CourseCode = $_POST["CourseCode"];
$CourseCredit = $_POST["CourseCredit"];
$LectureTime = $_POST["LectureTime"];
$Department = $_POST["Department"];
$ProfID = $_POST["ProfID"];

$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
} else {
	$sql = "INSERT INTO P_Course (Grade, CourseType, CourseName, CourseCode, CourseCredit, LectureTime, Department, ProfID)
		VALUES ('$Grade', '$CourseType', '$CourseName', '$CourseCode', '$CourseCredit', '$LectureTime', '$Department', '$ProfID');";
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
