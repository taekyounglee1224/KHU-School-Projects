<?php
$stdID = $_GET["id"];
$password = $_GET["password"];
$mysqli = mysqli_connect("localhost", "hmlee", "2020103959", "hmlee");
$check = "SELECT * FROM P_Student WHERE stdID ='$stdID'";
$result = mysqli_query($mysqli, $check);
$row = mysqli_fetch_array($result);

if ($row) {
    // The record with the entered stdID exists
    echo "<script>location.href = 'linkpage.html';</script>";
} else {
    // The record with the entered stdID does not exist
    echo "<script>window.alert('아이디 또는 비밀번호가 잘못되었습니다.');</script>";
    echo "<script>location.href='InsertStudent.php';</script>";
}
?>
