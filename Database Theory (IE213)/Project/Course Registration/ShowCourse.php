<!DOCTYPE html>
<html lang='ko'>
<head>
	<meta charset='UTF-8'>
	<title>종합시간표 조회</title>
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
  

#head_bar{
   overflow:visible;
   height:70px;
   width:2000px;
   background-color: #dadada;
}

#head_bar .one{
   float:left;
   height:70px;
   width:200px;
   font-size:20px;
   text-align: center;
   line-height:70px;
   background-color: #094a9a;
   color:#fff;
   box-sizing: border-box;
   margin-right: 200px;

}

#head_bar .ttt{
   float:left;
   height:70px;
   width:200px;
   line-height:70px;
   text-align: center;
   font-size:20px;
   margin-right:-50px;

   

}

#head_bar .ttt_1{
   float:left;
   background-color: white;
   text-align: center;
   line-height:60px;
   height:60px;
   width:200px;
   font-size:20px;
   border:solid 1px black;
   margin :5px;
}

#btn_bar {
   margin :5px;
}

.image-container {
            position: fixed;
            top: 0;
            right: 0;
        }

#btn_bar .btn{
   float:left;
   background-color: #094a9a;
   width:100x;
   height:50px;
   margin-right:10px;
   text-align: center;
   color:#fff;
   margin-bottom: 20px;
}

#list_head {
   height:450px;
   width:2000px;
   text-align: center;
   margin-left: 0px;
   white-space:nowrap;
}

#sub_list {
   float:left;
   text-align: center;
   height:400px;
   width:1800px;
   margin-left: 5px;
   border-collapse : collapse;
   margin-bottom: 20px;

 }
.tr th{
  background-color: #dadada;
 }
 
.list_btn {
   height:35px;
   width:45px;
   background-color: #094a9a;
   color:#fff;
}
.jpg{
float:left;
   width:30px;
   height:30px;
   background-color: #094a9a;
   color:#fff;
   text-align: center;
   font-size:15px;


}

#list_jpg{
   float:left;
   width:1000px;
   margin-bottom: 20px;
}

#last_list{
float:left;
   text-align: center;
   height:210px;
   width:1800px;
   margin-left: 5px;
   border-collapse : collapse;
   margin-bottom: 20px;
   table-layout: fixed;
}
</style>
</head>

<body>
<br>
<h2><종합시간표 조회></h2>
<br>
<div class="image-container">
       <a href="linkpage.html">
          <img src = "home.PNG" width ="70" height="70">
       </a>
    </div>
<?php 
$mysqli = new mysqli("localhost","hmlee","2020103959","hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "SELECT * FROM P_Course"; 
	$res = mysqli_query($mysqli, $sql); 
 	if ($res) { 
 		echo "<table border=1>\n";
 		echo "<th>학년</th>  <th>이수구분</th>  <th>학수번호</th>  <th>교과목명</th>   <th>학점</th>   <th>강의시간</th>  <th>개설학과</th>  <th>교수ID</th>  <tr>\n";
 		while ($newArray = mysqli_fetch_array($res, MYSQLI_ASSOC)){
			$Grade = $newArray['Grade']; 
 			$CourseType = $newArray['CourseType']; 
			$CourseCode = $newArray['CourseCode']; 
			$CourseName = $newArray['CourseName']; 
			$CourseCredit = $newArray['CourseCredit']; 
 			$LectureTime = $newArray['LectureTime']; 
			$Department = $newArray['Department']; 
			$ProfID = $newArray['ProfID']; 
			
			
 			echo "<td>".$Grade."</td>";
 			echo "<td>".$CourseType."</td>";
 			echo "<td>".$CourseCode."</td>";
 			echo "<td>".$CourseName."</td>";
 			echo "<td>".$CourseCredit."</td>";
 			echo "<td>".$LectureTime."</td>";
 			echo "<td>".$Department."</td>";
 			echo "<td>".$ProfID."</td>";
 			
 			
 			echo "<tr>\n"; 
 		}
 		echo "</table>\n";
 	} else { 
 		printf("Could not retrieve records: %s\n", mysqli_error($mysqli)); 
 		echo "<p>$sql";
 	} 
 	mysqli_free_result($res); 
 	mysqli_close($mysqli); 
} 
?> 
</body>
</html>
