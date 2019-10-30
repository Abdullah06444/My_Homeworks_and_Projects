<?php include("mojolin_globals.php");
//open connection
$dbLink = mysqli_connect($db_server, $db_user, $db_password);

//open monster database
mysqli_select_db($dbLink, $primary_db);

function clean_html($input_text)
{
   $semi_colons=str_replace("_semi_colon_",";",$input_text);
   $single_quotes=str_replace("_single_quotes_","\'",$semi_colons);
   $double_quotes=str_replace("_double_quotes_","\"",$single_quotes);
   $select=str_replace("_select_" ,"select",$double_quotes);
   $insert=str_replace("_insert_" ,"insert",$select);
   $delete=str_replace("_delete_" ,"delete",$insert);
   $alter=str_replace("_alter_" ,"alter",$delete);
   $drop=str_replace("_drop_" ,"drop",$alter);
   $describe=str_replace("_describe_" ,"describe",$drop);
   $script=str_replace("_script_" ,"script",$describe);
   $dotted=str_replace("--------------------" ,"",$script);

   $noslashes=stripslashes($dotted);
   $notags=strip_tags($noslashes,"<pre><b><ol><ul><li><i><u><big><small><font>");
   $with_brs=nl2br($notags);
   $cleaned=stripslashes($with_brs);

	return(trim($cleaned));
}
	
	if ($emp_or_seek=="seekers")
	{
		$selquery = "SELECT * FROM cvkisisel WHERE eposta='$uniqueID'";
		$selresult = mysqli_query($dbLink, $selquery);
		$varmi = mysqli_num_rows($selresult);
		
		if($varmi > 0) 
		{
			while($row = mysqli_fetch_row($selresult))
			{
				$dogumyeriilce=clean_html($row[25])==""?'':clean_html($row[25]);
			}
		}
	}

	if ($emp_or_seek=="employers")
	{
		$selquery = "SELECT * FROM iskisisel WHERE eposta='$uniqueID'";
		$selresult = mysqli_query($dbLink, $selquery);
		$varmi = mysqli_num_rows($selresult);
		
		if($varmi > 0) 
		{
			while($row = mysqli_fetch_row($selresult))
			{
				$dogumyeriilce=clean_html($row[6])==""?'':clean_html($row[6]);
			}
		}
	}
	

	

	
	
/*	if($dogumyeriilce=clean_html($row[6])=="")
	{
*/		
		$il_id = $_POST["il"];
		$ilcequery = "SELECT * FROM ilce WHERE il_id ='$il_id' ORDER BY isim ASC";
		$result = mysqli_query($dbLink, $ilcequery);

		while($row = $result->fetch_assoc())
		{
			?>
			<option value = "<?php echo $row["ilce_id"]; ?>"><?php echo $row["isim"]; ?></option>
			<?php
		}
/*	}
	else
	{		
		$ilcequery = "SELECT * FROM ilce ORDER BY isim ASC";
		$result = mysqli_query($dbLink, $ilcequery);
	
		while($row = $result->fetch_assoc())
		{
			?>
			<option value = "<?php echo $row["ilce_id"]; ?>" <?php if ($dogumyeriilce=="KEMER") { echo "selected"; } ?>><?php echo $row["isim"]; ?></option>
			<?php
		}
	}*/
?>
