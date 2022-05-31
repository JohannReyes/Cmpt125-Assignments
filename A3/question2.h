#ifndef A3_Q2_H
#define A3_Q2_H

#include <stdlib.h> //for the use of srand and rand
#include <stdio.h>

#define NUM_OF_CARDS_IN_DECK 52

typedef enum {Spades, Hearts, Clubs, Diamonds} Suit;

typedef struct {
    Suit suit;
    char value;
} Card;

typedef struct {
    char* brand; //c string storing the brand name
    Card cards[NUM_OF_CARDS_IN_DECK]; //a deck has 52 cards
} Deck;

//a function that initializes all the fields of a Deck.
// For each suit, the values of the cards are
// ‘A’, ‘2’, ‘3’, …, ‘9’, ,'T', ‘J’, ‘Q’, ‘K’.
void initializeDeck(Deck* theDeck, char* brandName);

//a function that shuffles the deck
void shuffleDeck(Deck* theDeck);

//a function that prints the content of a Deck.
void printDeck(const Deck* theDeck);

#endif
