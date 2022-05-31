#include <stdio.h>
#include <stdlib.h> //for the use of srand and rand
#include "question2.h"

int main()
{
    //set the random seed to 0, it'll generate the same sequence
    //normally it is srand(time(NULL)) so the seed is different in every run
    //using 0 makes it deterministic so it is easier to mark
    //do not change it
    srand(0);

    Deck myDeck;
    initializeDeck(&myDeck, "Bicycle");
    printDeck(&myDeck);
    shuffleDeck(&myDeck);
    printf("\n");
    printDeck(&myDeck);

    return 0;
}
