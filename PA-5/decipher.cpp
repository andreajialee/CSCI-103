#include "bigint.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout<<"\033[1;41m----Missing an argument----\033[0m"<<endl;
	    cout << "Usage: ./decipher <file>"<<endl;
	    cout << "Examples:" << endl;
	    cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message 1\033[0m" << endl;
	    cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message 2\033[0m"<<endl;
		return -1;
	}

	/************* You complete *************/
ifstream input(argv[1]);
    if(input.fail())
        cout << "Error" << endl;
    
    int base;
    string d, n, secret;
    BigInt D, N, SEC, temp;
    try{
        input >> base >> d >> n;
        D = BigInt(d,base);
        N = BigInt(n,base);
        BigInt temp(base);
    }
    catch(const exception& a){
        cout << a.what() << endl;
        return -1;
    }
    try{
        while(true){
            if(input.eof())
                break;
            input >> secret;
            BigInt SEC(secret,base);
            temp = modPow(SEC,D,N);
            cout << (char)(temp.to_int());
        }
        cout << endl;
    }
    catch(const exception& b){
        cout << b.what() << endl;
        return -1;
    }

	return 0;
}
