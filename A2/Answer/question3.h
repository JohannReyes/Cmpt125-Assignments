#ifndef A2_Q3_H
#define A2_Q3_H
/*
CMPT 125 Assignment 2 Question 3
Author: Johann Reyes
Student ID: 301443359
SFU email: jra81@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This uses enum and struct to define a deck of cards
*/

//put your answer here
#define NUM_OF_CARDS_IN_DECK 52

typedef enum Suit {Spades, Hearts, Clubs, Diamonds};

typedef struct Card
{
  Suit suit;
  char value;
};

typedef struct Deck
{
  char* brand;
  Card cards[NUM_OF_CARDS_IN_DECK];
};
#endif

