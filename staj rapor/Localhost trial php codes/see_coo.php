<?php
	session_start();

	try{
		
		$db = new PDO("mysql:hostname=localhost; dbname=deneme;", 'root', '');
	}
	catch(PDOException $e){
		
		die($e->getMessage());
	}

?>

<!DOCTYPE html>

<html lang="en-US">

	<head>
	
		<meta charset = "UTF-8">
		<title>PHP Remember Me</title>
	</head>
	
	<body>
		
		<?php
			if(isset($_COOKIE["giris"]) && !isset($_SESSION["login"])){
				$login = (array) json_decode($_COOKIE["giris"]);
				$kadi = $login["kadi"];
				$sifre = $login["sifre"];
				print_r($login);
				$query = $db->query("SELECT * FROM users WHERE fname = '$kadi' && lname = '$sifre'");
					$count = $query->rowCount();
					if($count){
					$row = $query->fetch(PDO::FETCH_ASSOC);
					$_SESSION["login"] = true;
					$_SESSION["adsoyad"] = $row["fname"];
					header("Location : see_coo.php");
				}
			}
			
			
			
			
			
			
			
			if(isset($_SESSION["login"])){
		?>
				Hoşgeldin<b><?=$_SESSION["adsoyad"]?></b>
		<?php
			}
			else{
				
				if($_POST){
					$kadi = $_POST["kadi"];
					$sifre = $_POST["sifre"];
					$hatirla = @$_POST["hatirla"];
					$query = $db->query("SELECT * FROM users WHERE fname = '$kadi' && lname = '$sifre'");
					$count = $query->rowCount();
					if($count){
						$row = $query->fetch(PDO::FETCH_ASSOC);
						$_SESSION["login"] = true;
						$_SESSION["adsoyad"] = $row["fname"];
						if($hatirla == '1'){
							$login = array("kadi" => $row["fname"], "sifre" => $row["lname"]);
							$login = json_encode($login);
							setcookie("giris", $login, time() + 30);
						}
						header("Location : see_coo.php");
					}
				}
		?>
				<form action = "" method = "POST">
					Kullanıcı Adı : <input type = "text" name = "kadi"/><br/>
					Şifre		  : <input type = "password" name = "sifre"/><br/>
					<input type = "checkbox" name = "hatirla" value = "1"/>Beni Hatırla<br/>
					<input type = "submit" value = "Giriş Yap"/>
				</form>
		<?php
			}
		?>
		
	</body>

</html>