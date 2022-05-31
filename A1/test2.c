#include <stdio.h>
#include "question2.h"

int main() {
  int intArr1[] = {-1, 0, 2, 3, 4, 5, 6, 7};
  char pair[32];

  findPair(intArr1, 8, -1, pair);
  printf("%s\n", pair);

  findPair(intArr1, 8, 5, pair);
  printf("%s\n", pair);

  findPair(intArr1, 8, 25, pair);
  printf("%s\n", pair);

  return 0;
}
