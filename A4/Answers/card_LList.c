#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "card_LList.h"

/*
CMPT 125 Assignment 4 card_LList.c
Author: Johann Reyes
Student ID: 301443359 
SFU email: jra81@sfu.ca 
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This is the source code for the game. In implements the main
function that is the driver of the program. In also includes a clear function
that attemps to "push" the face up print up beyond the screen.
Purpose: This code contains all the fcns for editing the win pile of each player, their linked lists of cards won. These include
fcns that creates their linked list and adds the cards they have won through out the game to the linked lists and also a fcn
that clears their linked list at the end of the game.
*/

//a function that creates a new Card_LList, which is an empty linked list.
Card_LList* createCard_LList(){
    
    Card_LList* cardList = malloc( sizeof(Card_LList) );  //giving initial memory
    if(cardList == NULL)  // checking if malloc was valid
    {
      exit(0);
    }
    cardList->head = NULL;
    cardList->tail = NULL;
    
    return cardList;
}

//a function that removes all the nodes from the list
// by freeing them one by one. The result is an empty linked list.
void clearCard_LList(Card_LList* theList){

    Card_Node* node = theList->head;
    
    while(node != NULL)
    {
      Card_Node* next = node->next;
      free(node);
      node = next;
    }
    
    theList->head = NULL;
    theList->tail = NULL;
}

//a function that checks if the list is empty.
// If it is empty, return true; otherwise return false.
bool isEmptyCard_LList(Card_LList* theList){
    
    if( theList == NULL || (theList->head == NULL && theList->tail == NULL) )  // checking if empty
    {
      return true;
    }
    
    return false;
}

//a function that inserts the card as a part of a node
// (the node itself doesn't store the card, but the address of the card).
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
void insertFrontCard_LList(Card_LList* theList, Card* theCard){

	  Card_Node* node = malloc(sizeof(Card_Node));  // making card_node for theCard
    if(node == NULL)                              // validity check
    {
      printf("insertFrontCard: node is NULL, malloc failed\n");
      exit(0);
    }
    node->card = theCard;
    
    if(theList->tail == NULL)    
    {
      theList->tail = node;  // if tail is NULL, then we must make tail = theCard (this is if the list is empty)
    }
    
    if(theList->head != NULL)
    {
      node->next = theList->head;  // if the list is not empty i.e. head != NULL, then set the current head to the second value
    }
    
    theList->head = node;    // puts theCard at the front of the list
}

//a function that inserts the card as a part of a node
// (the node itself doesn't store the card, but the address of the card).
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
void insertEndCard_LList(Card_LList* theList, Card* theCard){

    Card_Node* node = malloc(sizeof(Card_Node));  // making card_node for theCard
    if(node == NULL)                              // validity check
    {
      printf("insertFrontCard: node is NULL, malloc failed\n");
      exit(0);
    }
    node->card = theCard;
    node->next = NULL;
    
    if(theList->head == NULL)    
    {
      theList->head = node;  // if head is NULL, then we must make head = theCard (this is if the list is empty)
    }
    
    if(theList->tail != NULL)
    {
      theList->tail->next = node;  // if the list is not empty i.e. tail != NULL, then set the current tail->next to the new Card
    }
    
    theList->tail = node;    // puts theCard at the end of the list
}

//a function that returns the address of the card stored in the node.
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
// Freeing of the node memory is done here.
Card* removeFrontCard_LList(Card_LList* theList){

	Card_Node* front = theList->head;		// gets the front card in linked list

	free(theList->head);					// frees the head node
	theList->head = theList->head->next;	// this makes the second card on the list the new first card, i.e. the new head

	return front->card;
}

//a function that returns the address of the card stored in the node.
// This method encapsulates the inner workings of the linked list and
// there is no need to duplicate the card.
// Freeing of the node memory is done here.
Card* removeEndCard_LList(Card_LList* theList){

	Card_Node* end = theList->tail;		// gets the end card in linked list

	Card_Node* node = theList->head;
    while(node->next != NULL)
    {
      Card_Node* next = node->next;
      if(next->next == NULL)		// checks if Node* next is on tail
      {
      	theList->tail = node;		// makes the second last card on the list the new tail
      	theList->tail->next = NULL;
      }
      node = next;
    }
    free(node);				// frees the tail node

	return end->card;
}