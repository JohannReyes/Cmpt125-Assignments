#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "question1.h"

/*
CMPT 125 Assignment 3 Question 1
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This takes an array of strings and uses quick sort to sort the strings by length or by aplhabetical order
*/

int partitionLength(char* stringArray[], int start, int end){
  int pivot = strlen(stringArray[end]), i2 = start-1; //i2 is switching index
  char* temp;
  
  for(int i=start; i<=end-1; i++)  //i is index for comparing each string 
  {
    if( pivot > strlen(stringArray[i]) )
    {
      i2+=1;
      temp = stringArray[i2];
      stringArray[i2] = stringArray[i];
      stringArray[i] = temp;
    }
  }
  temp = stringArray[i2+1];
  stringArray[i2+1] = stringArray[end];
  stringArray[end] = temp;

  return (i2+1);
}

int partitionAlpha(char* stringArray[], int start, int end){
  char* pivot = stringArray[end];
  char* temp;
  int i2 = start-1; //i2 is switching index

  for(int i=start; i<=end-1; i++)  //i is index for comparing each string 
  {
    for(int i3=0; i3<63; i3++)  //i3 is index for each charater in the word
    {
      if( pivot[i3] != stringArray[i][i3] )
      {
        if( pivot[i3] > stringArray[i][i3])
        {
          i2+=1;
          temp = stringArray[i2];
          stringArray[i2] = stringArray[i];
          stringArray[i] = temp;
        }
        break;
      } 
    }
  }
  temp = stringArray[i2+1];
  stringArray[i2+1] = stringArray[end];
  stringArray[end] = temp;

  return (i2+1);
}

void quicksort(char* stringArray[], int start, int end, bool cond){
  if(end>start)
  {
    int partIndex;
    if(cond == true)  //sort by length  
    {
      partIndex = partitionLength(stringArray, start, end);
    }
    else if(cond == false)  //sort alphabetically 
    {
      partIndex = partitionAlpha(stringArray, start, end);
    }

    quicksort(stringArray, start, partIndex-1, cond); //left side
    quicksort(stringArray, partIndex+1, end, cond); //right side
  }
}

void quicksort_cstrings(char* stringArray[], int size, bool byLength){
  quicksort(stringArray, 0, size-1, byLength);
}
