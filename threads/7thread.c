#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h> 


void *mythread(void *arg){
    int m= (int) arg;
    printf("%d\n",m);
    return (void *)(arg+1);
}
int main(int argc, char *argv[]){
    pthread_t p;
    int rc, m;
    pthread_create(&p,NULL ,mythread,(void *)100);
    pthread_join(p, (void **)&m);
    printf("return %d\n",(int)m);
    return 0;
}