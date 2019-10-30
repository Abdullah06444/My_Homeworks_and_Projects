class fuzzy_number{
	public:
	double min_s,max_s,max_f,min_f;
	double max_value;
	
	fuzzy_number(){
		min_s= 0;
		max_s =  0;
		max_f = 0;
		min_f =  0;
		max_value = 0;
	}
	
	fuzzy_number(double mins, double maxs, double maxf, double minf){
		min_s= mins;
		max_s =  maxs;
		max_f = maxf;
		min_f =  minf;
		max_value = 1;
		
	}
	
	bool in_there(double number){
		if(number < min_f && number > min_s){
			return true;
		}else{
			return false;
		}
	}
		
	double member_ship(double number){
		double value;
		if(in_there(number)){
			if(number < max_s){	
				value = (number- min_s)/(max_s-min_s);
			}
			else if( number <= max_f){
				value = max_value ;
			}else{
				value = (min_f-number)/(min_f- max_f);
			}
		}else{
			
			value = 0 ;
		}
		
		return value;	
	}	
	
	
	fuzzy_number new_number(double m_s){
		
		double new_max_s, new_max_f;
		
		new_max_s = m_s*(max_s-min_s)+min_s;
		new_max_f = min_f- m_s*(min_f-max_f);
		
		fuzzy_number temp(min_s,new_max_s,new_max_f,min_f);
		temp.max_value = m_s;
		return temp;
	}
	
	
};



