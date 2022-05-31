#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "question1.h"

//a helper function to print the content in the array
//assumes stringArray is not NULL
void printStringArray(char* stringArray[], unsigned int size) {
  for (int i=0; i<size; i++) {
    printf("%s\n", stringArray[i]);
  }
}

int main() {
  int numInput = 0;
  printf("%s\n", "How many words are you going to input?");
  scanf("%d", &numInput);

  if (numInput == 0) {
    printf("No words to be sorted.\n");
  } else {
    char** userWords = malloc(sizeof(char*) * numInput);
    if (userWords == NULL) {//if memory is not available terminate the program
      exit(0);
    }
    for (int i=0; i<numInput; i++) {
      printf("Input word #%d: ", i+1);
      //assume each word has no more than 63 characters
      userWords[i] = malloc(sizeof(char) * 64);
      scanf("%s", userWords[i]);
    }

    quicksort_cstrings(userWords, numInput, true);
    puts("User words printed by length:");
    printStringArray(userWords, numInput);
    quicksort_cstrings(userWords, numInput, false);
    puts("User words printed by alphabetical order:");
    printStringArray(userWords, numInput);

    for (int i=0; i<numInput; i++) {
      free(userWords[i]);
    }
    free(userWords);

  }

  return 0;
}
