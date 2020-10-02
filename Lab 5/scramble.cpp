/*
CSCI 103 Lab 5: Scramble
Name: Andrea Lee
Email: alee9707@usc.edu

Description:
Word Scramble guessing game
Illustrates string library functions, character arrays,
arrays of pointers, etc.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Scramble the letters of this string randomly
void permute(char items[], int len);

/* Delete the array below and replace by reading in words from a file 
   in main() */
//const char* wordBank[] = {
   //"computer", "president", "trojan", "program", "coffee",
   //"library", "football", "popcorn", "science", "engineer"};

const int numWords = 10;

int main(int argc, char* argv[]) {
  srand(time(0));
  char guess[80];
  char buffer[41];

  bool wordGuessed = false;
  int numTurns = 10;
  
  if(argc<2){
    cout << "Not enough command line arguments" << endl;
    return 1;
  }
  
  ifstream infile(argv[1]);

  // Check to open the file 
  if(!infile.is_open()){
    cout << "Could not open the file" << endl;
    return 1;
  }
  // Check to read an integer from the file 
  int num;
  infile >> num;
  if(infile.fail()){
    cout << "Could not read the integer" << endl;
    return 1;
  }
  /* Add code to declare the wordBank array, read in each word
     and store it */
  char** wordBank = new char* [num];
  // reading in each word & copming it into wordBank
  int i=0;
  while(infile>>buffer){
    int len = strlen(buffer);
    wordBank[i] = new char [len + 1];
    strcpy(wordBank[i], buffer);
    i++;
  }
  // Close the file
  infile.close();
  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (!wordGuessed && numTurns > 0) {
    cout << "Scrambled word: " << word << endl;
    cout << "What do you guess the original word is? ";
    cin >> guess;
    /* Complete the next line of code */
    if(strcmp(word, guess)==0){
      wordGuessed = true; // ADD code to check if the guess is equal to the chosen word.
                          // wordGuessed should be true if they are equal, and false otherwise
        
    }  
 
    numTurns--;   // Every guess counts as a turn
  }
  if (wordGuessed) {
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  /* Free up any necessary memory */
  delete [] word;
  delete [] wordBank;
  return 0;
}

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}


