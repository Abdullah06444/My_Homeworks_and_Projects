<?PHP



$session = isset($_GET['session']) ? $_GET['session'] : '';
date_default_timezone_set('Europe/Istanbul');

// Redirect from mojolin.com to www.mojolin.com
	if (getenv("HTTP_HOST") == "mojolin.com") {
		Header("Location: http://www.mojolin.com" . getenv("REQUEST_URI"));
	}

/*
Demonstration of using session identifiers
*/

	function SessionID($length=12)
	{
			// Set pool of possible characters
			$Pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			$Pool .= "abcdefghijklmnopqrstuvwxyz";
			$lastChar = strlen($Pool) - 1;

			// rastgele session ID uretilen kisim
			for($i = 0; $i < $length; $i++)
			{
					@$sid .= $Pool[mt_rand(0, $lastChar)];
			}
	
			return($sid);
	}

	//Seed the generator
	mt_srand((double)microtime()*100000000.00);

	//connect to server, then test for failure
	if(!($dbLink = mysqli_connect("$db_server", "$db_user", "$db_password")))
	{
			print("Failed to connect to database!<BR>\n");
			print("Aborting!<BR>\n");
			exit();
	}
 
	//select database, then test for failure
	if(!mysqli_select_db($dbLink,$primary_db))
	{
			print("Can't use the test database!<BR>\n");
			print("Aborting!<BR>\n");
			exit();
	}

$sql = "SELECT LastAction, logged_in, ID FROM session";
$result = mysqli_query($dbLink,$sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
		
		if($row["logged_in"] == 1)
		{	
			// Başkası bizi sisteme girip silmesin diye refresh yapılmalı.
			// Yenilemeyi direk otomatik yapabilmeli yarım saatte bir
			//echo "<br> if koşulu ". $template . " --> " . $row["LastAction"] . "<br>";
			/*?>
			<meta http-equiv="refresh" content="20;URL='<?php echo $_SERVER['PHP_SELF']?>'">
			<?php*/
			//refresh kullanımları
			//header("Refresh: 10; url=http://bilirisi.com/index.php?session=" . $row["ID"] ."");
			//header("Refresh: 10; url='"window.location.reload()."'");
			header("Refresh: 1740; url=http://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]");
		}
    }
}


	

	//check session
	if(isset($session))
	{
		//we have a session, so check it
		$Query = "SELECT ID,LastAction ";
		$Query .= "FROM session ";
		$Query .= "WHERE ID='" . addslashes($session) . "' ";

			if(!($dbResult = mysqli_query($dbLink, $Query)))
			{
					//can't execute query
					print("Couldn't query session table!<BR>\n");
					print("MySQL Reports: " . mysqli_error() . "<BR>\n");
					exit();
			}

		//if we have a row, then the match succeeded
		if(mysqli_num_rows($dbResult))
		{
				//session exists, update last action
				$Query = "UPDATE session ";
				$Query .= "SET LastAction = now() ";
				$Query .= "WHERE ID='$session' ";
				if(!($dbResult = mysqli_query($dbLink, $Query)))
				{
						//can't execute query
						print("Couldn't update session table!<BR>\n");
						print("MySQL Reports: " . mysqli_error() . "<BR>\n");
						exit();
				}
		}
		else
		{

			//no session, so create one
			$session = SessionID(12);
			include("$server_root/web_include/functions/class.rc4crypt.php");

			$cookie['uniqueID'] = isset($cookie) ? $cookie['uniqueID'] : '';

			//if cookie is saved in clear text, encrypt and reset
			if(preg_match("/@/",$cookie['uniqueID'],$matches)) {
				$rc4 = new rc4crypt;
				$enc_email=$rc4->endecrypt($db_password, $cookie[uniqueID], en);
				setcookie("cookie[uniqueID]", "$enc_email", mktime(19,14,07,1,18,2038),"/", ".mojolin.com");
						
				//insert session to database
				$Query = "INSERT INTO session (ID,LastAction,uniqueID,logged_in,emp_or_seek) VALUES ('$session', now(),'$cookie[uniqueID]','$cookie[logged_in]','$cookie[emp_or_seek]') ";
			} 

			//if cookie is already encrypted, just enter into database
			else {
				$rc5 = new rc4crypt;
				$dec_email=$rc5->endecrypt($db_password, $cookie['uniqueID'], 'de');

				$cookie['logged_in'] = isset($cookie['logged_in']) ? $cookie['logged_in'] : '';
				$cookie['emp_or_seek'] = isset($cookie['emp_or_seek']) ? $cookie['emp_or_seek'] : '';
	  
				//insert session to database
				$Query = "INSERT INTO session (ID,LastAction,uniqueID,logged_in,emp_or_seek) VALUES ('$session', now(),'$dec_email','$cookie[logged_in]','$cookie[emp_or_seek]') ";
			}

			if(!($dbResult = mysqli_query($dbLink, $Query)))
			{
				//can't execute query
				print("Couldn't insert into session table!<BR>\n");
				print("MySQL Reports: " . mysqli_error() . "<BR>\n");
				exit();
			}
		}
	}

	//if session is empty, we need to create it
	if(@$session == "")
	{

		//no session, so create one
		$session = SessionID(12);
		include("$server_root/web_include/functions/class.rc4crypt.php");
		
		//if cookie is saved in clear text, encrypt and reset
		if(preg_match("/@/",@$cookie[uniqueID],$matches)) {
			$rc4 = new rc4crypt;
			$enc_email=$rc4->endecrypt($db_password, $cookie[uniqueID], 'en');
			setcookie("cookie[uniqueID]", "$enc_email", mktime(19,14,07,1,18,2038),"/", ".mojolin.com");
						
			//insert session to database
			$Query = "INSERT INTO session (ID,LastAction,uniqueID,logged_in,emp_or_seek) VALUES ('$session', now(),'$cookie[uniqueID]','$cookie[logged_in]','$cookie[emp_or_seek]') ";
		} 

		//if cookie is already encrypted, just enter into database
		else {
			$rc5 = new rc4crypt;
			$dec_email=$rc5->endecrypt($db_password, @$cookie[uniqueID], 'de');
			
			//insert session to database
			@$Query = "INSERT INTO session (ID,LastAction,uniqueID,logged_in,emp_or_seek) VALUES ('$session', now(),'$dec_email','$cookie[logged_in]','$cookie[emp_or_seek]') ";
		}

		if(!($dbResult = mysqli_query($dbLink,$Query)))
		{
			//can't execute query
			print("Couldn't insert into session table!<BR>\n");
			print("MySQL Reports: " . mysql_error() . "<BR>\n");
			exit();
		}
	}
		
	//clear out any old sessions
	$Query = "DELETE FROM session ";
	$Query .= "WHERE LastAction < '"; // Çıkış yaptıktan sonra sessiondan logged-out yapıyor.
	// time()-x second   x saniye içerisinde giriş yapmazsa sessionID değişiyor ve oturumu siliyor kapatıyor.
	$Query .= date("Y-m-d H:i:s", (time()-1800));
	$Query .= "'";
	
	if(!($dbResult = mysqli_query($dbLink,$Query)))
	{
			//can't execute query
			print("Couldn't remove old sessions!<BR>\n");
			print("MySQL Reports: " . mysqli_error() . "<BR>\n");
			exit();
	}
?>

