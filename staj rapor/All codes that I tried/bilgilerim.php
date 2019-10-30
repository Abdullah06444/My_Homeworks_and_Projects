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

	if(isset($session))
	{

		$selquery = "select uniqueID,logged_in,emp_or_seek,hrcontact_id from session where ID='$session' ";
		$selresult = mysqli_query($dbLink,$selquery);

		while($row = mysqli_fetch_row($selresult))
		{
			$uniqueID=$row[0];
			$logged_in=$row[1];
			$emp_or_seek=$row[2];
			$hrcontact_id=$row[3];
		}
		/*
		@$selquery = "select search_resumes from hrcontact where email='$uniqueID' ";
		$selresult = mysqli_query($dbLink,$selquery);

		while($row = mysqli_fetch_row($selresult))
		{
			$search_resumes=$row[0];
		} 
		*/
	}


	if ($logged_in==1)
	{

		if ($emp_or_seek=="seekers")
		{
			$dbtab="jobseeker";
			$linkadresi='calisan';
		}
		else if ($emp_or_seek=="employers")
		{
			$dbtab="hrcontact";
			$linkadresi='isveren';
		}

		//echo "GİRİŞ YAPILDI!!! $dbtab ... ";
		$selquery = "Select * from $dbtab where email = '$uniqueID' ";
		$selresult = mysqli_query($dbLink, $selquery);

		while($row = mysqli_fetch_row($selresult))
		{
			$isim=clean_html($row[1])==""?clean_html($row[11]):clean_html($row[1]);
			//$soyisim=clean_html($row[2])==""?'':clean_html($row[2]);
			/*
			echo $row[1];
			echo $row[2];
			echo $row[3];
			//echo $row[4];
			echo $row[5];
			echo $row[6];
			echo $row[7];
			echo $row[8];
			echo $row[9];
			echo $row[10];
			echo $row[11];
			echo $row[12];
			echo $row[13];
			echo $row[14];
			echo $row[15];
			echo $row[16];
			echo $row[17];
			echo $row[18];
			echo $row[19];
			echo $row[20];
			echo $row[21];*/
		}

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
				$eposta=clean_html($row[0])==""?'':clean_html($row[0]);
				$isim=clean_html($row[1])==""?'':clean_html($row[1]);
				$soyisim=clean_html($row[2])==""?'':clean_html($row[2]);
				$dogumyeri=clean_html($row[3])==""?'':clean_html($row[3]);
				$dogumtarihi=clean_html($row[4])==""?'':clean_html($row[4]);
				$cinsiyet=clean_html($row[5])==""?'':clean_html($row[5]);
				$dogumyeriilce=clean_html($row[25])==""?'':clean_html($row[25]);
			}
		}
		$a1='İsim';
		$a2='Soyisim';
		$a3='Doğum Yeri';
		$a5='Doğum Yeri İlçe';
		$a4='Doğum Tarihi';
		$b1='İsminizi yazın';
		$b2='Soyisminizi yazın';
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
				$eposta=clean_html($row[1])==""?'':clean_html($row[1]);
				$isim=clean_html($row[2])==""?'':clean_html($row[2]);
				$soyisim=clean_html($row[3])==""?'':clean_html($row[3]);
				$dogumyeri=clean_html($row[4])==""?'':clean_html($row[4]);
				$dogumtarihi=clean_html($row[5])==""?'':clean_html($row[5]);
				$dogumyeriilce=clean_html($row[6])==""?'':clean_html($row[6]);
			}
		}
		$a1='Firma İsmi';
		$a2='Firma Sektörü';
		$a3='Bulunduğu Bölge';
		$a5='Bulunduğu Bölgenin İlçesi';
		$a4='Kuruluş Yılı';
		$b1='Firma ismini yazın';
		$b2='Firma sektörünü yazın';
	}

	$ilquery = "SELECT * FROM il ORDER BY isim ASC";
	$result = mysqli_query($dbLink, $ilquery);
	
?>
			
			
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/xhtml">
<html xmlns="http://www.w3.org/xhtml" xml:lang="en">

