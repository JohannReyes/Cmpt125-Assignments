#include "question2.h"
/*
CMPT 125 Assignment 1 Question 2
Johann Reyes
301443359
jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).

This program takes a specific target and returns the two array postions that sum up to that target
*/
void findPair(int array[], unsigned int size, int target, char* result) {

  char A, B;
  int check=0;

  for(int i=0; i<size; i++)  //goes through the array looking for two numbers that sum up tp the target 
  {
    for(int b=i+1; b<size; b++)
    {
      if(array[i]+array[b] == target)
      {
        A = i + '0';
        B = b + '0';
        check =1;
      }
    }
  }

  if(check==1) //condition to output the correct asnwer 
  {
    sprintf(result, "%c+%c", A, B);
  }
  else
  {
    sprintf(result, "not_found");
  }
 
}
