<?php
/*
include("mojolin_globals.php");
//open connection
$dbLink = mysqli_connect($db_server, $db_user, $db_password);

//open monster database
mysqli_select_db($dbLink, $primary_db);
*/


	$action = 			isset($_POST['action']) ? $_POST['action'] : '';

	if ($action=="iskaydet" || $action=="isyayinla")
	{

		$ilan_isim = 			isset($_POST['ilan_isim']) ? $_POST['ilan_isim'] : '';
		$ilan_sektor = 			isset($_POST['ilan_sektor']) ? $_POST['ilan_sektor'] : '';
		$ilan_ililce = 			isset($_POST['ilan_ililce']) ? $_POST['ilan_ililce'] : '';
		$ilan_kurulus = 		isset($_POST['ilan_kurulus']) ? $_POST['ilan_kurulus'] : '';
		$ilan_baslik = 			isset($_POST['ilan_baslik']) ? $_POST['ilan_baslik'] : '';
		$ilan_yetenek = 		isset($_POST['ilan_yetenek']) ? $_POST['ilan_yetenek'] : '';
		$ilan_tanim = 			isset($_POST['ilan_tanim']) ? $_POST['ilan_tanim'] : '';
		$ilan_depart =	 		isset($_POST['ilan_depart']) ? $_POST['ilan_depart'] : '';
		$ilan_poz = 			isset($_POST['ilan_poz']) ? $_POST['ilan_poz'] : '';
		$ilan_tip = 			isset($_POST['ilan_tip']) ? $_POST['ilan_tip'] : '';
		$ilan_acikla = 			isset($_POST['content']) ? $_POST['content'] : '';
		$ilan_cinsiyet = 		isset($_POST['ilan_cinsiyet']) ? $_POST['ilan_cinsiyet'] : '';
		$ilan_askerlik = 		isset($_POST['ilan_askerlik']) ? $_POST['ilan_askerlik'] : '';
		$ilan_egit = 			isset($_POST['ilan_egit']) ? $_POST['ilan_egit'] : '';
		$ilan_tecrubeyil = 		isset($_POST['ilan_tecrubeyil']) ? $_POST['ilan_tecrubeyil'] : '';
		$ilan_tecrube = 		isset($_POST['ilan_tecrube']) ? $_POST['ilan_tecrube'] : '';
		$ilan_ucretperiyod = 	isset($_POST['ilan_ucretperiyod']) ? $_POST['ilan_ucretperiyod'] : '';
		$ilan_ucret = 			isset($_POST['ilan_ucret']) ? $_POST['ilan_ucret'] : '';
		$ilan_ileteposta = 		isset($_POST['ilan_ileteposta']) ? $_POST['ilan_ileteposta'] : '';
		$ilan_uniqueID = 		isset($_POST['ilan_id']) ? $_POST['ilan_id'] : '';

		$ilan_uniqueID = 		$ilan_uniqueID=='' ? md5(uniqid(mt_rand(), true)) : $ilan_uniqueID;



		echo "burdayız";

		$selquery = "SELECT eposta FROM isilanlar WHERE eposta='$uniqueID' AND ilan_uniqueID='$ilan_uniqueID'";
		$selresult = mysqli_query($dbLink, $selquery);
		$varmi = mysqli_num_rows($selresult);
		if($varmi > 0) 
		{
			while($row = mysqli_fetch_row($selresult))
			{
				
				echo "burdayız da";
				$ilan_yayintarih=$row['ilan_yayintarih'];
				$ilan_yayinson=$row['ilan_yayinson'];
				$ilan_yayindami=$row['ilan_yayindami'];
				
			}
			echo $ilan_yayintarih;
			echo $ilan_yayintarih;
			echo $ilan_yayintarih;
			
			if ($ilan_yayindami==0 && $action=="isyayinla")
			{
				
				echo "burdayız ayrıca";
				$ilan_yayintarih=date('Y-m-d H:i:s');
				$ilan_yayinson=date('Y-m-d H:i:s', (time()+2592000));
				$ilan_yayindami=1;
			}
			$upquery = "UPDATE isilanlar SET "
			."ilan_isim='$ilan_isim', ilan_sektor='$ilan_sektor', ilan_ililce='$ilan_ililce', "
			."ilan_kurulus='$ilan_kurulus', ilan_baslik='$ilan_baslik', ilan_yetenek='$ilan_yetenek', "
			."ilan_tanim='$ilan_tanim', ilan_depart='$ilan_depart', ilan_poz='$ilan_poz', "
			."ilan_tip='$ilan_tip', ilan_acikla='$ilan_acikla', ilan_cinsiyet='$ilan_cinsiyet', "
			."ilan_askerlik='$ilan_askerlik', ilan_egit='$ilan_egit', ilan_tecrubeyil='$ilan_tecrubeyil', "
			."ilan_tecrube='$ilan_tecrube', ilan_ucretperiyod='$ilan_ucretperiyod', ilan_ucret='$ilan_ucret', "
			."ilan_ileteposta='$ilan_ileteposta', ilan_yayintarih='$ilan_yayintarih', ilan_yayinson='$ilan_yayinson', "
			."ilan_yayindami='$ilan_yayindami' "
			."WHERE eposta='$uniqueID' AND ilan_uniqueID='$ilan_uniqueID' "; 
			$upresult = mysqli_query($dbLink, $upquery);
		}
		else
		{
			
			echo "bura da olur";
			if ($action=="isyayinla")
			{
				
				echo "burdayız ayrıcanak";
				$ilan_yayintarih=date('Y-m-d H:i:s');
				$ilan_yayinson=date('Y-m-d H:i:s', (time()+2592000));
				$ilan_yayindami=1;
			}
			
			$insquery="INSERT INTO isilanlar "
			."(eposta,ilan_isim,ilan_sektor,ilan_ililce,ilan_kurulus,ilan_baslik,"
			."ilan_yetenek,ilan_tanim,ilan_depart,ilan_poz,ilan_tip,ilan_acikla,"
			."ilan_cinsiyet,ilan_askerlik,ilan_egit,ilan_tecrubeyil,ilan_tecrube,"
			."ilan_ucretperiyod,ilan_ucret,ilan_ileteposta,"
			."ilan_yayintarih,ilan_yayinson,ilan_yayindami,ilan_uniqueID) "
			."VALUES('$uniqueID','$ilan_isim','$ilan_sektor','$ilan_ililce',"
			."'$ilan_kurulus','$ilan_baslik','$ilan_yetenek','$ilan_tanim','$ilan_depart',"
			."'$ilan_poz','$ilan_tip','$ilan_acikla','$ilan_cinsiyet','$ilan_askerlik','$ilan_egit',"
			."'$ilan_tecrubeyil','$ilan_tecrube','$ilan_ucretperiyod','$ilan_ucret','$ilan_ileteposta',"
			."'$ilan_yayintarih','$ilan_yayinson','$ilan_yayindami','$ilan_uniqueID') ";
			$insresult = mysqli_query($dbLink, $insquery);
		}
	}
	/* bilgilerim.php de button tuşu action="cvbilgikaydet" olduğu için*/
	else if ($action=="cvbilgikaydet")
	{
		//$uniqueID= 	isset($_POST['ilet_eposta']) ? $_POST['ilet_eposta'] : '';
		
		$isim = 				isset($_POST['isim']) ? $_POST['isim'] : '';
		$soyisim = 				isset($_POST['soyisim']) ? $_POST['soyisim'] : '';
		$dogumyeri = 			isset($_POST['dogumyeri']) ? $_POST['dogumyeri'] : '';
		$dogumtarihi = 			isset($_POST['dogumtarihi']) ? $_POST['dogumtarihi'] : '';
		$dogumyeriilce = 		isset($_POST['dogumyeriilce']) ? $_POST['dogumyeriilce'] : '';
		
		
		$selquery = "SELECT eposta FROM iskisisel WHERE eposta='$uniqueID'";
		$selresult = mysqli_query($dbLink, $selquery);
		$varmi = mysqli_num_rows($selresult);
		
		
	$ilquery = "SELECT * FROM il ORDER BY isim ASC";
	$result = mysqli_query($dbLink, $ilquery);	
	
	while($row = $result->fetch_assoc())
	{
	
		//dogumyeri = il_id ise dogumyeri = il olsun diyelim
		if($dogumyeri == $row["il_id"])
		{
			
			$dogumyeri = $row["isim"];
		}
	}
	
	$ilcequery = "SELECT * FROM ilce ORDER BY isim ASC";
	$result = mysqli_query($dbLink, $ilcequery);	
	
	while($row = $result->fetch_assoc())
	{
		//dogumyeriilce = ilce_id ise dogumyeriilce = ilce olsun diyelim
		if($dogumyeriilce == $row["ilce_id"])
		{
			
			$dogumyeriilce = $row["isim"];
		}
	}
		
		
		
		
		
		
		
		
		if($varmi > 0) 
		{
			$upquery = "UPDATE iskisisel SET is_isim='$isim', is_sektor='$soyisim', is_bolge='$dogumyeri', is_tarih='$dogumtarihi', is_bolge_ilce='$dogumyeriilce' WHERE eposta='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);

			$upquery = "UPDATE $dbtab SET first='$isim', last='$soyisim', bulunduguil='$dogumyeri', kurulusyili='$dogumtarihi', bulunduguilce='$dogumyeriilce' WHERE email='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);

		}
		else
		{
			$insquery="INSERT INTO iskisisel (eposta, is_isim, is_sektor, is_bolge, is_tarih, is_bolge_ilce) VALUES('$uniqueID','$isim','$soyisim','$dogumyeri','$dogumtarihi', '$dogumyeriilce')";
			$insresult = mysqli_query($dbLink, $insquery);

			$upquery = "UPDATE $dbtab SET first='$isim', last='$soyisim', bulunduguil='$dogumyeri', kurulusyili='$dogumtarihi', bulunduguilce='$dogumyeriilce' WHERE email='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);	
		}

	}

/*
<?php
date_default_timezone_set('Europe/Istanbul'); ('UTC') ('GMT') de yazılabilir

$betik_zd = date_default_timezone_get();
//ini_set('date.timezone')="Europe/Istanbul";
if (strcmp($betik_zd, ini_get('date.timezone'))){
    echo 'Betik zaman dilimi ini dosyasında belirtilenden farklı.';
    echo ini_get('date.timezone');
	echo ' ayarladığımız: ';
    echo $betik_zd;
} else {
    echo 'Betik zaman dilimi ini dosyasında belirtilenle aynı.';
}
?> now: <?php echo date('Y-m-d H:i:s', (time()+2592000)); ?>

				 tz: <?php echo date('Y-m-d H:i:s'); ?> 
*/
?>
	