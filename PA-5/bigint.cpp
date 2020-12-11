#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

/*
//   Create a default BigInt with base 10.
*/
BigInt::BigInt(){

    /******** You complete ****************/
	base = 10;
	isPositive = true;
}

/*
//  Create a BigInt with a specified base.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
	base = setbase;
	isPositive = true;
}

/*
//  Create a BigInt from int (base 10) with a specified base.
//  Here you would convert an int (base 10) into a specified base.
//  e.g., (10,2) <-- 10 base 10 to base 2 --> result:  BigInt with value 1010 base 2
//  e.g., (100,16) <--- 100 base 10 to base 16 --> result: BigInt with value 64 base 16
*/
BigInt::BigInt(int input,int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
	
	base = setbase;
	int num = abs(input);
	if(input<0){
		isPositive = false;
	}
	else
		isPositive = true;
	if(input==0)
		vec.push_back(0);
	while(num > 0){
		vec.push_back(num%setbase);
		num = num / base;
	}
}

/*
//  Create a BigInt from string with a specified base.
//  You can assume that the string number input is in the same
//      base as the setbase input.
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
	base = setbase;
    for(int i = s.length()-1; i>=1; i--){
        if(s[i] < 58){
            vec.push_back(s[i]-48);
        }else{ 
            vec.push_back(s[i]-55);
        }
    }
    if(s[0] == '-'){
        isPositive = false;
    }else{
        if(s[0] < 58){
            vec.push_back(s[0]-48);
        }else{ 
            vec.push_back(s[0]-55);
        }
        isPositive = true;
    }
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply use the assignment operator.
*/
BigInt::BigInt(const BigInt &b){

    /************* You complete *************/
	base = b.base;
	isPositive = b.isPositive;
	
	int n = (int)b.vec.size();
	for(int i=0; i<n; i++){
		vec.push_back(b.vec[i]);
	}
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}

/*
// Convert to string and return the string
//  Display it in its corresponding base
*/
string BigInt::to_string(){

    /************* You complete *************/
	string str = "";
	if(!isPositive)
		str += '-';
	int n = (int)vec.size();
	for(int i=n-1; i>=0; i--){
		if(vec[i] < 10)
			str = str + (char)(vec[i]+48);
		else if(vec[i]>=10)
			str = str + (char)(vec[i]+55);
	}
	return str;
}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt > INT_MAX, return INT_MAX.
//    If BigInt < INT_MIN, return INT_MIN.
*/
int BigInt::to_int() const{

    /************* You complete *************/
	int num = 0;
    for(int i=0; i<(int)vec.size(); i++){
        num = num + (vec[i]*pow(base,i));
    }
    if(!isPositive){
        num = num * -1;
	}
	if(num>INT_MIN&&num<INT_MAX){
		return num;
	}
	if(isPositive){
		return INT_MAX;
	}
	return INT_MIN;
}

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
	int num = 0;
    if(isPositive && !b.isPositive)
        return 1;

    if(!isPositive && b.isPositive)
        return -1;
                             
    if(vec.size() < b.vec.size())
        num = -1;
    else if(vec.size() > b.vec.size())
        num = 1;
    else{
        for(int i = vec.size() - 1; i >= 0; i--){
            if(vec[i] < b.vec[i]){
                num = -1;
                break;
            } 
            if(vec[i] > b.vec[i]){
                num = 1;
                break;
            } 
        }
    }
    
    if(!isPositive && !b.isPositive){
        num = num * -1;
    } 
    return num;
}

/*
//  Assignment operator. (i.e., BigInt a = b;)
*/
const BigInt & BigInt::operator = (const BigInt &b){

    /************* You complete *************/
	base = b.base;
	isPositive = b.isPositive;
	while(vec.size()!=0)
		vec.pop_back();
	
	int n = (int)b.vec.size();
	
	for(int i=0; i<n; i++)
		vec.push_back(b.vec[i]);
	
	return *this;
}

