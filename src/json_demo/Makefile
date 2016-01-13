INC_DIR = ../../libs/cjson
CFLAGS = -I$(INC_DIR)
LDFLAGS = -L../../libs/cjson
all: test_json

test_json: test.c
	gcc $(CFLAGS) test.c -o test -lm $(LDFLAGS) -lcjson

.PHONY: all clean


clean:
	rm -rf test
