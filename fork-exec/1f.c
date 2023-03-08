#include<stdio.h>
#include<unistd.h>

int main(){
    int x=2;
    pid_t pid = fork();
    if (pid==0) printf("Hello from child %d\n",++x);
    else printf("Hello from Parent%d\n",--x);
    return 0;
}

