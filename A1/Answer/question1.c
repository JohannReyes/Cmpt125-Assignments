#include "question1.h"
/*
Cmpt Assignment 1 Question 1
Johann Reyes
301443359
jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).

This program takes in two integers and interlaces them into one whole integer 
*/
unsigned int interlace_ints(unsigned int firstNum, unsigned int secondNum) {
  int a[9], counter = 1000, num=0;

  a[0] = (secondNum - (secondNum%10000))/10000;   //puts in first digit into array
  secondNum = (secondNum%10000);

  for(int i=1; i<9; i++)  //goes through each digit in each int and puts them all into the array in the correct order
  {
    a[i+1] = (secondNum - (secondNum%counter))/counter;

    a[i] = (firstNum - (firstNum%counter))/counter;

    firstNum = firstNum%counter;
    secondNum = secondNum%counter;
    
    counter = counter/10;
    i += 1;
  }
  
  counter = 100000000;
  for(int i=0; i<9; i++)  //Makes the array into an int
  {
    num += (a[i]*counter);
    counter = counter/10;
  }

  return num;
}
