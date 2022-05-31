#ifndef A2_Q4_H
#define A2_Q4_H

#include <string.h>

//a function that sorts an array of C strings into ascending alphabetical order
void sortAscending(char* stringArray[], unsigned int size);

//a function that takes in an array of C strings (it can either be sorted or
// unsorted) and returns the address of the “median” .
char* getMedian(char* stringArray[], unsigned int size);

#endif
