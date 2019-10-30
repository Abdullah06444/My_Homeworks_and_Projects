#include"fuzzy_number.cpp"
#define number_of_income_type 4
#define number_of_asset_type 3
#define number_of_Market_type 4
#define number_of_Location_type 3
#define number_of_applicant_type 3
#define number_of_House_type 5
#define number_of_Credit_type 5
#define number_of_Interest_type 3

struct person{
	double p_asset , p_income,p_interest;
	double p_Market , p_Location,P_House,p_credit;
	int income_type[number_of_income_type];
	int asset_type[number_of_asset_type];
	int location_type[number_of_Location_type];
	int market_type[number_of_Market_type];
	int interest_type[number_of_Interest_type];
	fuzzy_number applicants[number_of_applicant_type];	
	fuzzy_number houses[number_of_House_type];
	fuzzy_number credit[number_of_Credit_type];
};
