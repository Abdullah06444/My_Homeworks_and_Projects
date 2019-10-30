<div class="block-section bg-color4">

	<div class="container">
		<div class="panel panel-md">
			<div class="panel-body">
	  <!-- Google+ Login -->
	  <?PHP include("denemeapi/index.php"); ?>

				<div class="row">
					<div class="col-md-12">
						<!-- buttons top -->
						<p><a href="register.html#" class="btn btn-primary btn-theme btn-block"><i class="fa fa-facebook pull-left bordered-right"></i>Facebook ile kayıt yap</a></p>
						<p><a href="<?=$authUrl?>" class="btn btn-danger btn-theme btn-block"><i class="fa fa-google-plus pull-left bordered-right"></i>Google ile kayıt yap</a></p>
						<!-- end buttons top -->

						<div class="white-space-10"></div>
						<p class="text-center"><span class="span-line">VEYA</span></p>

						<!-- form login -->
						<form ACTION ="<?PHP echo "register.php?session=".$session."" ?>" METHOD="POST"> <!-- //htdocs/register/seekers_ -->
					

					<?PHP			
						if($action == "" || $complete == "no") 
						{
							$bademail = isset($bademail) ? $bademail : '';
							$alreadyemail = isset($alreadyemail) ? $alreadyemail : '';
							$badpass1 = isset($badpass1) ? $badpass2 : '';
							$badpass2 = isset($badpass2) ? $badpass2 : '';
							$badmatch = isset($badmatch) ? $badmatch : '';
							$pregmatch =  isset($pregmatch) ? $pregmatch : '';
							$badrecaptcha = isset($badrecaptcha) ? $badrecaptcha : '';
							
					?>		
						<div class="form-group">
					
					
						<center class="text-center">
							<div class="row">
								<div class="radio flat-radio">
									<div class="col-xs-6">
										<label>
										<input type="radio" name="sec" onclick="myFunction()" value="seekers"> 
										<span class="fa fa-check"></span>
										Çalışan
										</label>
									</div>

									<div class="col-xs-6">
										<label>
										<input type="radio" name="sec" onclick="myFunction()" value="employers"> 
										<span class="fa fa-check"></span>
										Şirket
										</label>
									</div>							
								</div>
							</div>
						</center>
						
                        <label>
						<?PHP
						
							echo "" . $alreadyemail . $bademail . "E-posta";	
							if($bademail) { print("<li><small><b>Geçersiz bir email adresidir.</a></b></small></li></font>"); } 
							if($alreadyemail) { print("<li><small><b>Bu email adresi zaten kayıtlıdır.</a></b></small></li></font>"); }
						?>
						</label>
                        
							<input name="email" type="email" class="form-control" placeholder="E-Posta Adresi" value="<?PHP echo $email; ?>">
						</div>
						
						<div class="form-group">
                        <label>
						<?PHP

	//$selquery = "Select email,password,first from $dbtab where email='$email'";
	//$selresult = mysqli_query($dbLink, $selquery);


						
							echo "" . $badpass1 . $badpass2 . $badmatch . $pregmatch . "Şifre";	
							if($badpass1 || $badpass2) { print("<li><small><b>Bir şifre alanı boş bırakıldı.</b></small></li></font>"); } 
							if($badmatch) { print("<li><small><b>Şifreler eşleşmedi.</b></small></li></font>"); }
							if($pregmatch) { print("<li><small><b>Şifre istenen formatta girilmedi.</b></small></li></font>"); }
	//if(!$badmatch) { row[1] = hash('sha512',$password1); }
											
						}
						?>
						
						
						</label>
							<input name="password1" type="password" class="form-control" placeholder="Şifre" value="<?PHP echo $password1; ?>">
						</div>
						
						
						<div class="form-group">
                        <label>Şifre Tekrar</label>
							<input name="password2" type="password" class="form-control" placeholder="Şifre Tekrar" value="<?PHP echo $password2; ?>">
						</div>
					  
						
						<div class="form-group">
							<div class="row">
								<div class="col-xs-6"></div>
								<div class="col-xs-6 text-right">
									<p class="help-block"><a href="kayitbolme1.php#myModal2" data-toggle="modal">Şifre Kriterleri!</a></p>
								</div>
							</div>
						</div>

						<?php
							echo "" . $badrecaptcha . "<small><b>reCaptcha</b></small>";
							if($badrecaptcha) { print("<li><small><b>Lütfen reCaptcha doğrulamayı yapınız.</b></small></li></font>"); }
						?>
						<div class="form-group">
							<div class="g-recaptcha" data-sitekey="6Lcno2QUAAAAAKSG01PxLZ3mpfUfXBga0tL5c2yh"></div>
						</div>
		
						<div class="form-group no-margin">
							<button name="action" value="kayitol" id="myRadio" class="btn btn-theme btn-lg btn-t-primary btn-block" disabled>Kayıt Ol</button>
						
							<script src='https://www.google.com/recaptcha/api.js'></script>
							<script>
								function myFunction() 
								{
									document.getElementById("myRadio").disabled = false;
								}
							</script>
						</div>
						</form><!-- form login -->

					</div>
                </div>
            </div>
        </div>

        <div class="white-space-20"></div>
        <div class="text-center color-white">bilirisi.com'da üyelik oluşturarak <br><a href="register.php" class="link-white"><strong>Kullanım Koşulları</strong></a> ve <a href="register.php" class="link-white"><strong>Gizlilik</strong></a> sözleşmelerini<br>kabul etmiş bulunursunuz.</div>
    </div>
        
</div>
