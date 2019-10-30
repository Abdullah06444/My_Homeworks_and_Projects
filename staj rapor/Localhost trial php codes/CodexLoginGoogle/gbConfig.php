<?php
session_start();

//Include Google client library 
include_once 'src/Google_Client.php';
include_once 'src/contrib/Google_Oauth2Service.php';

/*
 * Configuration and setup Google API
 */
$clientId = '916014209896-1ep93238n7cgspncd0rqglc3uk0hj0rv.apps.googleusercontent.com';
$clientSecret = 'lmhg6lR079pvd8AmJxMsz8Hl';
$redirectURL = 'http://localhost/CodexLoginGoogle/';

//Call Google API
$gClient = new Google_Client();
$gClient->setApplicationName('Login to Devri');
$gClient->setClientId($clientId);
$gClient->setClientSecret($clientSecret);
$gClient->setRedirectUri($redirectURL);

$google_oauthV2 = new Google_Oauth2Service($gClient);
?>