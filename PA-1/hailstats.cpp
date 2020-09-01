/********************************************************
 * CS 103 PA 1: Hailstats
 * Name: Andrea Lee
 * USC email: alee9707@usc.edu
 * Comments (you want us to know):
 *
 * Description:
   * Performs the hailstone conjecture through a range of numbers
     * if it is even divide by two
     * if it is odd, multiply it by there then add one
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Declare variables
  int num, length;
  int start, end, min, max, minLength=100, maxLength=0;
  
  // Take in input
  cout << "Enter the range that you want to search:" << endl;
  cin >> start >> end;
  
  // Invalid Range
  if(start>end){
    cout << "Invalid Range" << endl;
    return 0;
  }
  
  // Run the number through the hailstone conjecture
  for(int i=start; i<= end; i++){
    num = i;
    length = 0;
    
    // In the case that i is one
    if(num==1){
      length = 0;
    }
    
    // Running
    while(num!=1){
      if(num%2==1){
        num = (3*num) + 1;
        length++;
      }
      else{
        num = num/2;
        length++;
      }
    }
    
    // Set the max and mins
    if(length>maxLength){
      maxLength = length;
      max = i;
    }
    if(length<minLength){
      minLength = length;
      min = i;
    }
  }
  
  // Print the final output
  cout << "Minimum length: " << minLength << endl;
  cout << "Achieved by: " << min << endl;
  cout << "Maximum length: " << maxLength << endl;
  cout << "Achieved by: " << max << endl;
  
  return 0;

}
