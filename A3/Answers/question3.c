#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "question3.h"

/*
CMPT 125 Assignment 3 Question 3
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This program uses the struct cStringStack to store an array of strings. These strings are inputed/deleted by the user.
			 The program ensures to either give the array more space and memory everytime the user inputs or "pushes" a new string
			 and frees and exces memory when the user deletes or "pops" unwanted strings. Once the user is done editing the array, 
			 the program then outputs the array, both in order and in reverse along with an identical copy of it.
*/

//creates a new stack following the struct defined
//a new stack has size = 0 and items = NULL
cStringStack* cStringStack_create(){
	cStringStack* newstack = malloc(sizeof(cStringStack));
	if(newstack == NULL)
	{
		return NULL;
	}
	newstack->size = 0;
	//newstack->items = NULL;
	newstack->items = malloc( (newstack->size)*sizeof(char*));

	return newstack;
}

//pushes a given C string to the stack,
//you must copy the content instead of just the address
void cStringStack_push(cStringStack* csStack, char* cStr){
	if(csStack == NULL)
	{
		//do nothing since stack itslef is null
	}
	else
	{
		csStack->size = (csStack->size) + 1;
		csStack->items = realloc( csStack->items, (csStack->size)*sizeof(char*) );
		csStack->items[(csStack->size)-1] = malloc(127*sizeof(char));
		strcpy(csStack->items[(csStack->size)-1], cStr);
	}
}

//pops the C string from the stack,
//implemented by returning the address of the C string (copy)
//if the stack has 1 item, once popped it should become the same as a new stack,
//if the stack is empty, return NULL
char* cStringStack_pop(cStringStack* csStack){
	if(csStack == NULL)
	{
		return NULL;
	}
	else if( cStringStack_isEmpty(csStack) == true)
	{
		return NULL;
	}
	char* poppedString = csStack->items[(csStack->size)-1];
	csStack->size = (csStack->size) - 1;
	csStack->items = realloc( csStack->items, (csStack->size)*sizeof(char*));
	return poppedString;
}

//checks if the stack is empty
bool cStringStack_isEmpty(cStringStack* csStack){
	if(csStack->size <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//frees all the memory used by the stack to store the C strings
void cStringStack_free(cStringStack* csStack){
	if(csStack == NULL)
  	{
    	//do nothing, csStack is null pointer
  	}
  	else
  	{
    	free(csStack->items);
    	free(csStack);
  	}
}

//reverse the order of the C strings stored so the first added one
// will be popped first, and so on
void cStringStack_reverse(cStringStack* csStack){
	if(csStack == NULL)
	{
		//do nothing, csStack is null pointer
	}
	else
	{
		for(int i=0; i<(csStack->size)/2; i++)
		{
			char* temp = csStack->items[i];
			csStack->items[i] = csStack->items[(csStack->size)-1-i];
			csStack->items[(csStack->size)-1-i] = temp;
		}
	}
}

//creates a copy of a stack,
//each item has to be a C string with the same content but in different address
cStringStack* cStringStack_duplicate(cStringStack* csStack){
	if(csStack == NULL)
	{
		return NULL;
	}
	cStringStack* copyStack = malloc(sizeof(cStringStack));
	if(copyStack == NULL)
	{
		return NULL;
	}
	copyStack->size = csStack->size;
	copyStack->items = malloc( (csStack->size)*sizeof(char*));
	memcpy( copyStack->items, csStack->items, (copyStack->size) * sizeof(char*) );
  	return copyStack;
}