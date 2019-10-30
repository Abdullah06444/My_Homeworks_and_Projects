<?PHP include("mojolin_globals.php");
include("$server_root/generate_passwd.php");

//open connection
$dbLink = mysqli_connect($db_server, $db_user, $db_password);

//open monster database
mysqli_select_db($dbLink, $primary_db);


$cleaned_email=strtolower($email);
$salt = genpassword(2);

	// kaydın tamamlanması degil sadece yeni kayıt olanın şifresinin gerekli kurallara uymasını gösteren kısım
	if(preg_match('/^(?=.*\d)(?=.*[A-Z])(?=.*[a-z])[0-9A-Za-z.,*+-_#]{6,16}$/', $password1)) {
			
		$enc_pass=hash('sha512',$password1);// Ben çözdüm olayı! :D crypt($password1,$salt);
	}	
	
?>

<!DOCTYPE html>
<!-- saved from url=(0055)register.html -->
<html lang="en"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <?PHP include("head.php"); ?>
  <script type="text/javascript" charset="UTF-8" src="dosyalar/common.js"></script><script type="text/javascript" charset="UTF-8" src="dosyalar/util.js"></script><script type="text/javascript" charset="UTF-8" src="dosyalar/stats.js"></script><script type="text/javascript" charset="UTF-8" src="dosyalar/AuthenticationService.Authenticate"></script></head>  
  
  <body>
    <!-- wrapper page -->
    <div class="wrapper">
      <!-- main-header -->
      <header class="main-header">


        <!-- main navbar -->
        <?PHP include("mainpc.php"); ?>
		<!-- end main navbar -->

        <!-- mobile navbar -->
        <?PHP include("mainmobil.php"); ?>
		<!-- end mobile navbar -->

		<?PHP include("ustbaslik.php"); ?>
       

      </header>
	  <!-- end main-header -->


      <!-- body-content -->
      <div class="body-content clearfix">

	  
        <?PHP include("kayitbolme1.php"); ?>
        <?PHP include("kayitbolme2.php"); ?>

        <!-- modal password criteria -->
			<?PHP include("sifrekriterleri.php"); ?>
		<!-- end modal password criteria -->  
		
      </div><!--end body-content -->


      <!-- main-footer -->
      <?PHP include("footer.php"); ?>
	  <!-- end main-footer -->

    </div><!-- end wrapper page -->

	<?PHP include("scriptler.php"); ?>

</body></html>