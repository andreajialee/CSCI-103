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
// 	print_maze(mymaze, rows, cols);

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
	Location start;
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
				cfinish++;
			}
		}
	}
	if(cstart!=1||cfinish!=1){
		return -1;
	}
	// Create queue
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
 	visited[start.row][start.col] = 1;
	
	// 2D Array: predecessor
	Location ** predecessor = new Location*[rows];
	for(int i=0; i<rows; i++){
		predecessor[i] = new Location[cols];
	}
	
	int cRow, cCol;
	while(!q.is_empty() && pathFound == false){
		Location curr = q.remove_from_front();
		
		// Neighbors of current
		Location n, e, s, w;
		n.row = curr.row-1; n.col = curr.col;
		s.row = curr.row+1; s.col = curr.col;
		e.row = curr.row; e.col = curr.col+1;
		w.row = curr.row; w.col = curr.col-1;
		// Create array of neighbors
		Location nb[4] = {n, s, e, w};
		// Check neighbors
		for(int i=0; i<4; i++){
			int nRow = nb[i].row;
			int nCol = nb[i].col;
			// Check Bounds
			if(nRow>=0 && nRow<rows && nCol>=0
				 && nCol<cols && visited[nRow][nCol]==0){ 
				// If '.' 
				if(maze[nRow][nCol]=='.'){ 
					q.add_to_back(nb[i]); // add neighbor to back
 					visited[nRow][nCol] = 1; // mark visited
					predecessor[nRow][nCol] = curr; // set predecessor to current
				}
				// If at endpoint
				else if(maze[nRow][nCol]=='F'){
					cRow = curr.row; cCol = curr.col;
					visited[nRow][nCol] = 1; // mark that it was visited
					predecessor[nRow][nCol] = curr; // set predecessor to current
					pathFound = true;
					}
				}
			}
		}
		if(pathFound==true){
			while(maze[cRow][cCol]!='S'){
				maze[cRow][cCol] = '*';
				int temp = cRow;
				int temp2 = cCol;
				cRow = predecessor[temp][temp2].row;
				cCol = predecessor[temp][temp2].col;
			}
		}

	// Deallocate Memory
	for(int i=0; i<rows; i++){
			delete [] predecessor[i];
			delete [] visited[i];
	}
	delete [] predecessor;
	delete [] visited;

	// Return whether or not path was found
	if(pathFound==true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
