/********************************************************
 * CS 103 PA 1: Diceplot
 * Name: Andrea Lee
 * USC email: alee9707@usc.edu
 *
 * Description:
 * This code simulates 500 rolls of 4-dice and 
 ********************************************************/

#include <iostream>
#include <cmath>
#include <ctime> 
#include <cstdlib>
using namespace std;

// Roll the dice for a random number
int roll(){
   int random = rand() % 6 + 1;
   return random;
}

// Print the Histogram
void printHistogram(int counts[21]){
  for(int i=0; i<21; i++){
    cout << i+4 << ": ";
    for(int j=0; j<counts[i]; j++){
      cout << "x";
    }
    cout << endl;
  }
}

 int main(){
   srand(time(0));
   int n = 0;
   int nums[21];
   
   // Call for the input
   cout << "Enter a number: " << endl;
   cin >> n;
   
   // Initialize the array
   for(int i=0; i<21; i++){
     nums[i] = 0;
   }
   
   // Run n expirements
   for(int i=0; i<n; i++){
     // Reset sum as 0 every time
     int sum = 0;
     // Rolls the dice four times and adds the sum
     for(int j=0; j<4; j++){
       sum+=roll();
     }
     // Tally the x for that sum value
     nums[sum-4] = ++nums[sum-4];
   }
   
   // Print the histogram
   printHistogram(nums);
   
   return 0;
}
