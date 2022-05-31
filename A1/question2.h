#ifndef A1_Q2_H
#define A1_Q2_H

#include <stdio.h>

//takes in 3 parameters: an int array, its size, an int called “target”,
// and a char array of size 32
//Puts a cstring in the format A+B to that char array, where A and B are the
// indexes of a pair of elements in the int array that add up to the target
// value. Puts the cstring not_found in the char array if no such pair exists.
void findPair(int array[], unsigned int size, int target, char* result);

#endif
