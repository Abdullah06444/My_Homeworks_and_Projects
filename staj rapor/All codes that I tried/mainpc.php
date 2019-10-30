<?PHP

//echo $_POST['sec'];

//$session = isset($_POST['session']) ? $_POST['session'] : '';


//echo $_POST['sec'];
/*
echo "ilk: ";
			echo $sec;
*/
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

include("$server_root/session.php");
include("$server_root/verify_auth.php");
			


			
$selquery="Select logged_in,emp_or_seek from session where ID='$session' ";
$selresult = mysqli_query($dbLink, $selquery);
while($row = mysqli_fetch_row($selresult))
{           
  if($row[0] == "1") 
  {
	$logged_in=1;
	$sec = $row[1];
	/*echo "iki: ";
			echo $sec;*/
  }
  else
  {
	$logged_in=0;
  }
}
	
	
	
if($action == "girisyap") 	
{

	/*echo "uc: ";
			echo $sec;*/
	if ($sec=="seekers")
	{
		$dbtab="jobseeker";
		/*echo "dort: ";
			echo $sec;*/
	}
	else if ($sec=="employers")
	{
	/*echo "bes: ";
			echo $sec;*/
		$dbtab="hrcontact";
	}
	else
	{
		$dbtab="yok";
	}
	
	include("$server_root/web_include/functions/class.rc4crypt.php");
	$selquery = "Select email,password,first from $dbtab where email='$email'";
	$selresult = mysqli_query($dbLink, $selquery);

	//check to see if there are any results from query
	$matches = mysqli_num_rows($selresult);
	if($matches == 0)
	{
		if($email == "")
		{
			$complete="no";
			$badaccountt = "<font color=red>";
		}
		else
		{
			$complete="no";
			$badaccount = "<font color=red>";
		}
	}
	else 
	{
		while($row = mysqli_fetch_row($selresult))
		{

			if(hash('sha512',$password) == $row[1])
			{
				
				/*if($cookie == "1") 
				{*/
					$rc5 = new rc4crypt;
					$enc_email=$rc5->endecrypt($db_password, $row[0], en);
					setcookie("cookie[uniqueID]", "$enc_email", mktime(19,14,07,1,18,2038), "/", ".mojolin.com");
					setcookie("cookie[logged_in]", "1", mktime(19,14,07,1,18,2038), "/", ".mojolin.com");
					setcookie("cookie[emp_or_seek]", "seekers", mktime(19,14,07,1,18,2038), "/", ".mojolin.com");
				//}
				// giriş yaptıktan sonra hemen session database'inde güncelleme yaparak o sessionID'yi kullanıcıya atıyor.
				$insquery = "update session set uniqueID='$row[0]', logged_in = '1', emp_or_seek = '$sec' where ID='$session' ";
				$insresult = mysqli_query($dbLink, $insquery);
				$isim = $row[2];
				header("Location: http://$base_url/index.php?session=$session");
							
			}
			else if($password == "")
			{
				$complete="no";
				$badpasswordd = "<font color=red>";				
			}
			else
			{
				$complete="no";
				$badpassword = "<font color=red>";
			}
		}
	}
}

