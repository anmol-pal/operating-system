#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("Hello World top level (pid:%d)\n", (int)getpid());
    int rc= fork();
    if(rc<0){
        fprintf(stderr,"Fork Failed\n");
        exit(1);
    } else if(rc ==0 ) {
        printf("Hello I am child (pid:%d)\n",(int)getpid());
        sleep(1);
    } else{
        int rc_wait = wait(NULL);
        printf("Hello , from Parent %d (pid:%d)\n",rc,(int)getpid());
    }
    return 0;
}


// gcc -o fork fork-test.c -> Illsustrates wait()
// wait() syscall will wait untill any child process terminates 