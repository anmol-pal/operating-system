#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    int *p = malloc (sizeof (int));
    assert(p!= NULL);
    printf("(%d) address pointed to by p %p\n", getpid(), p);
    *p=0;
    while(1){
        sleep(1);
        *p=*p+1;
        printf("%d p: %d\n",getpid(), *p);
    }
    return 0;
}

//gcc -o mem virtualization_mem.c 
// ./mem &; ./mem&
// Upon starting multiple processes we still get same address printed 
// (13967) address pointed to by p 0x7faf73705be0
// (13966) address pointed to by p 0x7fc28b705be0
// 13967 p: 1
// 13966 p: 1
// 13967 p: 2
// 13966 p: 2
// 13967 p: 3
// 13966 p: 3
// 13967 p: 4
// 13966 p: 4
// 13967 p: 5
// 13966 p: 5
// 13967 p: 6