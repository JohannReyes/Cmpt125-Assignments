#include <stdio.h>
#include "question1.h"

int main() {
  printf("%u\n", interlace_ints(1000, 99999));
  printf("%u\n", interlace_ints(2345, 11111));
  printf("%u\n", interlace_ints(2468, 13579));

  return 0;
}
