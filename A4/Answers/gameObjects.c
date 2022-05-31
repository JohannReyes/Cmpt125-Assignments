#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gameObjects.h"
#include "card_LList.h"

/*
CMPT 125 Assignment 4 gameObjects.c
Author: Johann Reyes
Student ID: 301443359 
SFU email: jra81@sfu.ca 
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This is the source code for the game. In implements the main
function that is the driver of the program. In also includes a clear function
that attemps to "push" the face up print up beyond the screen.
Purpose: This code contains all the fcns for the game objects, i.e. the cards. This include preseting the deck and shuffleing
them, as well as printing the deck face up/down and initializing the 2 players and making/clearing thier win piles.
*/

//a function that initializes all the fields of a Deck.
// For each suit, the values of the cards are
// ‘A’, ‘2’, ‘3’, …, ‘9’, ,'T', ‘J’, ‘Q’, ‘K’.
void initializeDeck(Deck* theDeck, char* brandName){
	
	  theDeck->brand = brandName;
  	char face[13] = {"A23456789TJQK"};  //value of each card
  	int i2=Spades;
  	for(int i=0; i<NUM_OF_CARDS_IN_DECK; i++)
  	{
    	theDeck->cards[i].suit = i2;
    	theDeck->cards[i].value = face[i%13];
    	if( (i+1)%13 == 0 )
    	{
      		i2+=1;
    	}
  	}

}

//a function that shuffles the deck
void shuffleDeck(Deck* theDeck){

    for(int i=0; i<NUM_OF_CARDS_IN_DECK-1; i++)
    {
      int j = i + rand() / (RAND_MAX / (NUM_OF_CARDS_IN_DECK - i) + 1);
      int suit = theDeck->cards[i].suit;  //temp suit
      char face = theDeck->cards[i].value;  //temp value

      theDeck->cards[i].suit = theDeck->cards[j].suit;  //switch i with j
      theDeck->cards[i].value = theDeck->cards[j].value;

      theDeck->cards[j].suit = suit;  //switch j with i(temp)
      theDeck->cards[j].value = face;
    }
}

//a function that prints the content of a Deck.
//accepts a second bool parameter:
//if true, print face up, if false, print face down.
//if the card is won by a player, leave it blank.
void printDeck(const Deck* theDeck, bool faceUp){
    
    char* suit[4] = {"\u2660","\u2661","\u2663","\u2662"};  //suit symbols represented by Suit enum index
    
    for(int i=97; i<110; i++)  // letters for table
    {
      if(i == 97)
      {
        printf("   %c", i);
      }
      else
      {
        printf("  %c", i);
      }
    }
    printf("\n");
    
    for(int i=0; i<NUM_OF_CARDS_IN_DECK; i++)
    {
      if( (i)%13 == 0 )
      {
        printf("%d ", i/13);  // numbers for table
      }

      if(faceUp == true)
      {
        printf("%c%s ", theDeck->cards[i].value, suit[theDeck->cards[i].suit]);  // face up
      }
      else	// face down
      {
      	if(theDeck->cards[i].value == 48)
      	{
      		printf("   ");	// print nothing since the card has already been taken
      	}
      	else
      	{
      		printf("%c\u218C ", '?');  // print card face down
      	}  
      }
      
      if( (i+1)%13 == 0 )
      {
        printf("\n");
      }
    }
    
}

//a function that initializes all the fields of a Player.
void initializePlayer(Player* thePlayer, char* theName){

    thePlayer->name = theName;
    thePlayer->cardsWon = 0;
    thePlayer->winPile.head = NULL;
    thePlayer->winPile.tail = NULL;
}

//a function clears the winning pile of the player by calling the necessary
// function on a Card_LList.
void clearPlayer(Player* thePlayer){

    clearCard_LList(&thePlayer->winPile);
}
