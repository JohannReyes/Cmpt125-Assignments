#ifndef A2_Q2_H
#define A2_Q2_H

//a recursive function that takes in one unsigned int as its input and returns
// the value indicated by this forumla:
// foo(0) = 1
// foo(1) = 2
// foo(n) = 2*foo(n-2) + foo(n-1) + n + 2, for n >= 2
unsigned long foo_recursive(unsigned long n);

//a non-recursive function that takes in one unsigned int as its input and
// returns the value indicated by this forumla:
// foo(0) = 1
// foo(1) = 2
// foo(n) = 2*foo(n-2) + foo(n-1) + n + 2, for n >= 2
unsigned long foo_fast(unsigned long n);

#endif
