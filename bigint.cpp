#include "bigint.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>

BigInt::BigInt(string s){ 
	int n = s.length();
	for(int i=n-1; i>=0; i--){
		int num = s[i] - '0';
		vec.push_back(num);
	}
}



string BigInt::to_string(){
	str = "";
	int n = (int)vec.size();
	for(int i=n-1; i>=0; i--){
			str+=vec[i] + 48;
		}

	return str;
}

void BigInt::add(BigInt b){
	while(vec.size()!=b.vec.size()){
		if(vec.size()>b.vec.size()){
			b.vec.push_back(0);
		}
		else{
			vec.push_back(0);
		}
	}
	
	int carry = 0;
	
	for(int i=0; i<(int)vec.size(); i++){
		int sum = vec[i]+b.vec[i]+carry;
		carry = sum/10;
		vec[i] = sum%10;
	}
	if(carry>0){
		vec.push_back(carry);
	}

}