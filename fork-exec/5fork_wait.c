#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void fork_wait(){
    int child_status;
    if(fork()==0){
        printf("CHILD\n");
        exit(0);
    }else{
        printf("PARENT\n");
        wait(&child_status);
        printf("Child Terminated with %d\n",child_status); 
    }
    printf("Bye\n");
}
void main(){
    fork_wait();
}