#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h> 

typedef struct books{
    char name[50];
    char author[20];
    int id;
} book1;

typedef struct bookissue{
    char name[50];
    char author[20];
    int id;
    char issueto[20];
} bookissue1;

void *issuingbookfunction(void *bookissued){
    book1 *b = (book1 *) bookissued;
    printf("Current status:\n");
    printf("Name: %s :\n", b->name);
    // printf("Author: %s :\n", b->author);
    // printf("id: %s :\n", b->id);


    // char temp[20];
    bookissue1 *i = malloc( sizeof(bookissue1));
    // printf("Issued to? :\n");
    // fgets(temp, 20, stdin);
    strcpy(i->name,"Goblet of fire\0" );
    // strcpy(i->author,"JK Rowling" );
    // strcpy(i->issueto,"Emma watson" );
    // strcpy(i->issueto, temp);
    // i->id=101;

    return (void *)i;
}

int main(int argc , char* argv){

    printf("Issuing to: ");
    pthread_t th;
    bookissue1 * issue;

    book1 *issuingbook;
    strcpy(issuingbook->name,"Game of thrones\0" );
    // strcpy(issuingbook->author,"George R R Martin" );
    // issuingbook->id=102;

    pthread_create(&th, NULL, issuingbookfunction, &issuingbook);
    pthread_join(th,(void **) &issue);
    printf("Return values\n");
    printf("Name: %s\n",issue->name);
    // printf("Author: %s\n",issue->author);
    // printf("ID: %d\n",issue->id);
    // printf("Issue to: %s\n",issue->issueto);

    return 0;
}