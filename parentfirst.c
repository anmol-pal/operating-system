#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


static int c=0;
int main(){
    int child=fork();
    if(child<0){
        sleep(1);
        fprintf(stderr," Fork failed\n");
        exit(-1);
    }else if(child==0){
        wait(NULL);
        printf("child %d\n",c+3);
    }else {
        printf("Parent %d\n",c+5);
    }
    return 0;
}