/* 
maze.cpp

Author: Andrea Lee

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
  
   mymaze = read_maze(argv[1], &rows, &cols); // FILL THIS IN 
   //print_maze(mymaze, rows, cols);
	
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }
  
   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
  for(int i=0; i<rows; i++){
    delete[] mymaze[i];
  }
  delete[] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
	Location start, finish;
	int cstart = 0;
	int cfinish = 0;
	bool pathFound = false;
	
	// Checks for starts and finishes
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(maze[i][j]=='S'){
				start.row = i;
				start.col = j;
				cstart++;
			}
			else if(maze[i][j]=='F'){
				finish.row = i;
				finish.row = j;
				cfinish++;
			}
		}
	}
	if(cstart!=1||cfinish!=1){
		return -1;
	}
	
	// Create q and add start to the back
	Queue q = Queue(rows * cols);
	q.add_to_back(start);
	
	// 2D Array: visited
	int ** visited = new int*[rows];
	for(int i=0; i<rows; i++){
		visited[i] = new int[cols];
	}
	// Initialize the array at 0
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			visited[i][j] = 0;
		}
	}
	// Mark the start as visited
	visited[start.row][start.col]=1;
	
	// 2D Array: predecessor
	Location startPrev;
	startPrev.row = -1;
	startPrev.col = -1;
	
	Location ** predecessor = new Location*[rows];
	for(int i=0; i<rows; i++){
		predecessor[i] = new Location[cols];
	}
	// Initialize predecessor at -1 * -1
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			predecessor[i][j] = startPrev;
		}
	}
	
	while(!q.is_empty()){
		Location curr = q.remove_from_front();

		// One Above
		Location oneAbove;
		oneAbove.row = curr.row-1;
		oneAbove.col = curr.col;
		if(oneAbove.row>=0 && oneAbove.row<rows
			 && oneAbove.col>=0 && oneAbove.col<cols)
		{
			if(maze[oneAbove.row][oneAbove.col] =='F')
			{
				while(maze[curr.row][curr.col]!='S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				pathFound = true;
				break;
			}
			else if(maze[oneAbove.row][oneAbove.col] == '.'
						&& visited[oneAbove.row][oneAbove.col] == 0)
			{
				visited[oneAbove.row][oneAbove.col] = 1;
				predecessor[oneAbove.row][oneAbove.col] = curr;
				q.add_to_back(oneAbove);
			}
		}
		
		// One Left
		Location oneLeft;
		oneLeft.row = curr.row;
		oneLeft.col = curr.col-1;
		if(oneLeft.row>=0 && oneLeft.row<rows
			 && oneLeft.col>=0 && oneLeft.col<cols)
		{
			if(maze[oneLeft.row][oneLeft.col] =='F')
			{
				while(maze[curr.row][curr.col]!='S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				pathFound = true;
				break;
			}
			else if(maze[oneLeft.row][oneLeft.col] == '.'
						&& visited[oneLeft.row][oneLeft.col] == 0)
			{
				visited[oneLeft.row][oneLeft.col] = 1;
				predecessor[oneLeft.row][oneLeft.col] = curr;
				q.add_to_back(oneLeft);
			}
		}
		
		// One Below
		Location oneBelow;
		oneBelow.row = curr.row+1;
		oneBelow.col = curr.col;
		if(oneBelow.row>=0 && oneBelow.row<rows
			 && oneBelow.col>=0 && oneBelow.col<cols)
		{
			if(maze[oneBelow.row][oneBelow.col] =='F')
			{
				while(maze[curr.row][curr.col]!='S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				pathFound = true;
				break;
			}
			else if(maze[oneBelow.row][oneBelow.col] == '.'
						&& visited[oneBelow.row][oneBelow.col] == 0)
			{
				visited[oneBelow.row][oneBelow.col] = 1;
				predecessor[oneBelow.row][oneBelow.col] = curr;
				q.add_to_back(oneBelow);
			}
		}
		
		// One Right
		Location oneRight;
		oneRight.row = curr.row;
		oneRight.col = curr.col+1;
		if(oneRight.row>=0 && oneRight.row<rows
			 && oneRight.col>=0 && oneRight.col<cols)
		{
			if(maze[oneRight.row][oneRight.col] =='F')
			{
				while(maze[curr.row][curr.col]!='S')
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				pathFound = true;
				break;
			}
			else if(maze[oneRight.row][oneRight.col] == '.'
						&& visited[oneRight.row][oneRight.col] == 0)
			{
				visited[oneRight.row][oneRight.col] = 1;
				predecessor[oneRight.row][oneRight.col] = curr;
				q.add_to_back(oneRight);
			}
		}
   
		// Deallocate memory
		for(int i=0; i<rows; i++){
			delete [] predecessor[i];
			delete [] visited[i];
		}
		delete [] predecessor;
		delete [] visited;
		
		if(pathFound==true)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
