<?php
	session_start();
	require_once "GoogleAPI/vendor/autoload.php";
	$gClient = new Google_Client();
	$gClient->setClientId("276309437617-5jqe570rmsai0jnd21s1u44h94ncuc9h.apps.googleusercontent.com");
	$gClient->setClientSecret("aWR1vPaMfIeMW9TxJGiavgqR");
	$gClient->setApplicationName("CPI Login Tutorial");
	$gClient->setRedirectUri("http://localhost/GoogleLoginAdam/g-callback.php");
	$gClient->addScope("https://www.googleapis.com/auth/plus.login https://www.googleapis.com/auth/userinfo.email");
?>
