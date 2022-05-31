#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "question4.h"
/*
CMPT 125 Assignment 2 Question 4
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This program asks the user to input a number of words into the program. The program then sorts the # of words in ascending alphabetical order using bubble sort and then outputs the meadian of the words.
*/

void sortAscending(char* stringArray[], unsigned int size){
  char* temp;
  for(int i=0; i<size; i++)
  {
    for(int i2=i+1; i2<size; i2++)
    {
      for(int i3=0; i3<64; i3++)
      {
        if(stringArray[i][i3] != stringArray[i2][i3])
        {
          if(stringArray[i][i3] > stringArray[i2][i3])
          {
            temp = stringArray[i];
            stringArray[i] = stringArray[i2]; 
            stringArray[i2] = temp;
          }
          break;
        }
      }
    }
  }
}

char* getMedian(char* stringArray[], unsigned int size){
  unsigned int median;
  
  sortAscending(stringArray, size);
  if(size%2 != 0)    
  {
    median = (size-1)/2;
  }
  else
  {
    median = size/2;
  }
  
  return stringArray[median];
}
