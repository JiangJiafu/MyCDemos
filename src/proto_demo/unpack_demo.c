#include <stdio.h>
#include <stdlib.h>
#include "addressbook.pb-c.h"
#define MAX_MSG_SIZE 1024

static size_t
read_buffer (unsigned max_length, uint8_t *out)
{
    size_t cur_len = 0;
    size_t nread;
    while ((nread=fread(out + cur_len, 1, max_length - cur_len, stdin)) != 0)
    {
        cur_len += nread;
        if (cur_len == max_length)
        {
            fprintf(stderr, "max message length exceeded\n");
            exit(1);
        }
    }
    return cur_len;
}

int main (int argc, const char * argv[]) 
{
    int i = 0;
    Tutorial__AddressBook *address_book = NULL;   
    // Read packed message from standard-input.
    uint8_t buf[MAX_MSG_SIZE];
    size_t msg_len = read_buffer (MAX_MSG_SIZE, buf);
    
    // Unpack the message using protobuf-c.
    address_book = tutorial__address_book__unpack(NULL, msg_len, buf);
    if (address_book == NULL)
    {
        fprintf(stderr, "error unpacking incoming message\n");
        exit(1);
    }
    // display the message's fields.
    printf("Received: person number=%d\n", address_book->n_person);  // required field
    for (i = 0; i < address_book->n_person; ++i)
    {
        printf("Person name: %s\n", address_book->person[i]->name);
        printf("Person id: %d\n", address_book->person[i]->id);
    }
    // Free the unpacked message
    tutorial__address_book__free_unpacked(address_book, NULL);
    return 0;
}
