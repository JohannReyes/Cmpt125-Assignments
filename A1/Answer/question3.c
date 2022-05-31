#include "question3.h"
/*
CMPT 125 Assignment 1 Question 3
Johann Reyes
301443359
jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).

This program takes a matrix and subtracts a chosen row from another chosen row
*/
void rowSubtraction(unsigned int rows, unsigned int columns,
    int matrix[rows][columns], unsigned int row1, unsigned int row2) {

  if(row1<rows && row2<rows) // checks if the the rows inputed are valid
  {
    for(int i=0; i<columns; i++) // subtracts the two rows
    {
      matrix[row1][i] = matrix[row1][i] - matrix[row2][i];
    }
  }

}
