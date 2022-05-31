#include <stdio.h>
#include "question1.h"
/*
CMPT 125 Assignment 2 Question 1
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This takes a number and interlaces it with zeros inbetween each number recursively 
*/

unsigned int expand_int(unsigned int num){
  unsigned int counter=1, num2=num;

  if(num<10)
  {
    return num;
  }
  else
  {
    while(num/(counter*10) > 0)
    {
      num = num - num%(counter*10);

      counter = counter*10;
    }
    num2 = num2 - num;
  }

  return num*counter + expand_int(num2);
}

