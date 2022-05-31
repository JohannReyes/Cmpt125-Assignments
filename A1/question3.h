#ifndef A1_Q3_H
#define A1_Q3_H

//takes in the dimensions (rows and columns) of a 2D array of ints and the array
// itself, and performs a row subtraction operation as indicated by 2 other
// parameters representing the row numbers.
//Does not return anything as the change is within the 2D array.
void rowSubtraction(unsigned int rows, unsigned int columns,
    int matrix[rows][columns], unsigned int row1, unsigned int row2);

#endif