if($action == "kayitol") 
{
	if ($sec=="seekers")
	{
		$dbtab="jobseeker";
	}
	else if ($sec=="employers")
	{
	/*echo "alti: ";
			echo $sec;*/
		$dbtab="hrcontact";
	/*echo "huop: ";
			echo $dbtab;*/
	}
	//password1 missing
	if($password1 == "") 
	{
		$badpass1 = "<font color=red>";
		$complete = "no"; 
	}

	//password1 missing
	if($password2 == "") 
	{
		$badpass2 = "<font color=red>";
		$complete = "no"; 
	}

	//passwords do not match
	if($password1 != $password2) 
	{
		$badmatch = "<font color=red>";
		$complete = "no"; 
	}
	
	// .,*+- gibi sembollere de izin vermesi için eklemek durumunda kaldım.
	if(!preg_match('/^(?=.*\d)(?=.*[A-Z])(?=.*[a-z])[0-9A-Za-z.,*+-_#]{6,16}$/', $password1))
	{
		$pregmatch = "<font color=red>";
		$complete = "no";
		
	}
	
	
	/*
	
	$selquery = "Select email,password from $dbtab where email='$email'";
	$selresult = mysqli_query($dbLink, $selquery);

	//check to see if there are any results from query
	$matches = mysqli_num_rows($selresult);
	
	if($password1 == $password2)
	{
		row[1] = hash('sha512',$password1);
	}
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	// Email Address already in database
	$selquery = "Select id from $dbtab where email = '$cleaned_email' ";
	$selresult = mysqli_query($dbLink, $selquery);
	$matches = mysqli_num_rows($selresult);
    if($matches > 0)
	{
		$alreadyemail = "<font color=red>";
		$complete = "no"; 
	}

	//Not a real email address
	if(!preg_match("/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+([\.][a-z0-9-]+)+$/i",$cleaned_email)) 
	{
		$bademail = "<font color=red>";
		$complete = "no"; 
	}

    //if (isset($_POST['submit'])) {
        //$username = $_POST['username'];
        $secretKey = "6Lcno2QUAAAAALjCqeiluAiiJXakOFBnQ6lU4QPK";
        $responseKey = $_POST['g-recaptcha-response'];
        $userIP = $_SERVER['REMOTE_ADDR'];

        $url = "https://www.google.com/recaptcha/api/siteverify?secret=$secretKey&response=$responseKey&remoteip=$userIP";
        $response = file_get_contents($url);
        $response = json_decode($response);
	// Everything looks good.
	// Yeni kayıt olanları burada database ekliyor.
		
		if($complete != "no" && $response->success)
		{ 
			$oturum=1;
			
			//insert a row
			$insquery="insert into $dbtab (email,password) values('$cleaned_email','$enc_pass')";
			$insresult = mysqli_query($dbLink, $insquery);

			//update session
			$upquery = "update session set uniqueID='$cleaned_email', logged_in = '1', emp_or_seek = '$sec' where ID='$session' "; 
			$upresult = mysqli_query($dbLink, $upquery);

			//redirect to profile page
			header("Location: http://$base_url/index.php?session=$session");
		}
		else if(!$response->success)
		{
			$badrecaptcha = "<font color=red>";
			$complete = "no";
		}
	//}
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
		//BURASI kayıt olunan yeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeerrrrrrrrrrrrrrrrrrrrrrrrrrr!!!!!!!!!!!!!!!!!!!!!!!!!!!
		include("cvkayit.php");
		
	}
	else if ($emp_or_seek=="employers")
	{
		$dbtab="hrcontact";
		$linkadresi='isveren';
						  
		$selquery = "SELECT * FROM iskredi WHERE eposta='$uniqueID' ";
		$selresult = mysqli_query($dbLink, $selquery);
		$varmi=mysqli_num_rows($selresult);
		if ($varmi > 0) 
		{								
			while($row = mysqli_fetch_assoc($selresult))
			{
				$kredi=$row['bakiye'];
			}
		} else
		{
			$kredi=0;
		}
		//BURASI kayıt olunan yeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeerrrrrrrrrrrrrrrrrrrrrrrrrrr!!!!!!!!!!!!!!!!!!!!!!!!!!!
		include("iskayit.php");
	}

	/*echo "GİRİŞ YAPILDI!!! $dbtab ... ";
	Giriş yapıldıktan sonra kullanıcı adını gösterme*/
	$selquery = "Select * from $dbtab where email = '$uniqueID' ";
	$selresult = mysqli_query($dbLink, $selquery);
	$varmi=mysqli_num_rows($selresult);
	if ($varmi > 0) 
	{		
		while($row = mysqli_fetch_row($selresult))
		{
			$isim=clean_html($row[1])==""?clean_html($row[11]):clean_html($row[1]);

		}
	}
	
}
/*print("  
<p><b><big>Profile for $row[1] $row[2]</big></b><br>
<small><b>link for direct access to resume from other sites:<br>
<font color=$high_text>http://$base_url/search/direct_view.php?email=$uniqueID&id=$resume_id</font></small><br>
<hr>
<b>  First Name: </b> ".clean_html($row[1])."<br>
<b>  Last Name: </b> ".clean_html($row[2])."<br>
<b>  Phone Number: </b> ".clean_html($row[9])." <br>
<b>  Fax Number: </b> ".clean_html($row[10])." <br>
<b>  Email: </b> ".clean_html($row[11])." <br>
<b>  Web Site: </b>".clean_html($row[12])." <br>
<b>  Last Updated: </b>  
\n");
}*/


