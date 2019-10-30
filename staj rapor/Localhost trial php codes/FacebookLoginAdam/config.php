<?php
	session_start();

	require_once "Facebook/autoload.php";

	$FB = new \Facebook\Facebook([
		'app_id' => '1300470206756579',
		'app_secret' => '3e84b8e0979518f375ee7bea88286943',
		'default_graph_version' => 'v3.10'
	]);

	$helper = $FB->getRedirectLoginHelper();
?>