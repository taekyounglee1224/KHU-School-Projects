<?php
$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee");

if (mysqli_connect_errno()) {
    echo "Connect failed: " . mysqli_connect_error();
    exit();
} else {
    // Assuming you have the necessary data to insert into the P_Enrollment table
    $stdID = $_POST['stdID'];
    $Grade = $_POST['Grade'];
    $CourseType = $_POST['CourseType'];
    $CourseName = $_POST['CourseName'];
    $CourseCode = $_POST['CourseCode'];
    $CourseCredit = $_POST['CourseCredit'];
    $LectureTime = $_POST['LectureTime'];
    $Department = $_POST['Department'];
    $ProfID = $_POST['ProfID'];

    $stmt = $mysqli->prepare("INSERT INTO P_Enrollment (stdID, Grade, CourseType, CourseName, CourseCode, CourseCredit, LectureTime, Department, ProfID) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
    $stmt->bind_param("sisssisss", $stdID, $Grade, $CourseType, $CourseName, $CourseCode, $CourseCredit, $LectureTime, $Department, $ProfID);

    if ($stmt->execute()) {
        echo "��û�Ǿ����ϴ�.";
    } else {
        echo "��û�� �� �����ϴ�.";
    }

    $stmt->close();
    $mysqli->close();
}
?>
