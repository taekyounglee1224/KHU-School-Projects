<!DOCTYPE html>
<html lang='ko'>
<head>
	<meta charset='UTF-8'>
	<title>edit student</title>
</head>

<body>

<?php 
$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "SELECT * FROM P_Student"; 
	$res = mysqli_query($mysqli, $sql); 
 	if ($res) { 
 		echo "<Table border=1>\n";
 		echo "<TH>stdID</TH>  <TH>StdName</TH>  <TH>Phone</TH>  <TH>Email</TH> <TH>Update</TH> <TR>\n";
 		while ($newArray = mysqli_fetch_array($res, MYSQLI_ASSOC)){
			$stdID = $newArray['stdID']; 
 			$StdName = $newArray['StdName']; 
			$Phone = $newArray['Phone']; 
			$Email = $newArray['Email']; 
			echo "<FORM action=UpdateStudentResp.php method=post>\n";
				echo "<input type=hidden name=stdID value=".$stdID.">";
				echo "<TD><input type=text name=newstdID value='".$stdID."'></TD>";
				echo "<TD><input type=text name=StdName value='".$StdName."'></TD>";
				echo "<TD><input type=text name=Phone value='".$Phone."'></TD>";
				echo "<TD><input type=text name=Email value='".$Email."'></TD>";
				echo "<TD><input type=submit value=update></TD>";
				echo "<TR>\n"; 
			echo "</FORM>\n";
 		}
 		echo "</Table>\n";
 	} else { 
 		printf("Could not retrieve records: %s\n", mysqli_error($mysqli)); 
 	} 
 	mysqli_free_result($res); 
 	mysqli_close($mysqli); 
} 
?> 
</body>
</html>