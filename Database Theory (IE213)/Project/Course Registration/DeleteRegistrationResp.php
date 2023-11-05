<!DOCTYPE html>
<html lang="ko">
<head>
<title>수강신청 내역</title>
<meta charset="utf-8">
</head>
<style type="text.css">

#btn_bar {
   margin :5px;
}

.button {
  background-color: #4CAF50;
  border-radius: 16px;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
}

.button3 {
	font-size: 10px;
  background-color: white; 
  color: black; 
  border: 4px solid navy;
}

.button3:hover {
  background-color: navy;
  color: white;
}

</style>
<body>

<?php

$CourseCode = $_POST["CourseCode"];

$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "DELETE FROM P_RegistrationHistory WHERE CourseCode='".$CourseCode."'";
	$res = mysqli_query($mysqli, $sql); 
	
	if ($res === TRUE) {
		echo "수강 취소되었습니다";
	} else {
		printf("Could not delete record: %s\n", mysqli_error($mysqli));
	}
	mysqli_close($mysqli);	
}
?>
<br>
<div id="btn_bar">
      <input type="button" class= "button button3" value="수강신청 계속하기" onClick="location.href='registration.php'" class="btn"/>
</div>
</body>
</html>