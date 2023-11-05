<!DOCTYPE html>
<html lang="ko">
<head>
<meta charset='utf-8'>
<title>수강신청</title>
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
   width:250px;
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
.image-container {
            position: fixed;
            top: 0;
            right: 0;
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
  background-color: white; 
  color: black; 
  border: 2px solid #4CAF50;
}

.button1:hover {
  background-color: #4CAF50;
  color: white;
}


.button2 {
	font-size: 4px;
  background-color: white; 
  color: black; 
  border: 2px solid #008CBA;
}

.button2:hover {
  background-color: #008CBA;
  color: white;
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

</head>

<body>
<div id="head_bar">
	<div class="one">2023년도 2학기 수강신청</div>


</div>


<div id="btn_bar">
    <!-- 공지사항, 수강신청내역 버튼 추가 -->
    <input type="button" class= "button button3" value="공지사항" onClick="location.href='announcement.html'" class="btn"/> <input type="button" class= "button button3" value="수강신청내역" onClick="location.href='DeleteRegistration.php'" class="btn"/>
</div>

<div class="image-container">
       <a href="linkpage.html">
          <img src = "home.PNG" width ="70" height="70">
       </a>
    </div>

 
<?php
$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee");

if ($mysqli->connect_error) {
    die("데이터베이스 연결 실패: " . $mysqli->connect_error);
    exit();
} else {
    $sql = "SELECT * FROM P_Course";
    $res = $mysqli->query($sql);

    if ($res->num_rows > 0) {
        echo " <table>";

        echo "<tr>
            	<th>학년</th>
            	<th>이수구분</th>
            	<th>교과목명</th>
            	<th>학수번호</th>
            	<th>학점</th>
            	<th>강의시간</th>
            	<th>개설학과</th>
            	<th>교수ID</th>
            	<th>신청</th>
            	</tr>";

        while ($row = $res->fetch_assoc()) {
            $Grade = $row['Grade'];
            $CourseType = $row['CourseType'];
            $CourseName = $row['CourseName'];
            $CourseCode = $row['CourseCode'];
            $CourseCredit = $row['CourseCredit'];
            $LectureTime = $row['LectureTime'];
            $Department = $row['Department'];
            $ProfID = $row['ProfID'];

            echo "<tr>";
            echo "<td>$Grade</td>";
            echo "<td>$CourseType</td>";
            echo "<td>$CourseName</td>";
            echo "<td>$CourseCode</td>";
            echo "<td>$CourseCredit</td>";
            echo "<td>$LectureTime</td>";
            echo "<td>$Department</td>";
            echo "<td>$ProfID</td>";
            echo '<td><a href="registrationhistory.php?CourseCode=' . $row['CourseCode'] . '" class="otherbutton button2">신청</a></td>';

            echo "</tr>";
        }
        echo "</table>";
    } else {
        printf("Could not retrieve records: %s\n", mysqli_error($mysqli));
    }
    mysqli_free_result($res);

    mysqli_close($mysqli);
}
?>

</body>
</html>