#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MSGSIZE 16

char* msg1 = "Hello world! 1566";
char* msg2 = "Hello world! 1567";
char* msg3 = "Hello world! 1568";


int main(){
    char* inbfr[MSGSIZE];
    int p[2], pid, nbytes;

    if(pipe(p)<0) exit(1);

    if((pid=fork())>0){
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        wait(NULL);
    }else{
        while((nbytes = read(p[0], inbfr, MSGSIZE)) >0)
        printf("%s\n",inbfr);

        if(nbytes!=0) exit(2);
        printf("Finished Reading");
    }

    return 0;
}

// This program hangs after because after finishing read/write parent and child block instead of terminating process.
// Read system call will get as much data it requests or the data pipe has , whichever is less.
// If pipe is empty ,we call read system call and READ on pipe will return EOF, if no process has write end open
// If some other process pipe open for writing , read blocks hoping new data will come through and thus this code hangs
