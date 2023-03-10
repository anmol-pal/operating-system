#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static int data=11;
int main(int argc, char* argv[]){
    int istack=22;
    pid_t pid=fork();
    if (pid==0){
        data*=3;
        istack*=3;
    }
    else{
        sleep(1);
    }
    printf("Process %d data = %d and istack= %d \n",pid,data, istack);
    exit(0);
}