<head>

			<script src = "http://code.jquery.com/jquery-1.7.1.min.js" type = "text/javascript"></script>
			<script type = "text/javascript">
				$(document).ready(function()
				{

					$("#il").change(function(){

						var il_id = $(this).val();

						$.ajax({

						type : "POST",
						url : "ajaxililce.php",
						data : {"il":il_id},// burası seçtikten sonra kutuda göstermeye yarıyor

							success:function(e)
							{
								$("#ilce").show();
								$("#ilce").html(e);
							}
						})
					});
				});
			</script>
</head>

<body>

	<h3 class="no-margin-top">Kişisel Bilgilerim</h3>
	<hr>
		<div class="row">
			<div class="col-xs-12">
				<form ACTION ="<?PHP echo $linkadresi.".php?session=".$session."" ?>" METHOD="POST">
				
				<div class="col-xs-6">
					<label><?PHP echo $a1; ?></label>
					<input name="isim" type="text" class="form-control" placeholder="<?PHP echo $b1; ?>" value="<?php echo $isim; ?>">
				</div>

				<div class="col-xs-6">
					<label><?PHP echo $a2; ?></label>
					<input name="soyisim" type="text" class="form-control" placeholder="<?PHP echo $b2; ?>" value="<?php echo $soyisim; ?>">
				</div>
				
				<div class="col-xs-6">
					<label><?PHP echo $a3; ?></label>
					<select id = "il" name="dogumyeri" type="text" class="form-control">
						<?php
								while($row = $result->fetch_assoc())
								{
						?>
									<option value = "<?php echo $row["il_id"]; ?>" <?php if ($row["isim"]==$dogumyeri) { echo "selected"; } ?>><?php echo $row["isim"]; ?></option>
						<?php
								}
						?>
						
					</select>
				</div>
			
				<div class="col-xs-6">
					<label><?PHP echo $a5; ?></label>
					<select id = "ilce" name="dogumyeriilce" type="text" class="form-control">

						<?php
						
							if($dogumyeriilce != "")
							{
								
								$ilidquery = "SELECT il_id FROM il WHERE isim='$dogumyeri'";
								$result = mysqli_query($dbLink, $ilidquery);

								while($row = $result->fetch_assoc())
								{
										
									$selquery = "SELECT * FROM ilce WHERE il_id='".$row["il_id"]."'";
									$result = mysqli_query($dbLink, $selquery);
								
									while($row = $result->fetch_assoc())
									{
						?>
										<option value = "<?php echo $row["ilce_id"]; ?>" <?php if ($row["isim"]==$dogumyeriilce) { echo "selected"; } ?>><?php echo $row["isim"]; ?></option>						
						<?php
									}
								}
							}
						?>
					</select>				
				</div>

				<div class="col-xs-6">
					<label><?PHP echo $a4; ?></label>
					<input name="dogumtarihi" type="date" class="form-control" placeholder="GG.AA.YYYY" value="<?php echo $dogumtarihi; ?>">
				</div>

				<div class="col-xs-6">
					<?php 
					if ($emp_or_seek=="seekers")
					{

					?>
						<label>Cinsiyet</label>
						
						<center class="text-center">
							<div class="row">
								<div class="radio flat-radio">
									<div class="col-xs-3">
										<label>
										<input type="radio" name="cinsiyet" onclick="myFunction()" value="Kadın" <?php if($cinsiyet == "Kadın"){?> checked <?php } ?> /> 
										<span class="fa fa-check"></span>
										Kadın
									</label>
								</div>


								<div class="col-xs-3">
									<label>
										<input type="radio" name="cinsiyet" onclick="myFunction()" value="Erkek" <?php if($cinsiyet == "Erkek"){?> checked <?php } ?> /> 
										<span class="fa fa-check"></span>
										Erkek
									</label>
									</div> 
								</div>
							</div>
						</center>

					<?php					
					}
					?>
				</div>


					<div class="col-xs-6">
						<br>
						<button name="action" value="cvbilgikaydet" type="submit"  class="btn btn-theme btn-t-primary btn-md btn-block">KAYDET</button>
					</div>
				</form>
			</div>
		</div>
		
	</body>

</html>