#include <stdio.h>
#include "question1.h"

unsigned int interlace_ints(unsigned int firstNum, unsigned int secondNum) {
	return expand_int(firstNum)*10 + expand_int(secondNum);
}

int main() {
  printf("%u\n", expand_int(1));
  printf("%u\n", expand_int(24));
  printf("%u\n", expand_int(876));

  //test usage of expand_int
  printf("\n");
  printf("%u\n", interlace_ints(1000, 99999));
  printf("%u\n", interlace_ints(2345, 11111));
  printf("%u\n", interlace_ints(2468, 13579));

  return 0;
}
