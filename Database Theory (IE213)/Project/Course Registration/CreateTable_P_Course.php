<?php 
$mysqli = new mysqli("localhost","hmlee","2020103959","hmlee");

if (mysqli_connect_errno()) {         
                printf("Connect failed: %s\n", mysqli_connect_error()); 
                exit(); 
} else { 
                $sql = "CREATE TABLE P_Course (
                Grade INT NOT NULL,
                CourseType CHAR(10) NOT NULL,
                CourseName CHAR(30) NOT NULL,
                CourseCode VARCHAR(20) Primary Key,
                CourseCredit INT NOT NULL,
                LectureTime VARCHAR(25) NOT NULL,
                Department CHAR(20) NOT NULL,
                ProfID CHAR(15) NOT NULL,
                CONSTRAINT P_Course_FK foreign key(ProfID)
                	References P_Lecturer(ProfID)
                );"; 
        $res = mysqli_query($mysqli, $sql); 

if ($res === TRUE) { 
        echo "Table P_Course has successfully been created."; 
} else { 
        printf("Could not create table: %s\n", mysqli_error($mysqli)); 
} 

mysqli_close($mysqli); 
} 
?> 