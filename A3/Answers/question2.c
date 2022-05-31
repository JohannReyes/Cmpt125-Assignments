#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "question2.h"

/*
CMPT 125 Assignment 3 Question 2
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This uses the enum of suits and struct of deck and card to initialize a deck of regular playing cards and shuffles
             them randomly using Fisher-Yates shuffle algorithm.
*/

void printDeck(const Deck* theDeck){
  printf("Brand of Deck: %s\n", theDeck->brand);
  char* suit[4] = {"\u2660","\u2661","\u2663","\u2662"};  //suit symbols represented by Suit enum index
  for(int i=0; i<NUM_OF_CARDS_IN_DECK; i++)
  {
    printf("%c%s ", theDeck->cards[i].value, suit[theDeck->cards[i].suit]);
    if( (i+1)%13 == 0 )
    {
      printf("\n");
    }
  }
}

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

void shuffleDeck(Deck* theDeck){
  for(int i=NUM_OF_CARDS_IN_DECK-1; i>0; i--)
  {
    int j = rand()%i; //gets a random int in the range 0<=j<=i
    int suit = theDeck->cards[i].suit;  //temp suit
    char face = theDeck->cards[i].value;  //temp value

    theDeck->cards[i].suit = theDeck->cards[j].suit;  //switch i with j
    theDeck->cards[i].value = theDeck->cards[j].value;

    theDeck->cards[j].suit = suit;  //switch j with i(temp)
    theDeck->cards[j].value = face;
  }
}