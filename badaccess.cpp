#include <iostream>
#include "bigint.h"

using namespace std;

int main(){
	BigInt a("1233");
	BigInt b("1938192");
	a.add(b);
	cout << a.vec[1];
	return 0;
}