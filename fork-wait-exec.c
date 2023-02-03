#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char*argv[]){
    printf("Hello world (pid:%d)\n",(int) getpid());
    int rc = fork();
    if(rc<0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc==0){
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        //open("./out.txt",O_CREAT | O_WRONLY| O_TRUNC, S_IRWXU);
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("concurrency.c");
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
        printf("this shouldn't print: %d",0);
    }else{
        int rc_wait=wait(NULL);
        printf("this print rc:%d (rc_wait:%d) (pid:%d)\n",rc,rc_wait,(int)getpid());
    }

    return 0;
}