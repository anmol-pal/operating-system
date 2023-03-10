#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h> 

typedef struct books{
    char name[100];
} book1;

typedef struct bookissue{
    char name[100];
} bookissue1;

void *issuingbookfunction(void *bookissued){
    book1 *b = (book1 *) bookissued;
    printf("Current status:\n");
    printf("Name: %s :\n", b->name);

    bookissue1 *i = malloc( sizeof(bookissue1));

    strcpy(i->name,"Goblet of fire\0" );

    return (void *)i;
}

int main(int argc , char* argv){

    printf("Issuing to: ");
    pthread_t th;
    bookissue1 *issue;
    book1 issuingbook={"Game of thrones\0"};

    pthread_create(&th, NULL, issuingbookfunction, &issuingbook);
    pthread_join(th,(void **) &issue);
    printf("Return values\n");
    printf("Name: %s\n",issue->name);
    free(issue);
    return 0;
}