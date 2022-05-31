/*
CMPT 125 Assignment 4 main.c
Author: Johann Reyes
Student ID: 301443359 
SFU email: jra81@sfu.ca 
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: This is the source code for the game. In implements the main
function that is the driver of the program. In also includes a clear function
that attemps to "push" the face up print up beyond the screen.
Purpose: This code is where all the fcns are put together to run a game of memory. This runs a 2 player game where each player must
match cards with the same value to get points. The player with the most won cards at the end wins!
*/

#include <stdio.h>
#include <stdlib.h> //for the use of system and srand and rand
#include "gameObjects.h"
#include "gameFunctions.h"

#define MAX_CHAR_NUMBER 16 //each input should have at most 15 characters

//a helper function that clears the screen, works for both unix and Windows,
//though behaviour might be different.
//reference: https://stackoverflow.com/questions/2347770/
//            how-do-you-clear-the-console-screen-in-c
void clear() {
  #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("printf '\33[H\33[2J'");
  #endif

  #if defined(_WIN32) || defined(_WIN64)
    system("cls");
  #endif
}

int main() {
  	//set the random seed to 0, it'll generate the same sequence
 	 //normally it is srand(time(NULL)) so the seed is different in every run
  	//using 0 makes it deterministic so it is easier to mark
 	 //do not change it
  	srand(0);

  	int whereInDeck1 = 0, whereInDeck2 = 0; //handy for indexing which card based on user input
  	char row1, col1, row2, col2;				//variables to store user input
  	char* suit[4] = {"\u2660","\u2661","\u2663","\u2662"};  //suit symbols represented by Suit enum index

  	//set up the players
  	Player player1, player2;
  	initializePlayer(&player1, "Player 1");
  	initializePlayer(&player2, "Player 2");
  	Player* currentPlayer = &player1; //this pointer remembers who's turn it is

  	//set up the deck: initalize & shuffle
  	Deck myDeck;
  	initializeDeck(&myDeck, "Bicycle");
  	shuffleDeck(&myDeck);

  	printDeck(&myDeck, true); //print the shuffled deck, face up
  	printf("\n");
  	clear(); //clear the screen


    //Step 2: print who's turn it is by showing the player's name
    currentPlayer = &player1;

    while(checkForWinner(&myDeck) == false)		// game start
    {
    	printDeck(&myDeck, false); 	// print deck face down
    	printf("\n");

    	//Step 3.1 get first input from player,
    	// keep asking until the input is valid (hint: use a do-while loop)
    	// you can assume that the format is correct (a digit<space>a letter)
    	printf("%s's turn:\n", currentPlayer->name);      // P1
    	printf("Pick the first card you want to turn (e.g., 0 a) then press enter: ");
    	scanf(" %c %c", &row1, &col1);
 		while(checkPlayerInput(&myDeck, currentPlayer, row1, col1) == false)
 		{
    		printf("Pick the first card you want to turn (e.g., 0 a) then press enter: ");
    		scanf("\n%c %c", &row1, &col1);
 		}

    	//Step 3.2: get second input from player,
    	// keep asking until the input is valid (hint: use a do-while loop)
    	// you can assume that the format is correct (a digit<space>a letter)
    	printf("Pick the second card you want to turn (e.g., 1 b) then press enter: ");
    	scanf("\n%c %c", &row2, &col2);
    	while(checkPlayerInput(&myDeck, currentPlayer, row2, col2) == false)
 		{
    		printf("Pick the second card you want to turn (e.g., 0 a) then press enter: ");
    		scanf("\n%c %c", &row2, &col2);
 		}

    	//Step 4: print the 2 cards the player picks //
    	whereInDeck1 = (row1-48)*13 + (col1-97);
    	whereInDeck2 = (row2-48)*13 + (col2-97);
    	printf("\n");
    	printf("First card picked: %c%s\n", myDeck.cards[whereInDeck1].value, suit[myDeck.cards[whereInDeck1].suit]);
    	printf("Second card picked: %c%s\n", myDeck.cards[whereInDeck2].value, suit[myDeck.cards[whereInDeck2].suit]);
    	printf("\n");

    	//Step 5: call the checkForMatch function to see if the player has picked
    	// a matching pair. If so, print the corresponding message and add the cards
    	// to the player's winning pile (Player.winPile).
    	// Keep the current player as a match leads to an extra round.
    	// Otherwise, print the corresponding message and switch player.
    	if(checkForMatch(&myDeck, currentPlayer, row1, col1, row2, col2) == true)
    	{
      		printf("%s has found a match! Earns extra turn\n", currentPlayer->name);
      		// add card to current play, do not change currentPlayer
      		addCardToPlayer(currentPlayer, &myDeck.cards[whereInDeck1]);
    		addCardToPlayer(currentPlayer, &myDeck.cards[whereInDeck2]);
    	}
    	else
    	{
      		printf("%s has not found a match\n", currentPlayer->name);
      		// do not add card to current player, change currentPlayer
      		if(currentPlayer == &player1)
      		{
      			currentPlayer = &player2;
      		}
      		else
      		{
      			currentPlayer = &player1;
      		}
    	}

    	printf("\n");
	}

	printf("Game Over!\n\n");

	//Step 6: find out who won the game and announce the winner
	printf("%s has won %d cards\n", player1.name, player1.cardsWon);
	printf("%s has won %d cards\n", player2.name, player2.cardsWon);
	printf("\n");
	
	if(player1.cardsWon == player2.cardsWon)	// tie
	{
		printf("Tie Game!\n");
	}
	else if(player1.cardsWon > player2.cardsWon)	//P1 win
	{
		printf("%s Wins!\n", player1.name);
	}
	else											// P2 win
	{
		printf("%s Wins!\n", player2.name);
	}

  	//Step 7: clean up player's winning piles*/
  	clearPlayer(&player1);
  	clearPlayer(&player2);

  return 0;
}
 