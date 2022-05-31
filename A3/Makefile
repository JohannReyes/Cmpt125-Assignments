all: test1 test2 test3

test1: test1.c question1.c
	gcc -Wall -std=c99 -o test1 test1.c question1.c

test2: test2.c question2.c
	gcc -Wall -std=c99 -o test2 test2.c question2.c

test3: test3.c question3.c
	gcc -Wall -std=c99 -o test3 test3.c question3.c

clean:
	rm -f test1 test2 test3
