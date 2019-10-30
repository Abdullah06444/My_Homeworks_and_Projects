#include<iostream>
#include"person.cpp"
#include"rule.cpp"
using namespace std;


double min(double a, double b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}
double defuzzication(fuzzy_number arrayOfFuzzyNumbers[5])
{
	double result;
	double max=0;
	double index=0;
	for(int i=0;i<5;i++){
		if(arrayOfFuzzyNumbers[i].max_value>max){			
			max=arrayOfFuzzyNumbers[i].max_value;
			result = arrayOfFuzzyNumbers[i].max_s+arrayOfFuzzyNumbers[i].max_f;
			index=1;
		}else if(arrayOfFuzzyNumbers[i].max_value==max){
			result += arrayOfFuzzyNumbers[i].max_s+arrayOfFuzzyNumbers[i].max_f;
			index++;	
		}
	}
	
	result= result/2.0;
	result=result/index;
	return result;
}
int main(){
	
	fuzzy_number asset_Low(0,0,0,150);
	fuzzy_number asset_Medium(50,250,500,650);
	fuzzy_number asset_High(500,700,1000,1000);
	
	fuzzy_number assets[number_of_asset_type]={ asset_Low,asset_Medium, asset_High};
	
	fuzzy_number income_Low(0,0,13,25);
	fuzzy_number income_Medium(15,35,35,55);
	fuzzy_number income_High(40,60,60,80);
	fuzzy_number income_Very_High(60,80,1000,1000);
	
	fuzzy_number incomes[number_of_income_type]={ income_Low,income_Medium, income_High , income_Very_High};
	
	fuzzy_number applicant_Low(0,0,2,4);
	fuzzy_number applicant_Medium(2,5,5,8);
	fuzzy_number applicant_High(6,8,10,10);
	
	fuzzy_number  applicants[number_of_applicant_type]={applicant_Low,applicant_Medium,applicant_High};
	
	fuzzy_number Market_Low(0,0,75,100);
	fuzzy_number Market_Medium(50,100,200,250);
	fuzzy_number Market_High(200,300,650,850);
	fuzzy_number Market_Very_High(650,850,1000,1000);
	
	fuzzy_number Markets[number_of_Market_type]={ Market_Low,Market_Medium, Market_High,Market_Very_High};
	
	fuzzy_number Location_Bad(0,0,1.5,4.0);
	fuzzy_number Location_Fair(2.5,5,6,8.5);
	fuzzy_number Location_Excellent(6,8.5,10,10);
	
	fuzzy_number Locations[number_of_Location_type]={ Location_Bad,Location_Fair, Location_Excellent};
	
	fuzzy_number House_Very_Low(0,0,0,3);
 	fuzzy_number House_Low(0,3,3,6);
	fuzzy_number House_Medium(2,5,5,8);
	fuzzy_number House_High(4,7,7,10);
	fuzzy_number House_Very_High(7,10,10,10);
	
	fuzzy_number houses[number_of_House_type] = {House_Very_Low,  House_Low, House_Medium ,House_High, House_Very_High	};
	
	fuzzy_number Credit_Very_Low(0,0,0,125);
 	fuzzy_number Credit_Low(0,125,125,250);
	fuzzy_number Credit_Medium(125,250,250,375);
	fuzzy_number Credit_High(250,375,375,500);
	fuzzy_number Credit_Very_High(375,500,500,500);
	fuzzy_number Credits[5]={Credit_Very_Low,Credit_Low,Credit_Medium,Credit_High,Credit_Very_High};
	
	fuzzy_number Interest_Low(0,0,2,5);
 	fuzzy_number Interest_Medium(2,4,6,8);
	fuzzy_number Interest_High(6,8.5,10,10);
	fuzzy_number Interests[3]={Interest_Low,Interest_Medium,Interest_High};
	
	int number_of_person;
	int count = 0 ,i ,j;
	cout<<"enter number of person"<<endl;
	cin>>number_of_person;
	person persons[number_of_person];
	cout<<"Enter Asset, Income, Market Location and Interest respectively"<<endl;
	for( i = 0 ; i< number_of_person; i++){
		cout<<"For Person "<<i+1<<endl;
		cin>>persons[i].p_asset>>persons[i].p_income>>persons[i].p_Market>>persons[i].p_Location>>persons[i].p_interest;
		cout<<"--- ASSESTS"<<endl;
		for(j = 0 ; j< number_of_asset_type ;j++){
			if(assets[j].in_there(persons[i].p_asset)){
				persons[i].asset_type[j]=1;
				cout<<j<<"  "<<assets[j].member_ship(persons[i].p_asset)<<endl;
			}else {
				persons[i].asset_type[j]=0;
			}
		}
		cout<<"--- INCOME"<<endl;
		for(j = 0 ; j< number_of_income_type ;j++){
			if(incomes[j].in_there(persons[i].p_income)){
				persons[i].income_type[j]=1;
				cout<<j<<"  "<<incomes[j].member_ship(persons[i].p_income)<<endl;
			}else{
				persons[i].income_type[j]=0;
			}
		}
		cout<<"--- MARKET"<<endl;
		for(j = 0 ; j< number_of_Market_type ;j++){
			if(Markets[j].in_there(persons[i].p_Market)){
				persons[i].market_type[j]=1;
				cout<<j<<"  "<<Markets[j].member_ship(persons[i].p_Market)<<endl;
			}else{
				persons[i].market_type[j]=0;
			}
		}
		cout<<"--- LOCATION"<<endl;
		for(j = 0 ; j< number_of_Location_type ;j++){
			if(Locations[j].in_there(persons[i].p_Location)){
				persons[i].location_type[j]=1;
				cout<<j<<"  "<<Locations[j].member_ship(persons[i].p_Location)<<endl;
			}else{
				persons[i].location_type[j]=0;
			}
		}
		cout<<"--- INTEREST"<<endl;
		
		for(j = 0 ; j< number_of_Interest_type;j++){
			if(Interests[j].in_there(persons[i].p_interest)){
				persons[i].interest_type[j]=1;
				cout<<j<<"  "<<Interests[j].member_ship(persons[i].p_interest)<<endl;
			}else{
				persons[i].interest_type[j]=0;
			}
		}
		cout<<"---"<<endl;
		
		int k,l, current;
		double m_s;
		for(k=0 ; k<number_of_asset_type; k++){
			if(persons[i].asset_type[k]==1){
				for(l=0;l <number_of_income_type ; l++){
					if(persons[i].income_type[l]==1){
						m_s=min(incomes[l].member_ship(persons[i].p_income),assets[k].member_ship(persons[i].p_asset));
						current = person_rule(k,l);
						fuzzy_number temp ;
						temp = applicants[current].new_number(m_s);
						if(persons[i].applicants[current].max_value<temp.max_value)
						 persons[i].applicants[current]=temp;
						
					}
				}
			}
		}
		
		for(k=0 ;k<number_of_applicant_type;k++){
			cout<<"applicant "<<k<<" "<<persons[i].applicants[k].max_value<<endl;
			
		}
		
		for(k=0; k<number_of_Location_type; k++){
			if(persons[i].location_type[k]==1){
				current = house_rule_location(k);
				if(current!=9999){
					
					m_s = Locations[k].member_ship(persons[i].p_Location);
					fuzzy_number temp ;
					temp = houses[current].new_number(m_s);
					if(persons[i].houses[current].max_value<temp.max_value)
						persons[i].houses[current]=temp;
					}
				
			}
		}
		
		for(k=0; k<number_of_Market_type; k++){
			if(persons[i].market_type[k]==1){
				current = house_rule_market(k);
				if(current!=9999){
					
					m_s = Markets[k].member_ship(persons[i].p_Market);
					fuzzy_number temp ;
					temp = houses[current].new_number(m_s);
					if(persons[i].houses[current].max_value<temp.max_value)
						persons[i].houses[current]=temp;
					}
				
			}
		}
		
		for(k=0 ; k<number_of_Location_type; k++){
			if(persons[i].location_type[k]==1){
				for(l=0;l <number_of_Market_type ; l++){
					if(persons[i].market_type[l]==1){
						current = house_rule(k,l);
						if(current!=9999){
						m_s=min(Markets[l].member_ship(persons[i].p_Market),Locations[k].member_ship(persons[i].p_Location));
						fuzzy_number temp ;
						temp = houses[current].new_number(m_s);
						if(persons[i].houses[current].max_value<temp.max_value)
						 persons[i].houses[current]=temp;
						}
					}
				}
			}
		}
		for(k=0 ; k<number_of_House_type; k++){
			cout<<"house "<<k<<" "<<persons[i].houses[k].max_value<<endl;
		}

		for(k=0 ; k<number_of_applicant_type;k++){
			if(persons[i].applicants[k].max_value>0){
				for(l=0;l<number_of_House_type; l++){
					if(persons[i].houses[l].max_value>0){
						current=credit_applicant_house_rule(k,l);
						if(current!=9999){
						m_s=min(persons[i].applicants[k].max_value,persons[i].houses[l].max_value);
						fuzzy_number temp ;
						temp = Credits[current].new_number(m_s);
						if(persons[i].credit[current].max_value<temp.max_value)
						 persons[i].credit[current]=temp;
														
						}
						
					}
				}
			}
		}
		
		for(k=0;k<number_of_income_type;k++){
			if(persons[i].income_type[k]==1){
				for(l=0; l<number_of_Interest_type;l++){
					if(persons[i].interest_type[l]==1){
						current = credit_income_interest_rule(k,l);
						if(current!=9999){
						m_s=min(Interests[l].member_ship(persons[i].p_income), incomes[k].member_ship(persons[i].p_income));
						fuzzy_number temp ;
						temp = Credits[current].new_number(m_s);
						if(persons[i].credit[current].max_value<temp.max_value)
						persons[i].credit[current]=temp;
						}
					}
				}
			}
		}
		for(k=0;k<number_of_House_type;k++){
			if(persons[i].houses[k].max_value>0){
				current=credit_house_rule(k);
				if(current!=9999){
					m_s=persons[k].houses[k].max_value;
					fuzzy_number temp ;
					temp = Credits[current].new_number(m_s);
					if(persons[i].credit[current].max_value<temp.max_value)
					persons[i].credit[current]=temp;
				}
			}
		}
		for(k=0;k< number_of_applicant_type;k++){
			if(persons[i].applicants[k].max_value>0){
				current=credit_applicant_rule(k);
				if(current!=9999){
					m_s=persons[k].applicants[k].max_value;
					fuzzy_number temp ;
					temp = Credits[current].new_number(m_s);
					if(persons[i].credit[current].max_value<temp.max_value)
					persons[i].credit[current]=temp;
				}
			 
			}			
		}
		for(k=0; k<number_of_Credit_type;k++){
			cout<<"credit "<<persons[i].credit[k].max_value<<endl;
		}
		
		double result = defuzzication(persons[i].credit);
		persons[i].p_credit=result;
		cout<<"\n\ncredit result "<<persons[i].p_credit<<endl;
		
}
}
