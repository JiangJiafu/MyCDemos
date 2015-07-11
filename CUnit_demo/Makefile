all: main

.PHONY: all clean

main: simple_test.c
	gcc -lcunit -I Headers -o simple_test simple_test.c

clean:
	rm -rf simple_test
