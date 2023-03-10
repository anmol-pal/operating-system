#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char*argv[]){
    printf("Hello world %d (pid:%d)\n", (int) getpid());
    int rc= fork();

    if(rc<0){
        fprintf(stderr, "fork failed");
        exit(1);
    } else if(rc==0){
        printf("hello, I am child (pid%d)\n",(int)getpid());
        char *myargs[3];
        myargs[0] = strdup("pwd"); //Wordcount
//        myargs[1] = strdup("-ltar"); //argument file to count
        myargs[1] = NULL; //runs word count
        execvp(myargs[0],myargs);
        printf("Will not print");
    }else{
        int rc_wait=wait(NULL);
        printf("Hello, parent here %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
    }

}

// gcc -o exec execfunction.c
// ./exec 