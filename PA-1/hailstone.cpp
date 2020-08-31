/********************************************************
 * CS 103 PA 1: Halistone
 * Name: Andrea Lee
 * USC email: alee9707@usc.edu
 * Comments (you want us to know):
 *
 * Description:
   * Performs the hailstone conjecture
     * if it is even divide by two
     * if it is odd, multiply it by there then add one
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Declare variables
  int length=0, num;
  
  // Take in input
  cout << "Enter a number:" << endl;
  cin >> num;
  
  // Print 0 if num is 1
  if(num==1){
    cout << "Length: 0" << endl;
    return 0;
  }
  
  // Run the number through the hailstone conjecture
  while(num!=1){
    if(num%2==1){
      num = (3*num) + 1;
      length++;
      cout << num << " ";
    }
    else{
      num = num/2;
      length++;
      cout << num << " ";
    }
  }
  
  cout << endl;
  
  // Print the length
  cout << "Length: " << length << endl;
  
  return 0;

}


