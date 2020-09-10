/********************************************************
 * CS 103 Lab 3: Shapes
 * Name: Andrea Lee
 * USC email: alee9707@usc.edu
 *
 * Description:
 * This code takes in input from the user and prints out the
 * rectangle function if a 0 is inputted, the ellipse function
 * if a 1 is inputted, and saves the image if a 2 is inputted.
 ********************************************************/

#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
  for(int i=top; i<=top+height; i++){
    if(i>=0 && i<=255){ // Check if it is in bounds
      for(int j=left; j<=left+width; j++){
        if(j>=0 && j<=255){ // Check if it is in bounds
          // Print Top & Bottom
          if(i==top||i==top+height){
            image[i][j]=0;
          }
          // Print Left & Right
          else if(j==left||j==left+width){
            image[i][j]=0;
          }
        }
      }
    }
  }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
  // Find radius
  double rx = width/2.0; 
  double ry = height/2.0;
  // Goes from 0 to 2pi
  for(double a=0; a<=(2*M_PI); a+=.01){
    // x-coordinate -> (length = xcos(theta))
    // begins at the left -> x = left + length/2
    int x = cx + (int)(rx*cos(a));
    // y-coordinate -> (height = ycos(theta))
    // begins at the top -> y = top - height/2
    int y = cy - (int)(ry*sin(a));
    
    // Check if it is in bounds & print
    if(x>=0 && x<=255 && y>=0 && y<=255){
      image[y][x] = 0;
    }
    
  }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
  
   // Main program loop here
  int pick = 0, a, b, c, d;
  
  // Prompt the user
  cout << "To a draw a rectangle, enter: 0 top left height width" << endl;
  cout << "To a draw an ellipse, enter: 1 cy cx height width" << endl;
  cout << "To save your drawing as \"output.bmp\" and quit, enter:2" << endl;
  
  // If pick != 2, then run through other options
  while(pick!=2){
    cin >> pick;
    switch(pick){
      // Draw Rectangle
      case 0:
        cin >> a >> b >> c >> d;
        draw_rectangle(a, b, c, d);
        break;
      // Draw Ellipse
      case 1:
        cin >> a >> b >> c >> d;
        draw_ellipse(a, b, c, d);
        break;
      // Exit & Save
      case 2:
        break;  
    }
  }
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