/*
//  Addition assignment operator.
//    - Compute a = a + b.
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
	while(b.vec.size() > vec.size()){
        vec.push_back(0);
    }
    if(b.to_int()==0){
        return *this;
    }
    if((!isPositive && !b.isPositive) || (isPositive && b.isPositive)){
        int carry = 0;
        int num = 0;
        for(unsigned int i = 0; i < vec.size();i++){
            if(i > b.vec.size()-1)
                num = carry + vec[i];
			else
                num = carry + vec[i] + b.vec[i];
            if(num >= base){
                vec[i] = num % base;
                carry = num/base;
            }
			else{
                vec[i] = num;
                carry = 0;
            }
        }
        if(carry == 1)
            vec.push_back(1);
	}
	else if(isPositive && !b.isPositive){
        BigInt tempb = b;
        tempb.isPositive = true;
        *this -= tempb;
    }
	else if(!isPositive && b.isPositive){
        BigInt tempb = b;
        tempb.isPositive = false;
        *this -= tempb;
    }
    return *this;
}
  


/*
//  Subtraction assignment operator.
//    - Compute a = a - b
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    int num; int bor = 0;
    
    while(b.vec.size() > vec.size())
        vec.push_back(0);

    if(isPositive == b.isPositive ){
        if((isPositive && (compare(b) == 1)) || (!isPositive && (compare(b) == (-1)))){          
            for(int i = 0; i<(int)vec.size(); i++){
                if(i>(int)b.vec.size()-1)
                    num = vec[i] - bor;
                else
                    num = vec[i] - b.vec[i] - bor;
                bor = 0;
                if(num < 0){
                    num+=base;
                    bor = 1;
                }
                vec[i] = num;
            }
        }
		else{
            BigInt temp = b;
            for(int i=0; i<(int)temp.vec.size(); i++){
                if(i>(int)vec.size()-1)
                    num = temp.vec[i] - bor;
                else
                    num = temp.vec[i] - vec[i] - bor;
                bor = 0;
                if(num < 0){
                    num+=base;
                    bor = 1;
                }
                temp.vec[i] = num;
            }
            *this = temp;
            isPositive = !isPositive;
        }
        
        while((vec[vec.size()-1] == 0) && vec.size() > 1){
            vec.pop_back();
        }    
    }
    else if(isPositive && !b.isPositive){
        BigInt temp = b;
        temp.isPositive = true;
        *this += temp;
        }
        
    else if(!isPositive && b.isPositive){
        BigInt temp = b;
        temp.isPositive = false;
        *this += temp;
        }

  if(to_int() == 0){
      isPositive = true;
  }
  
  return *this;//for now
}

/*
//  Multiplication assignment operator.
//    - Compute a = a * b;
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    if(to_int() == 0 || b.to_int() == 0){
        int n = vec.size()-1;
        while(true){
            if(n == 0){
                vec.pop_back();
                vec.push_back(0);
                isPositive = true;
                break;
            }
            vec.pop_back();
            n--;
        }
        return *this;
    }
    unsigned int pos = 0;
    int num = 0, carry = 0, sum = 0;
    int iNum = 0, iCarry = 0, iSum = 0;
    vector <int> temp;
    for(unsigned int i = 0; i < b.vec.size(); i++){
        pos = i;
        for(unsigned int j = 0; j < vec.size(); j++){
            if(i == 0){
                num = carry + (b.vec[i] * vec[j]);
                if(num >= base){
                    sum = num % base;
                    carry = num / base;
                    temp.push_back(sum);
                }
				else{
                    carry = 0;
                    temp.push_back(num);
                }
            }
			else if(i > 0){
                num = carry + (b.vec[i] * vec[j]);
                if(num >= base){
                    sum = num % base;
                    carry = num / base;
                    if(pos > temp.size()-1){
                    	iNum = iCarry + sum;
                    	if(iNum >= base){
                    		iSum = iNum % base;
                    		iCarry = iNum / base;
                    		temp.push_back(iSum);
                    		pos++;
						}
						else{
							iCarry = 0;
							temp.push_back(iNum);
                        	pos++;
						}
                    }
					else{
                        iNum = iCarry + temp[pos] + sum;
                        if(iNum >= base){
                            iSum = iNum % base;
                            iCarry = iNum / base;
                            temp[pos] = iSum;
                            pos++;
                        }
						else{
                            iCarry = 0;
                            temp[pos] = iNum;
                            pos++;
                        }
                    }
                }
                else{
                    carry = 0;
                    if(pos > temp.size() - 1){
                    	iNum = iCarry + num;
                    	if(iNum >= base){
                    		iSum = iNum % base;
                    		iCarry = iNum / base;
                    		temp.push_back(iSum);
                    		pos++;
						}
						else{
							iCarry = 0;
							temp.push_back(iNum);
							pos++;
						}
                    }
					else{
                        iNum = iCarry + temp[pos] + num;
                        if(iNum >= base){
                            iSum = iNum % base;
                            iCarry = iNum / base;
                            temp[pos] = iSum;
                            pos++;
                        }
						else{
                            iCarry = 0;
                            temp[pos] = iNum;
                            pos++;
                        }
                    }
                }
            }
    	}
    	if(i == 0){
    		if(carry > 0 && carry < base)
					temp.push_back(carry);		
			carry = 0;
		}
		else if(i > 0){
			num = carry + iCarry;
			if(num >= base){
				while(num>=base){
					sum = num % base;
					num = num / base;
					temp.push_back(sum);
				}
			}
			else
				temp.push_back(num);
			carry = 0;
			iCarry = 0;
		}
    }
    if((!isPositive && !b.isPositive)||(isPositive && b.isPositive))
        isPositive = true;
    else if((!isPositive && b.isPositive)||(isPositive && !b.isPositive))
        isPositive = false;
    
    int j = vec.size()-1;
    while(j >= 0){
        vec.pop_back();
        j--;
    }
    for(unsigned int i = 0; i < temp.size(); i++)
        vec.push_back(temp[i]);
    
    if(vec[vec.size()-1] == 0 && vec.size() > 1)
        vec.pop_back();
    else if(vec[vec.size()-1] == 0 && vec.size() == 1)
        isPositive = true;
    
    return *this;
}

/*
//  Division assignment operator.
//    - Call 'divisionMain' to compute a = a / b;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
	BigInt quotient(base);
	BigInt remainder(base);
	divisionMain(b,quotient, remainder);
	*this = quotient;
	return *this;
}

/*
//  Modulus assignment operator.
//    - Call 'divisionMain' to compute a = a % b.
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
	BigInt quotient(base);
	BigInt remainder(base);
	divisionMain(b, quotient, remainder);
	*this = remainder;
	return *this;
}

/*
//  Main function for the Division and Modulus operator.
//     - Compute (q)uotient and (r)emainder: a = (b * q) + r.
//     - Note: NO fraction. This should behave like integer division
//             where 2/10 = 0, not 0.2
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){

    /************* You complete *************/
	BigInt div = b;
    div.isPositive = true;
    BigInt r(base);
    int c = 0, n = vec.size();
    for(int i = 0; i < n; i++){
        r.vec.insert(r.vec.begin(),vec[n-i-1]);
        if(i > 0 && r.vec[r.vec.size() - 1] == 0){
            r.vec.pop_back();
        }
        while(r.compare(div) != -1){
            r -= div;
            c++;
        }
        quotient.vec.insert(quotient.vec.begin(),c);
        c = 0;
    }
    remainder = r;

    while((quotient.vec[quotient.vec.size()-1] == 0) && quotient.vec.size() > 1){
        quotient.vec.pop_back();
    }
    if(((!isPositive && b.isPositive) || (isPositive && !b.isPositive)) && quotient.to_int() != 0)
        quotient.isPositive = false;
    else
        quotient.isPositive = true;
    
    if(!isPositive && remainder.to_int() != 0)
        remainder.isPositive = false;
    else
        remainder.isPositive = true;
}


