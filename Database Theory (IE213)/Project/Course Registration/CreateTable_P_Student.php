<?php 
$mysqli = new mysqli("localhost","hmlee","2020103959","hmlee");

if (mysqli_connect_errno()) {         
                printf("Connect failed: %s\n", mysqli_connect_error()); 
                exit(); 
} else { 
                $sql = "CREATE TABLE P_Student ( 
                stdID CHAR(15) Primary Key, 
                StdName CHAR(50) NOT NULL,
                Phone CHAR(20) NOT NULL,
                Email VARCHAR(100) NULL
                );"; 
        $res = mysqli_query($mysqli, $sql); 

if ($res === TRUE) { 
        echo "Table P_Student has successfully been created."; 
} else { 
        printf("Could not create table: %s\n", mysqli_error($mysqli)); 
} 

mysqli_close($mysqli); 
} 
?> 