#include<stdio.h>
#include<unistd.h>

void main(int argc, char*argv[]){
    pid_t pid=fork();
    
    if (pid!=0){
        printf("Parent\n");
    }
    else{
        printf("Child\n");
        argv[0]=argv[1];
        argv[1]=argv[2];
        argv[2]=NULL;
        execvp(argv[0],argv);
        printf("Child failed exec\n");
    }
    printf("End Printed by parent\n");
}
// gcc -o f ./4fork-exec.c
// f /bin/ls -ltar NULL
