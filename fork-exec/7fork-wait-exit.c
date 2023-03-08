#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char* argv[]){
    pid_t pid=fork();
    if(pid==0) {
        printf("Child %d\n",getpid());
        exit(15);
    }
    else{
        int wc= wait(NULL);
        printf("Parent here , child exited from process %d\n",wc);
    }
}