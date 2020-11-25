// queue.o
/* 
mazeio.cpp

Author: Andrea Lee

Short description of this file:
*/

#include <iostream>
#include <fstream>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from the given filename into a 
 *  2D dynamically  allocated array.
 * 
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem, 
 * opening the file or reading in the integer sizes.
 *
 * The first argument is the filename of the maze input.
 *  You should use an ifstream to open and read from this
 *  file.
 *
 * We also pass in two pointers to integers. These are
 * output parameters (i.e. declared by the caller and 
 * passed-by-reference for this function to fill in).
 * Fill the integers pointed to by these arguments
 * with the number of rows and columns 
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(char* filename, int* rows, int* cols) 
{
	// Open filename
	ifstream file;
	file.open(filename);
	if(!file.is_open()){
		return NULL;
	}
	// Read in first two nuns of the file 
	int row; int col;
	file >> row;
	file >> col;
	if(file.fail()){
		return NULL;
	}
	// Sets pointers to row, col
	*rows = row;
	*cols = col;
	// Make the 2d array 
  char** maze = new char*[row];	
	for(int i=0; i<row; i++){		
		maze[i] = new char[col];
	}
	
	// Read in char
	int i = 0;
	int j = 0;
	char a;
  while(file >> a){
		if(a!='.' && a!='#' && a!='S' && a!='F'){
			return NULL;
		}
		if (a == '\n') {
			continue;
		}
		if(j == col) {
			j = 0;
			i++;
		}
		maze[i][j]=a;
		j++;
	}
	
  file.close();
	
  return maze;
}

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) 
{
   // FILL THIS IN
  cout << rows << " " << cols << endl;
  
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      cout << maze[i][j];
    }
    cout << endl;
  }
  
}


