int person_rule(int asset, int income){
	int i = 9999;
	if(asset == 0 && income ==0){
		i=0;
	}else if(asset == 0 && income ==1){
		i=0;
	}else if(asset == 0 && income ==2){
		i=1;
	}else if(asset == 0 && income ==3){
		i=2;
	}else if(asset == 1 && income ==0){
		i=0;
	}else if(asset == 1 && income ==1){
		i=2;
	}else if(asset == 1 && income ==2){
		i=2;
	}else if(asset == 1 && income ==3){
		i=1;
	}else if(asset == 2 && income ==0){
		i=1;
	}else if(asset == 2 && income ==1){
		i=1;
	}else if(asset == 2 && income ==2){
		i=2;
	}else if(asset == 2 && income ==3){
		i=2;
	}	

	return i;
}
int house_rule(int Location, int Market){
	int i = 9999;
   if(Location == 0 && Market ==0){
		i=0;
	}else if(Location == 0 && Market ==1){
		i=1;
	}else if(Location == 0 && Market ==2){
		i=2;
	}else if(Location == 0 && Market ==3){
		i=3;
	}else if(Location == 1 && Market ==0){ 
		i=1;
	}else if(Location == 1 && Market ==1){
		i=2;
	}else if(Location == 1 && Market ==2){
		i=3;
	}else if(Location == 1 && Market ==3){ 
		i=4;
	}else if(Location == 2 && Market ==0){
		i=2;
	}else if(Location == 2 && Market ==1){
		i=3;
	}else if(Location == 2 && Market ==2){
		i=4;
	}else if(Location == 2 && Market ==3){
		i=4;
	}	
	return i;
}

int  house_rule_market(int Market){
	int i = 9999;
   if(Market == 0 ){
		i=1;
	} 
	return i;
}

int house_rule_location(int Location){
	int i = 9999;
   if(Location == 0 ){
		i=1;
	} 
	return i;
}
int credit_income_interest_rule(int income,int interest){ 
	int i = 9999;									
   if(income == 0 && interest==1){					
		i=0;
	}
	else if(income == 0 && interest==2){
		i=0;
	}
	else if(income == 1 && interest==2){
		i=1;
	}	
	return i;
}
int credit_applicant_rule(int applicant){
	int i = 9999;
	if(applicant==0){
		i=0;
	}
	return i;
}
int credit_house_rule(int house){
	int i = 9999;
	if(house==0){
		i=0;
	}
	return i;
}
int credit_applicant_house_rule (int applicant, int house){	
	int i = 9999;																
   if(applicant == 1 && house ==0){						 
		i=1;
	}
	else if(applicant == 1 && house ==1){
		i=1;
	}
	else if(applicant == 1 && house ==2){
		i=2;
	}
	else if(applicant == 1 && house ==3){
		i=3;
	}
	else if(applicant == 1 && house ==4){
		i=3;
	}
	else if(applicant==2 && house==0){
		i=1;
	}	
	else if(applicant==2 && house==1){
		i=2;
	}	
	else if(applicant==2 && house==2){
		i=3;
	}
	else if(applicant==2 && house==3){
		i=3;
	}
	else if(applicant==2 && house==4){
		i=4;
	}							
	return i;
}

