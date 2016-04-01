INC_DIR = -I/usr/local/include
CFLAGS = -I.
LDFLAGS = -L/usr/local/lib -lprotobuf-c
all: pack_demo unpack_demo

pack_demo: pack_demo.c addressbook.pb-c.c
	gcc $(INC_DIR) $(CFLAGS) pack_demo.c addressbook.pb-c.c -o pack_demo -lm $(LDFLAGS) 

unpack_demo: unpack_demo.c addressbook.pb-c.c
	gcc $(INC_DIR) $(CFLAGS) unpack_demo.c addressbook.pb-c.c -o unpack_demo -lm $(LDFLAGS) 
.PHONY: all clean


clean:
	rm -rf pack_demo unpack_demo
