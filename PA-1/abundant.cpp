/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Andrea
 * USC email: alee9707@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0; 

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
  
  // Take in input
  int num, sum;
  
  // Begin the loop
  while(cin>>num && num!=0){
    
    sum = 0;
  
    // Find the sum of the num's divisors
    for(int i=1; i<num; i++){
      if(num%i==0){
        sum+=i;
      }
    }
   
    // Check for abundance
    if(num<sum){
      num_abundant++;
      
      // Set the largest 3 abundant numbers' sums
      if(sum>a3){
        
        // If the sum is larger than a1
        if(sum>a1){
          a3 = a2; n3 = n2;
          a2 = a1; n2 = n1;
          a1 = sum; n1 = num;
        }
        
        // If the sum is larger than a2
        else if(sum>a2){
          a3 = a2; n3 = n2;
          a2 = sum; n2 = num;
        }
        
        // If the sum is larger than a3
        else{
          a3 = sum; n3 = num;
        }
       
      }
    }
  }   
    
  /* End of your code */

  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