?>
				

		<nav class="navbar navbar-default main-navbar hidden-sm hidden-xs">
          <div class="container">
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">

              <ul class="nav navbar-nav"><?PHP
			//echo $session;
			/*
			if (mysqli_num_rows($selresult) > 0) 
					{	// output data of each row
						while($row = mysqli_fetch_row($selresult)) 
						{
							echo "log?: " . $row["ID"]. "";
						}
					} else 
					{
						echo "log: 0";
					}
					
				//$logged_in=$row["ID"];
				*/
				$oturum=$logged_in;
			
			?>
			
<?php
			if ($emp_or_seek=="seekers" || $emp_or_seek=="")
			{
?>			
                <li class=""><a href="job_list.php?session=<?PHP echo $session ; ?>"><strong>İş Bul</strong></a></li>
<?php
			}
			if ($emp_or_seek=="employers" || $emp_or_seek=="")
			{
?>
                <li class=""><a href="resume_list.php?session=<?PHP echo $session ; ?>"><strong>Eleman Bul</strong></a></li>
                <li  class=""><a href="job_post_1.php?session=<?PHP echo $session ; ?>"><strong>İlan Ver</strong></a></li>
<?php
			}
?>
                <li class="dropdown">
                  <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" >bilirisi.com <span class="caret"></span></a>
                  <ul class="dropdown-menu" role="menu">
                    <li><a href="about.php?session=<?PHP echo $session ; ?>">Hakkımızda</a></li>
                    <li><a href="contact.php?session=<?PHP echo $session ; ?>">İletişim</a></li>
                    <li><a href="terms_privacy.php?session=<?PHP echo $session ; ?>">Gizlilik &amp; Kullanım</a></li>
                    <li><a href="error_404.php?session=<?PHP echo $session ; ?>">Yardım</a></li>
                  </ul>
                </li>
              </ul>

				<?PHP
				if ($oturum!=1)
				{
				?>
              <ul class="nav navbar-nav navbar-right">
                <li class="link-btn"><a href="login.php?session=<?PHP echo $session ; ?>"><span class="btn btn-theme btn-pill btn-xs btn-line">Giriş</span></a></li>
                <li class="link-btn"><a href="register.php?session=<?PHP echo $session ; ?>"><span class="btn btn-theme  btn-pill btn-xs btn-line">Kayıt</span></a></li>
              </ul>
				<?PHP
				}
				else
				{
				?>
			  <ul class="nav navbar-nav navbar-right">

<?php
				if ($emp_or_seek=="employers")
				{
?>
				<li class="link-btn"><a href="kredial.php?session=<?PHP echo $session ; ?>"><span class="btn btn-theme btn-success btn-pill btn-xs">Krediniz: <?php echo $kredi; ?></span></a></li>
<?php                
				}
				
				// 426. line sayesinde kaydedilen resimler yukarıda da gözükebiliyor.
?>
				<li class="dropdown">
                  <a href="job_post_1.html#" class="link-profile dropdown-toggle" data-toggle="dropdown">
                    <img src="resimyukle/resimup/upload.php?session=<?PHP echo $session ; ?>&s=f" alt="" class="img-profile"> &nbsp; 
					<?PHP
					echo "".$isim."" ;
					/*$selquery = "Select * from jobseeker where email = '$email' ";
					$selresult = mysqli_query($dbLink, $selquery);

					while($row = mysqli_fetch_row($selresult))
					{
							echo "".clean_html($row[1])."" ;
							echo "".clean_html($row[11])."" ;
						if (clean_html($row[1])=="")
						{
							echo "B".clean_html($row[11])."" ;
						}
						else
						{
							echo "A".clean_html($row[1])."" ;
						}
					}*/
					?>				
					<b class="caret"></b>
                  </a>
                  <ul class="dropdown-menu" role="menu">
                    <li><a href="<?php echo $linkadresi; ?>.php?session=<?PHP echo $session ; ?>&page=myalerts"> Bildirimler </a></li>
                    <li><a href="<?php echo $linkadresi; ?>.php?session=<?PHP echo $session ; ?>&page=notifications"> Mesajlar <span id="mesajsay" class="badge "></span></a></li>
                    <li><a href="<?php echo $linkadresi; ?>.php?session=<?PHP echo $session ; ?>&page=change_password"> Şifre Değiştir</a></li>
                  </ul>
                </li>
                <li class="link-btn"><a href="logout.php?session=<?PHP echo $session ; ?>"><span class="btn btn-theme  btn-pill btn-xs btn-line">Çıkış</span></a></li>
              </ul>
				<?PHP
				}
				
				?>
			  
            </div>
          </div>
        </nav>