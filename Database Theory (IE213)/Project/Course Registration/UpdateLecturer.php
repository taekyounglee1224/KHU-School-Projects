<!DOCTYPE html>
<html lang='ko'>
<head>
	<meta charset='UTF-8'>
	<title>edit lecturer</title>
</head>

<body>

<?php 
$mysqli = new mysqli("localhost", "hmlee", "2020103959", "hmlee"); 

if (mysqli_connect_errno()) { 
	printf("Connect failed: %s\n", mysqli_connect_error()); 
	exit(); 
} else { 
	$sql = "SELECT * FROM P_Lecturer"; 
	$res = mysqli_query($mysqli, $sql); 
 	if ($res) { 
 		echo "<Table border=1>\n";
 		echo "<TH>ProfID</TH>  <TH>ProfName</TH>  <TH>ProfPhone</TH>  <TH>ProfEmail</TH> <TH>Update</TH> <TR>\n";
 		while ($newArray = mysqli_fetch_array($res, MYSQLI_ASSOC)){
			$ProfID = $newArray['ProfID']; 
 			$ProfName = $newArray['ProfName']; 
			$ProfPhone = $newArray['ProfPhone']; 
			$ProfEmail = $newArray['ProfEmail']; 
			echo "<FORM action=UpdateLecturerResp.php method=post>\n";
				echo "<input type=hidden name=stuNum value=".$ProfID.">";
				echo "<TD><input type=text name=newStuNum value='".$ProfID."'></TD>";
				echo "<TD><input type=text name=name value='".$ProfName."'></TD>";
				echo "<TD><input type=text name=phone value='".$ProfPhone."'></TD>";
				echo "<TD><input type=text name=email value='".$ProfEmail."'></TD>";
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