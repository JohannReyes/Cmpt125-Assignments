#include <stdio.h>
#include "question2.h"
/*
CMPT 125 Assignment 2 Question 2
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: The first function foo_recursive is a function that executes the fibonacci sequence with extra parts recursively. The second function foo_fast does the same thing as foo_recursive expect it executes it using a for loop instead of recursion.
*/

// foo(30) runs 2692537 times
//static int counter=0;

unsigned long foo_recursive(unsigned long n){
  //counter +=1;

  if(n==0)
  {
    return 1;
  }
  else if(n==1)
  {
    return 2;
  }
  else
  {
    return 2 * foo_recursive(n-2) + foo_recursive(n-1) + n + 2;
  }
}

unsigned long foo_fast(unsigned long n){
  
  unsigned long total, n1=1,n2=2;

  if(n==0)
  {
    return 1;
  }
  else if(n==1)
  {
    return 2;
  }
  else
  {
    for(int i=2; i<=n; i++)
    {
      total = (2*n1) + n2 + i +2;
      n1 = n2;
      n2 = total;
    }
    
    return total;
  }
}
