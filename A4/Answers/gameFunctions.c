#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gameObjects.h"
#include "card_LList.h"
#include "gameFunctions.h"

/*
CMPT 125 Assignment 4 gameFunctions.c
Author: Johann Reyes
Student ID: 301443359 
SFU email: jra81@sfu.ca 
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This is the source code for the game. In implements the main
function that is the driver of the program. In also includes a clear function
that attemps to "push" the face up print up beyond the screen.
Purpose: This code is contains the fcns that help run the main frame of the game. These inlcude check fncs that decide whether 
player inputs are valid, as well as checking if the player has chosen cards that match or not. This also adds the won cards the the
players win pile and also checks hwo many cards are still left in play, hence checking whether the game is over or not.
*/

//a function that adds the card to the player's winning pile by calling
// the appropriate function from card_LList and update the cards won.
// Also marks the card as taken ('0').
void addCardToPlayer(Player* thePlayer, Card* theCard){

	insertEndCard_LList(&thePlayer->winPile, theCard);	// inserts theCard to the linked list of Player
	thePlayer->cardsWon = thePlayer->cardsWon + 1;		// add 1 to cardsWon
	theCard->value = '0';								// sets the value of the Card as 0, indicating it has been taken
}

//a function that checks if the user choice is valid:
// if any of the choices are invalid, report that and return false.
bool checkPlayerInput(Deck* theDeck, Player* thePlayer, char row, char col){

	if( row<48 || row>51)		// validating row	0->3
	{
		printf("Error: The card you picked has invalid index(es)\n");
		return false;
	}
	if( col<97 || col>109)		// validating col	a->m
	{
		printf("Error: The card you picked has invalid index(es)\n");
		return false;
	}
	if( theDeck->cards[(row-48)*13 + (col-97)].value == 48)	// 48 is '0' in char, checking if the card has already been taken
	{
		printf("Error: The card you picked is already taken\n");
		return false;
	}

	return true;
}

//a function that checks if there is a match:
// if the two choices are the same, report it and return false.
// if there is a match, return true; otherwise, return false.
bool checkForMatch(Deck* theDeck, Player* thePlayer, char r1, char c1, char r2, char c2){

	if(theDeck->cards[(r1-48)*13 + (c1-97)].value == theDeck->cards[(r2-48)*13 + (c2-97)].value && theDeck->cards[(r1-48)*13 + (c1-97)].suit == theDeck->cards[(r2-48)*13 + (c2-97)].suit)
	{
		// checks if both value and suit of card are the same, hence making it a match
		printf("Error: Both cards are the same\n");
		return false;
	}
	if(theDeck->cards[(r1-48)*13 + (c1-97)].value == theDeck->cards[(r2-48)*13 + (c2-97)].value) // checks if both values are the same
	{
		return true;	// its a match, player wins card
	}

	return false;
}

//a function that checks if the game has a winner
// (all cards in the deck is taken)
bool checkForWinner(const Deck* theDeck){

	int i2=Spades;
  	for(int i=0; i<NUM_OF_CARDS_IN_DECK; i++)
  	{
  		if(theDeck->cards[i].value != 48)	// checking if value of card is not taken, hence !=0 or 48 in char
   		{
   			return false;
   		}
    	if( (i+1)%13 == 0 )
    	{
      		i2+=1;
    	}
  	}

  	return true;
}