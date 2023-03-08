#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h> 

typedef struct _myarg_t{
    int a;
    int b;
} myarg_t;

typedef struct _myret_t{
    int x;
    int y;
} myret_t;


void *mythread(void *arg){
    myarg_t *m = (myarg_t *) arg;
    printf("%d %d\n", m->a, m->b);

    myret_t *r= malloc( sizeof(myret_t));
    r->x=1;
    r->y=2;

    return (void *)r;
}
int main( int argc, char* argv[]){
    pthread_t p;
    myret_t *m;

    myarg_t args = {10,20};
    pthread_create(&p, NULL, mythread, &args);
    pthread_join(p, (void **)&m);
    printf("returned %d %d\n", m->x, m->y);
    free(m);
    return 0;
}