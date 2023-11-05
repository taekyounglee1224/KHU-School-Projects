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

</head>
<body>

<?php
$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee");

if (mysqli_connect_errno()) {
    printf("Connect failed: %s\n", mysqli_connect_error());
    exit();
}

// Course registration request handling
if (isset($_GET['CourseCode'])) {
    $CourseCode = $_GET['CourseCode'];

    $selectCourseSql = "SELECT * FROM P_Course WHERE CourseCode = '$CourseCode'";
    $selectCourseRes = mysqli_query($mysqli, $selectCourseSql);

    if ($selectCourseRes && mysqli_num_rows($selectCourseRes) >= 0) {
        $courserow = mysqli_fetch_assoc($selectCourseRes);

        $Grade = $courserow['Grade'];
        $CourseType = $courserow['CourseType'];
        $CourseName = $courserow['CourseName'];
        $CourseCode = $courserow['CourseCode'];
        $CourseCredit = $courserow['CourseCredit'];
        $LectureTime = $courserow['LectureTime'];
        $Department = $courserow['Department'];
        $ProfID = $courserow['ProfID'];

        if ($Grade >= 0) {
            $CheckCourseSql = "SELECT * FROM P_RegistrationHistory WHERE CourseCode='$CourseCode'";
            $CheckCourseRes = $mysqli->query($CheckCourseSql);

            if ($CheckCourseRes->num_rows === 0) {
                $insertCourseSql = "INSERT INTO P_RegistrationHistory (Grade, CourseType, CourseName, CourseCode, CourseCredit, LectureTime, Department, ProfID) VALUES ('$Grade', '$CourseType', '$CourseName', '$CourseCode', '$CourseCredit', '$LectureTime', '$Department', '$ProfID')";

                if ($mysqli->query($insertCourseSql) === TRUE) {
                    echo "수강신청 되었습니다.";
                } else {
                    echo "수강신청 에러: " . $mysqli->error;
                }
            } else {
                echo "이미 수강신청된 과목입니다.";
            }
        } else {
            echo "수강신청이 불가능한 과목입니다.";
        }
    } else {
        echo "과목을 찾을 수 없습니다.";
    }
}

mysqli_close($mysqli);
?>
<br>
<div id="btn_bar">
      <input type="button" class= "button button3" value="수강신청 계속하기" onClick="location.href='registration.php'" class="btn"/>
</div>

</body>
</html>

