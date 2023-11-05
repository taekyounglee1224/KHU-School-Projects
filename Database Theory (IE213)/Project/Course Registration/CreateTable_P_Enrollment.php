<?php 
$mysqli = new mysqli("localhost","hmlee","2020103959","hmlee");

if (mysqli_connect_errno()) {         
                printf("Connect failed: %s\n", mysqli_connect_error()); 
                exit(); 
} else { 
                $sql = "CREATE TABLE P_Enrollment (
                stdID CHAR(15) NOT NULL,
                Grade INT NOT NULL,
                CourseType CHAR(10) NOT NULL,
                CourseName CHAR(30) NOT NULL,
                CourseCode VARCHAR(20) NOT NULL,
                CourseCredit INT NOT NULL,
                LectureTime VARCHAR(25) NOT NULL,
                Department CHAR(20) NOT NULL,
                ProfID CHAR(15) NOT NULL,
                CONSTRAINT P_Enrollment_PK primary key(stdID, CourseCode),
                CONSTRAINT P_Enrollment_FK1 foreign key(stdID)
                	References P_Student(stdID),
                CONSTRAINT P_Enrollment_FK2 foreign key(CourseCode)
                	References P_Course(CourseCode)
                );"; 
        $res = mysqli_query($mysqli, $sql); 

if ($res === TRUE) { 
        echo "Table P_Enrollment has successfully been created."; 
} else { 
        printf("Could not create table: %s\n", mysqli_error($mysqli)); 
} 

mysqli_close($mysqli); 
} 
?> 