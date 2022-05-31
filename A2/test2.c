#include <stdio.h>
#include <limits.h>
#include "question2.h"

int main() {
  printf("%lu\n", foo_recursive(0));
  printf("%lu\n", foo_recursive(10));
  printf("%lu\n", foo_recursive(30));

  printf("\n");
  printf("%lu\n", foo_fast(0));
  printf("%lu\n", foo_fast(10));
  printf("%lu\n", foo_fast(30));

  printf("The maximum value of UNSIGNED LONG = %lu\n", ULONG_MAX);

  return 0;
}
