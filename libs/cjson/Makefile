all: libcjson

libcjson: cJSON.c cJSON.h
	gcc -c cJSON.c -o cJSON.o
	ar rcs  libcjson.a cJSON.o

.PHONY: all clean


clean:
	rm -rf cJSON.o libcjson.a
