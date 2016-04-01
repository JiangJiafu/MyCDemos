#include <stdio.h>
#include <stdlib.h>
#include "addressbook.pb-c.h"

int main (int argc, const char * argv[]) 
{
    int person_number = 1;
    int phone_number_size = 1;
    int len = 0;
    void *buf = NULL;
    Tutorial__Person__PhoneNumber **phone_number_array = NULL;
    Tutorial__Person **person_array = NULL;
    Tutorial__AddressBook address_book = TUTORIAL__ADDRESS_BOOK__INIT; // AMessage
    Tutorial__Person person = TUTORIAL__PERSON__INIT;
    Tutorial__Person__PhoneType phone_type = TUTORIAL__PERSON__PHONE_TYPE__HOME;
    Tutorial__Person__PhoneNumber phone_number = TUTORIAL__PERSON__PHONE_NUMBER__INIT;
    
    phone_number.number = "13401167356";
    phone_number.type= TUTORIAL__PERSON__PHONE_TYPE__MOBILE;
    person.name = "JiangJiafu";
    person.id = 1;
    person.email = "jiangjf@sugon.com";
    phone_number_array = malloc(sizeof(Tutorial__Person__PhoneNumber *) * phone_number_size);
    person.n_phone = phone_number_size;
    person.phone = phone_number_array;
    person.phone[0] = &phone_number;
    person_array = malloc(sizeof(Tutorial__Person *) * person_number);
    if (!person_array)
    {
        exit(-1);
    }
    address_book.n_person = phone_number_size;
    address_book.person = person_array;
    address_book.person[0] = &person;
    
    len = tutorial__address_book__get_packed_size(&address_book);
    buf = malloc(len);
    tutorial__address_book__pack(&address_book, buf);

    fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
    fwrite(buf,len,1,stdout); // Write to stdout to allow direct command line piping
    free(person_array);
    free(phone_number_array);
    free(buf); // Free the allocated serialized buffer
    return 0;
}