/*
//  Exponentiation assignment function.
//     - Compute a BigInt whose value is a = pow(a,b).
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
	if(b.vec[0] == 0 && b.vec.size() == 1){
        BigInt one(1,base);
        *this = one;
    }
    else if(b.vec[0] == 1 && b.vec.size() == 1)
        return *this;
    else if((b.to_int() % 2 == 0) && b.vec.size() > 0){
        BigInt bCopy = b;
        return *this *= exponentiation(bCopy/BigInt(2,base));
    }
    else if((b.to_int() % 2 != 0) && b.vec.size() > 0){
        BigInt copy = *this;
        BigInt copyB = b;
        copyB -= BigInt(1,base);
        *this *= exponentiation(copyB/ BigInt(2,base));
        *this *= copy;
    }
    return *this;
}


/*
//  Modulus Exponentiation assignment function.
//     - Compute a = (a ^ b) % m.
//     - Do NOT compute a^b directly and then % m. 
//         This is too computationally expensive.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
	BigInt ans = BigInt(1,base);
	if(b.vec[0]==0 && b.vec.size()==1)
		ans = *this % b;
	else if(b.vec[0]==1 && b.vec.size()==1)
		ans = *this % b;
	else{
		BigInt temp = b;
		while(temp.compare(BigInt(0, base)) != 0){
			if(temp.vec[0]%2==0){
				temp/=BigInt(2,base);
				*this *= (*this);
				*this %= m;
			}
			else{
				ans = (ans*(*this)) % m;
				temp -= BigInt(1,base);
			}
		}
	}
	*this = ans;
	return *this;
}


//----------------------------------------------------
//* Operator overloading, non-member functions
//----------------------------------------------------


//Call the += function above to compute a BigInt whose value is a + b
BigInt operator + (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt ans = a;
	ans += b;
	return ans;
}
//Call the -= function above to compute a BigInt whose value is a - b
BigInt operator - (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt ans = a;
	ans -= b;
	return ans;
}
//Call the *= function above to compute a BigInt whose value is a * b
BigInt operator * (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt ans = a;
	ans *= b;
	return ans;
}

//Call the /= function above to compute a BigInt whose value is a / b
BigInt operator / (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt ans = a;
	ans /= b;
	return ans;
}

//Call the %= function above to compute a BigInt whose value is a % b
BigInt operator % (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt ans = a;
	ans %= b;
	return ans;
}
//Call the exponentiation function above to compute a BigInt whose value is pow(a,b)
BigInt pow(const  BigInt &a, const BigInt & b){

    /************* You complete *************/
	BigInt ans = a;
	ans.exponentiation(b);
	return ans;
}

//Call the modulusExp function above to compute a BigInt whose value is (a ^ b) mod c
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    /************* You complete *************/
	BigInt ans = a;
	ans.modulusExp(b,m);
	return ans;
}

//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if(a.compare(b)==-1)
		return true;
	return false;
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if(a.compare(b)==0)
		return false;
	return true;
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if(a.compare(b)==1)
		return false;
	return true;
}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if(a.compare(b)==-1)
		return false;
	return true;
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if(a.compare(b)==1)
		return true;
	return false;
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
	if(a.compare(b)==-1)
		return true;
	return false;
}