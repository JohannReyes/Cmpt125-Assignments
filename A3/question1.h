#ifndef A3_Q1_H
#define A3_Q1_H

#include <stdbool.h>
#include <string.h>

//performs quicksort on an array of C strings.
//last variable controls whether the array should be sorted by length or not.
void quicksort_cstrings(char* stringArray[], int size, bool byLength);

#endif
