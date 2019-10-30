<?php
	
	// cookie oluşturma +
	//sitelerin kendi tarayıcımızda bilgilerimizi tutmamıza yarayan araç
	setcookie("cerez", "abdullah", (time() + 4));
	echo $_COOKIE['cerez'] . "</br>";
	
	// cookie silme -
	setcookie("cerez", "raif", (time() + 8));
	
	// cookie kullanımı
	echo $_COOKIE['cerez'] . "</br>";


	setcookie("cerezz", "baki");
	echo $_COOKIE['cerezz'] . "</br>";
	
	if(isset($_COOKIE['cerezz'])){ echo "cookie var " . $_COOKIE['cerezz'] . "</br>"; }
	else{ echo "cookie yok </br>"; }
	
	session_start();
	$_SESSION['username'] = "mert";
	echo $_SESSION['username'] . "</br>";
	
	if(isset($_SESSION['username'])){ echo "session var " . $_SESSION['username'] . "</br>"; }
	else{ echo "session yok </br>"; }
	
	unset($_SESSION['username']);
	echo $_SESSION['username'] . "</br>";
	
	print_r($_COOKIE);

	
?> 