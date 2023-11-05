<?php
$stdID = $_POST["stdID"];
$StdName = $_POST["StdName"];
$Phone = $_POST["Phone"];
$Email = $_POST["Email"];

$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
} else {
	$sql = "INSERT INTO P_Student (stdID, StdName, Phone, Email)
		VALUES ('$stdID', '$StdName', '$Phone', '$Email');";
	$res = mysqli_query($mysqli, $sql);
	echo "$sql";
	
	if ($res === TRUE) {
		echo "<p>회원가입이 완료되었습니다.";
	} else {
		printf("Could not insert record: %s\n", mysqli_error($mysqli));
	}
	mysqli_close($mysqli);
}
?>
