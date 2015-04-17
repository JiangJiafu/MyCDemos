testWriter: testWriter.c
	gcc -I /usr/include/libxml2/ -L /usr/lib64/ -lxml2 -o testWriter testWriter.c
tree1: tree1.c
	gcc -I /usr/include/libxml2/ -L /usr/lib64/ -lxml2 -o tree1 tree1.c

tree2: tree2.c
	gcc -I /usr/include/libxml2/ -L /usr/lib64/ -lxml2 -o tree2 tree2.c

.PHONY: all

all: testWriter tree1 tree2
