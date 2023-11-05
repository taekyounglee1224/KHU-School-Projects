<!DOCTYPE html>
<html lang='ko'>
<head>
	<meta charset='UTF-8'>
	<title>수강신청내역</title>
</head>
<style type="text/css">

table {
			border-collapse: collapse;
			width: 100%;
		}
		th, td {
			border: 1px solid black;
			padding: 8px;
		}
		th {
			background-color: #f2f2f2;
		}
* {
  box-sizing: border-box;
  padding: 0;
  margin: 0 auto;}
  
#btn_bar {
   margin :5px;
}
.image-container {
            position: fixed;
            top: 0;
            right: 0;
        }

  
.otherbutton {
  background-color: #4CAF50;
  border-radius: 16px;
  color: white;
  padding: 8px 16px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 2px;
  margin: 4px 2px;
  cursor: pointer;
}

.button1 {
  background-color: red; 
  color: white; 
  border: 2px solid red;
}

.button1:hover {
  background-color: red;
  color: white;
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
<br>
<h2><수강신청내역></h2>
<div class="image-container">
       <a href="linkpage.html">
          <img src = "home.PNG" width ="70" height="70">
       </a>
    </div>
<br>
<?php 
$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "SELECT * FROM P_RegistrationHistory"; 
	$res = mysqli_query($mysqli, $sql); 
 	if ($res) { 
 		echo "<Table>\n";
 		echo "<TH>학년</TH>  <TH>이수구분</TH>  <TH>교과목명</TH>  <TH>학수번호</TH>  <TH>학점</TH>  <TH>강의시간</TH>  <TH>개설학과</TH>  <TH>교수ID</TH> <TH>삭제</TH> <TR>\n";
 		while ($newArray = mysqli_fetch_array($res, MYSQLI_ASSOC)){
			$Grade = $newArray['Grade']; 
 			$CourseType = $newArray['CourseType']; 
 			$CourseName = $newArray['CourseName']; 
 			$CourseCode = $newArray['CourseCode']; 
 			$CourseCredit = $newArray['CourseCredit']; 
 			$LectureTime = $newArray['LectureTime']; 
 			$Department = $newArray['Department']; 
 			$ProfID = $newArray['ProfID']; 
		
 			echo "<TD>".$Grade."</TD>";
 			echo "<TD>".$CourseType."</TD>";
 			echo "<TD>".$CourseName."</TD>";
 			echo "<TD>".$CourseCode."</TD>";
 			echo "<TD>".$CourseCredit."</TD>";
 			echo "<TD>".$LectureTime."</TD>";
 			echo "<TD>".$Department."</TD>";
 			echo "<TD>".$ProfID."</TD>";
			echo "<TD>";
			echo "<FORM action=DeleteRegistrationResp.php  method=post>\n";
				echo "<input type=hidden name=CourseCode value=".$CourseCode.">";
				echo "<input type=submit class='otherbutton button1' value=삭제>";
			echo "</Form>";
			echo "</TD>\n";
			echo "<TR>\n"; 
 		}
 		echo "</Table>\n";
 	} else { 
 		printf("Could not retrieve records: %s\n", mysqli_error($mysqli)); 
 	} 
 	mysqli_free_result($res); 
 	mysqli_close($mysqli); 
} 
?> 
<br>
<div id="btn_bar">
      <input type="button" class= "button button3" value="수강신청 계속하기" onClick="location.href='registration.php'" class="btn"/>
</div>
</body>
</html>