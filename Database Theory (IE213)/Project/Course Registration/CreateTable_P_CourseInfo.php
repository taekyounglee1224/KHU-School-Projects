<?php 
$mysqli = new mysqli("localhost","hmlee","2020103959","hmlee");

if (mysqli_connect_errno()) {         
                printf("Connect failed: %s\n", mysqli_connect_error()); 
                exit(); 
} else { 
                $sql = "CREATE TABLE P_CourseInfo (
                CourseName CHAR(30) NOT NULL,
                CourseCode VARCHAR(20) NOT NULL,
                LectureTime VARCHAR(25) NOT NULL,
                Department CHAR NOT NULL,
                CONSTRAINT P_Enrollment_PK primary key(LectureTime, CourseCode),
                CONSTRAINT P_CourseInfo_FK foreign key(Coursecode)
                	References P_Course(CourseCode)
                );"; 
        $res = mysqli_query($mysqli, $sql); 

if ($res === TRUE) { 
        echo "Table P_CourseInfo has successfully been created."; 
} else { 
        printf("Could not create table: %s\n", mysqli_error($mysqli)); 
} 

mysqli_close($mysqli); 
} 
?> 