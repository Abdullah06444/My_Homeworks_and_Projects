<?php
/*
include("mojolin_globals.php");
//open connection
$dbLink = mysqli_connect($db_server, $db_user, $db_password);

//open monster database
mysqli_select_db($dbLink, $primary_db);
*/


$action = 			isset($_POST['action']) ? $_POST['action'] : '';

	if ($action=="cvkaydet")
	{
	//$uniqueID= 	isset($_POST['ilet_eposta']) ? $_POST['ilet_eposta'] : '';

	$siratecrube = 		isset($_POST['siratecrube']) ? $_POST['siratecrube'] : '';
	$siraegitim = 		isset($_POST['siraegitim']) ? $_POST['siraegitim'] : '';
	$siradil = 			isset($_POST['siradil']) ? $_POST['siradil'] : '';
	$sirasert = 		isset($_POST['sirasert']) ? $_POST['sirasert'] : '';
	$siraref = 			isset($_POST['siraref']) ? $_POST['siraref'] : '';
	$siraekleme = 		isset($_POST['siraekleme']) ? $_POST['siraekleme'] : '';


	$kisi_askerlik = 	isset($_POST['kisi_askerlik']) ? $_POST['kisi_askerlik'] : '';
	$kisi_tarih = 		isset($_POST['kisi_tarih']) ? $_POST['kisi_tarih'] : '';
	$kisi_medeni = 		isset($_POST['kisi_medeni']) ? $_POST['kisi_medeni'] : '';
	$kisi_surucu = 		isset($_POST['kisi_surucu']) ? $_POST['kisi_surucu'] : '';
	$kisi_seyahat = 	isset($_POST['kisi_seyahat']) ? $_POST['kisi_seyahat'] : '';
	$kisi_engel = 		isset($_POST['kisi_engel']) ? $_POST['kisi_engel'] : '';
	$kisi_saglik = 		isset($_POST['kisi_saglik']) ? $_POST['kisi_saglik'] : '';
	$kisi_problem = 	isset($_POST['kisi_problem']) ? $_POST['kisi_problem'] : '';
	$kisi_il = 			isset($_POST['kisi_il']) ? $_POST['kisi_il'] : '';
	$kisi_ilce = 		isset($_POST['kisi_ilce']) ? $_POST['kisi_ilce'] : '';
	$kos_meslek = 		isset($_POST['kos_meslek']) ? $_POST['kos_meslek'] : '';
	$kos_tanim = 		isset($_POST['kos_tanim']) ? $_POST['kos_tanim'] : '';
	$kos_depart = 		isset($_POST['kos_depart']) ? $_POST['kos_depart'] : '';
	$kos_poz = 			isset($_POST['kos_poz']) ? $_POST['kos_poz'] : '';
	$kos_tip = 			isset($_POST['kos_tip']) ? $_POST['kos_tip'] : '';
	$kos_para = 		isset($_POST['kos_para']) ? $_POST['kos_para'] : '';
	$ilet_tel = 		isset($_POST['ilet_tel']) ? $_POST['ilet_tel'] : '';
	$ilet_eposta = 		isset($_POST['ilet_eposta']) ? $_POST['ilet_eposta'] : '';



		//if ($ilet_tel!='')
		//{
		
			$selquery = "SELECT eposta FROM cvidler WHERE eposta='$uniqueID' ";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				
			}
			else
			{
				$cvid= md5(uniqid(mt_rand(), true));
				$insquery="INSERT INTO cvidler (eposta,cvid) VALUES('$uniqueID','$cvid')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		//}

			$selquery = "SELECT eposta FROM cvtecrube WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvtecrube SET tec_baslik='$tec_baslik', tec_kurum='$tec_kurum', tec_giristarih='$tec_giristarih', tec_cikistarih='$tec_cikistarih', tec_gorev='$tec_gorev', tec_yetenek='$tec_yetenek' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvtecrube (eposta,sira,tec_baslik,tec_kurum,tec_giristarih,tec_cikistarih,tec_gorev,tec_yetenek) VALUES('$uniqueID','$sira','$tec_baslik','$tec_kurum','$tec_giristarih','$tec_cikistarih','$tec_gorev','$tec_yetenek')";
				$insresult = mysqli_query($dbLink, $insquery);
			}



	//$siratecrube=1;
	//$siraegitim=3;
	//$siradil=3;
	//$sirasert=3;
	//$siraref=3;
	//$siraekleme=3;

		for ($sira=1;$sira<=$siratecrube;$sira++)
		{
			$tec_baslik = 		isset($_POST['tec_baslik'.$sira.'']) ? $_POST['tec_baslik'.$sira.''] : '';
			$tec_kurum = 		isset($_POST['tec_kurum'.$sira.'']) ? $_POST['tec_kurum'.$sira.''] : '';
			$tec_giristarih = 	isset($_POST['tec_giristarih'.$sira.'']) ? $_POST['tec_giristarih'.$sira.''] : '';
			$tec_cikistarih = 	isset($_POST['tec_cikistarih'.$sira.'']) ? $_POST['tec_cikistarih'.$sira.''] : '';
			$tec_gorev = 		isset($_POST['tec_gorev'.$sira.'']) ? $_POST['tec_gorev'.$sira.''] : '';
			$tec_yetenek = 		isset($_POST['tec_yetenek'.$sira.'']) ? $_POST['tec_yetenek'.$sira.''] : '';

			$selquery = "SELECT eposta FROM cvtecrube WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvtecrube SET tec_baslik='$tec_baslik', tec_kurum='$tec_kurum', tec_giristarih='$tec_giristarih', tec_cikistarih='$tec_cikistarih', tec_gorev='$tec_gorev', tec_yetenek='$tec_yetenek' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvtecrube (eposta,sira,tec_baslik,tec_kurum,tec_giristarih,tec_cikistarih,tec_gorev,tec_yetenek) VALUES('$uniqueID','$sira','$tec_baslik','$tec_kurum','$tec_giristarih','$tec_cikistarih','$tec_gorev','$tec_yetenek')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		}
		
		
		for ($sira=1;$sira<=$siraegitim;$sira++)
		{
			$egit_okul = 		isset($_POST['egit_okul'.$sira.'']) ? $_POST['egit_okul'.$sira.''] : '';
			$egit_derece = 		isset($_POST['egit_derece'.$sira.'']) ? $_POST['egit_derece'.$sira.''] : '';
			$egit_mezun = 		isset($_POST['egit_mezun'.$sira.'']) ? $_POST['egit_mezun'.$sira.''] : '';
			$egit_diploma = 	isset($_POST['egit_diploma'.$sira.'']) ? $_POST['egit_diploma'.$sira.''] : '';
			
			if ($egit_derece=="1")
			{
				$egit_derece_ad='İlköğretim';
			}
			else if ($egit_derece=="2")
			{
				$egit_derece_ad='Lise';
			}
			else if ($egit_derece=="3")
			{
				$egit_derece_ad='Meslek Lisesi';
			}
			else if ($egit_derece=="4")
			{
				$egit_derece_ad='Önlisans / Yüksekokul';
			}
			else if ($egit_derece=="5")
			{
				$egit_derece_ad='Lisans';
			}
			else if ($egit_derece=="6")
			{
				$egit_derece_ad='Yüksek Lisans';
			}
			else if ($egit_derece=="7")
			{
				$egit_derece_ad='Doktora';
			}
			else 
			{
				$egit_derece_ad='';
			}
			$selquery = "SELECT eposta FROM cvegitim WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvegitim SET egit_okul='$egit_okul', egit_derece='$egit_derece', egit_mezun='$egit_mezun', egit_diploma='$egit_diploma', egit_derece_ad='$egit_derece_ad' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvegitim (eposta,sira,egit_okul,egit_derece,egit_mezun,egit_diploma,egit_derece_ad) VALUES('$uniqueID','$sira','$egit_okul','$egit_derece','$egit_mezun','$egit_diploma','$egit_derece_ad')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		}
		
		for ($sira=1;$sira<=$siradil;$sira++)
		{	
			$ya_dil = 			isset($_POST['ya_dil'.$sira.'']) ? $_POST['ya_dil'.$sira.''] : '';
			$ya_derece = 		isset($_POST['ya_derece'.$sira.'']) ? $_POST['ya_derece'.$sira.''] : '';
			$ya_acikla = 		isset($_POST['ya_acikla'.$sira.'']) ? $_POST['ya_acikla'.$sira.''] : '';
			
			$selquery = "SELECT eposta FROM cvdil WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvdil SET ya_dil='$ya_dil', ya_derece='$ya_derece', ya_acikla='$ya_acikla' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvdil (eposta,sira,ya_dil,ya_derece,ya_acikla) VALUES('$uniqueID','$sira','$ya_dil','$ya_derece','$ya_acikla')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		}
		
		
		for ($sira=1;$sira<=$sirasert;$sira++)
		{		
			$sert_ad = 			isset($_POST['sert_ad'.$sira.'']) ? $_POST['sert_ad'.$sira.''] : '';
			$sert_tur = 		isset($_POST['sert_tur'.$sira.'']) ? $_POST['sert_tur'.$sira.''] : '';
			$sert_acikla = 		isset($_POST['sert_acikla'.$sira.'']) ? $_POST['sert_acikla'.$sira.''] : '';
			
			$selquery = "SELECT eposta FROM cvsert WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvsert SET sert_ad='$sert_ad', sert_tur='$sert_tur', sert_acikla='$sert_acikla' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvsert (eposta,sira,sert_ad,sert_tur,sert_acikla) VALUES('$uniqueID','$sira','$sert_ad','$sert_tur','$sert_acikla')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		}


		
		
		for ($sira=1;$sira<=$siraref;$sira++)
		{		
			$ref_firma = 		isset($_POST['ref_firma'.$sira.'']) ? $_POST['ref_firma'.$sira.''] : '';
			$ref_isim = 		isset($_POST['ref_isim'.$sira.'']) ? $_POST['ref_isim'.$sira.''] : '';
			$ref_telefon = 		isset($_POST['ref_telefon'.$sira.'']) ? $_POST['ref_telefon'.$sira.''] : '';
			
			$selquery = "SELECT eposta FROM cvreferans WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvreferans SET ref_firma='$ref_firma', ref_isim='$ref_isim', ref_telefon='$ref_telefon' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvreferans (eposta,sira,ref_firma,ref_isim,ref_telefon) VALUES('$uniqueID','$sira','$ref_firma','$ref_isim','$ref_telefon')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		}
		
		
		for ($sira=1;$sira<=$siraekleme;$sira++)
		{
			$ekledi = 			isset($_POST['ekledi'.$sira.'']) ? $_POST['ekledi'.$sira.''] : '';
			
			$selquery = "SELECT eposta FROM cvekleme WHERE eposta='$uniqueID' AND sira='$sira'";
			$selresult = mysqli_query($dbLink, $selquery);
			$varmi = mysqli_num_rows($selresult);
			if($varmi > 0) 
			{
				$upquery = "UPDATE cvekleme SET ekledi='$ekledi' WHERE eposta='$uniqueID' AND sira='$sira'"; 
				$upresult = mysqli_query($dbLink, $upquery);
			}
			else
			{
				$insquery="INSERT INTO cvekleme (eposta,sira,ekledi) VALUES('$uniqueID','$sira','$ekledi')";
				$insresult = mysqli_query($dbLink, $insquery);
			}
		}
		
		
				
		$selquery = "SELECT eposta FROM cvkisisel WHERE eposta='$uniqueID'";
		$selresult = mysqli_query($dbLink, $selquery);
		$varmi = mysqli_num_rows($selresult);
		if($varmi > 0) 
		{
			$upquery = "UPDATE cvkisisel SET kisi_askerlik='$kisi_askerlik', kisi_tarih='$kisi_tarih', kisi_medeni='$kisi_medeni', kisi_surucu='$kisi_surucu', kisi_seyahat='$kisi_seyahat', kisi_engel='$kisi_engel', kisi_saglik='$kisi_saglik', kisi_problem='$kisi_problem', kisi_il='$kisi_il', kisi_ilce='$kisi_ilce', kos_meslek='$kos_meslek', kos_tanim='$kos_tanim', kos_depart='$kos_depart', kos_poz='$kos_poz', kos_tip='$kos_tip', kos_para='$kos_para', ilet_tel='$ilet_tel', ilet_eposta='$ilet_eposta'	WHERE eposta='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);
		}
		else
		{
			$insquery="INSERT INTO cvkisisel (eposta,kisi_askerlik,kisi_tarih,kisi_medeni,kisi_surucu,kisi_seyahat,kisi_engel,kisi_saglik,kisi_problem,kisi_il,kisi_ilce,kos_meslek,kos_tanim,kos_depart,kos_poz,kos_tip,kos_para,ilet_tel,ilet_eposta) VALUES('$uniqueID','$kisi_askerlik','$kisi_tarih','$kisi_medeni','$kisi_surucu','$kisi_seyahat','$kisi_engel','$kisi_saglik','$kisi_problem','$kisi_il','$kisi_ilce','$kos_meslek','$kos_tanim','$kos_depart','$kos_poz','$kos_tip','$kos_para','$ilet_tel','$ilet_eposta')";
			$insresult = mysqli_query($dbLink, $insquery);
		}
		echo "oldu?";
	}
	
	else if ($action=="cvbilgikaydet")
	{
		//$uniqueID= 	isset($_POST['ilet_eposta']) ? $_POST['ilet_eposta'] : '';

		$isim = 				isset($_POST['isim']) ? $_POST['isim'] : '';
		$soyisim = 				isset($_POST['soyisim']) ? $_POST['soyisim'] : '';
		$dogumyeri = 			isset($_POST['dogumyeri']) ? $_POST['dogumyeri'] : '';
		$dogumtarihi = 			isset($_POST['dogumtarihi']) ? $_POST['dogumtarihi'] : '';
		$cinsiyet = 			isset($_POST['cinsiyet']) ? $_POST['cinsiyet'] : '';
		$dogumyeriilce = 		isset($_POST['dogumyeriilce']) ? $_POST['dogumyeriilce'] : '';

		$selquery = "SELECT eposta FROM cvkisisel WHERE eposta='$uniqueID'";
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

			$upquery = "UPDATE cvkisisel SET isim='$isim', soyisim='$soyisim', dogumyeri='$dogumyeri', dogumtarihi='$dogumtarihi', cinsiyet='$cinsiyet', dogumyeriilce='$dogumyeriilce'	WHERE eposta='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);
			
			$upquery = "UPDATE $dbtab SET first='$isim', last='$soyisim', dogumyeri='$dogumyeri', dogumtarihi='$dogumtarihi', gender='$cinsiyet', dogumyeriilce='$dogumyeriilce' WHERE email='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);
		}
		else
		{

			$insquery="INSERT INTO cvkisisel (eposta, isim, soyisim, dogumyeri, dogumtarihi, cinsiyet, dogumyeriilce) VALUES('$uniqueID', '$isim', '$soyisim', '$dogumyeri', '$dogumtarihi', '$cinsiyet', '$dogumyeriilce')";
			$insresult = mysqli_query($dbLink, $insquery);

			$upquery = "UPDATE $dbtab SET first='$isim', last='$soyisim', dogumyeri='$dogumyeri', dogumtarihi='$dogumtarihi', gender='$cinsiyet', dogumyeriilce='$dogumyeriilce' WHERE email='$uniqueID'"; 
			$upresult = mysqli_query($dbLink, $upquery);
		}

	}
	
	else 
	{
	
	
	
		
		$osman="deneme";
		$osman2=123;
		/*
	$selquery = "SELECT sira FROM cvtecrube WHERE eposta='$uniqueID' order by sira desc limit 1 ";
	$selresult = mysqli_query($dbLink, $selquery);
					echo "tecrubedeki max sira: ";
					if (mysqli_num_rows($selresult) > 0) 
					{	// output data of each row
						while($row = mysqli_fetch_assoc($selresult)) 
						{
							echo "" . $row["id"]. "";
							$siratecrube=$row["id"];
						}
					} else 
					{
						$siratecrube=0;
						echo "0";
					}

	$selquery = "SELECT * FROM cvegitim WHERE eposta='$uniqueID' AND sira='$siraegitim'";

	/*
	$selquery = "SELECT * FROM cvegitim WHERE eposta='$uniqueID' AND sira='$siraegitim'";
	$selquery = "SELECT * FROM cvdil WHERE eposta='$uniqueID' AND sira='$siradil'";
	$selquery = "SELECT * FROM cvsert WHERE eposta='$uniqueID' AND sira='$sirasert'";
	$selquery = "SELECT * FROM cvreferans WHERE eposta='$uniqueID' AND sira='$siraref'";
	$selquery = "SELECT * FROM cvekleme WHERE eposta='$uniqueID' AND sira='$siraekleme'";
	$selquery = "SELECT * FROM cvkisisel WHERE eposta='$uniqueID'";

	$selquery = "Select * from $dbtab where email = '$uniqueID' ";
	$selresult = mysqli_query($dbLink, $selquery);

	while($row = mysqli_fetch_row($selresult))
		{
		$isim=clean_html($row[1])==""?clean_html($row[11]):clean_html($row[1]);
		echo $row[1];*/
	}
?>
	