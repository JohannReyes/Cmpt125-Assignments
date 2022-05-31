#include <stdio.h>
#include <stdlib.h>
#include "question4.h"

//a helper function to print the content in the array
//assumes stringArray is not NULL
void printStringArray(char* stringArray[], unsigned int size) {
  for (int i=0; i<size; i++) {
    printf("%s\n", stringArray[i]);
  }
}

int main() {
  unsigned int size;
  printf("How many words are you going to input?\n");
  scanf("%d", &size);

  char** stringArray = malloc(size * sizeof(char*));

  for(int i=0; i<size; i++)
  {
    stringArray[i] = malloc(64 * sizeof(char));
    printf("Input word #%d: ", i+1);
    scanf("%s", stringArray[i]);
  }

  if(size>0)
  {
    printf("The median string is %s\n", getMedian(stringArray, size));
  }
  else
  {
    printf("No median can be found.\n");
  }
  return 0;
}
