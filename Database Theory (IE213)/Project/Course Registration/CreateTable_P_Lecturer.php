<?php 
$mysqli = new mysqli("localhost","hmlee","2020103959","hmlee");

if (mysqli_connect_errno()) {         
                printf("Connect failed: %s\n", mysqli_connect_error()); 
                exit(); 
} else { 
                $sql = "CREATE TABLE P_Lecturer ( 
                ProfID CHAR(15) Primary Key, 
                ProfName CHAR(50) NOT NULL,
                ProfPhone CHAR(20) NOT NULL,
                ProfEmail VARCHAR(100) NULL
                );"; 
        $res = mysqli_query($mysqli, $sql); 

if ($res === TRUE) { 
        echo "Table P_Lecturer has successfully been created."; 
} else { 
        printf("Could not create table: %s\n", mysqli_error($mysqli)); 
} 

mysqli_close($mysqli); 
} 
?> 