#include<stdio.h>
#include<unistd.h>

void main(){
    int x=0;
    pid_t pid=fork();
    if (pid==0){
        printf("child has x %d\n",--x);
    }else{
        printf("Parent has x %d\n",++x);
    }
    printf("Bye from %d with x %d\n",pid,x);
    
}