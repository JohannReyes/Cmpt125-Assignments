#include "question4.h"
/*
CMPT 125 Assignment 1 Question 4
Johann Reyes
301443359
jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).

This program takes in a string containing a mathematical operation and returns the number resulting of the operation
*/
int performMathOp(char* operation) {

  int num1=0, num2=0, symbol, counter=-1, num, i =0;

  while(operation[i] != '\0') //runs through the string seperating num1, num2 and symbol into thier own variables
  {
    if(operation[i]<48)
    {
      symbol = operation[i];
      counter = 0;
    }
    else if(counter>=0)
    {
      num2 = num2*10;
      num2 = num2 + (operation[i]-48);
    }
    else
    {
      num1 = num1*10;
      num1 = num1 + (operation[i]-48);
    }
    i+=1;
  }

  if(symbol==43) //checks to see which operation is to be used (-, +, *)
  {
    num = num1+num2;
  }
  else if(symbol==45)
  {
    num = num1-num2;
  }
  else
  {
    num = num1*num2;
  }

  return num;
}
