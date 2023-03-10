#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void * thr_fn1(void *arg){
    printf("thread 1 returning\n");
    return ((void *)1);
}
void * thr_fn2(void *arg){
    printf("thread 2 returning\n");
    return ((void *)2);
}

int main(void){
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0) 
        err_exit(err, "can not create thread 1");
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err !=0)
        err_exit(err, "can not create thread 2");
    err = pthread_join(tid2, &tret);
    if (err!=0)
        err_exit(err, "Cant join Thread1 and Thread2");
    printf("Thread 2 exit code %ld\n",(long)tret);
    exit(0);
}

//Does not work yet