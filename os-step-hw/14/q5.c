#include <stdio.h>
#include <stdlib.h>

int main(){
    int *data= (int*)malloc(100);
    data[100]=0;
    free(data);
    return 0;
}

/*
Write a program that creates an array of integers called data of size
100 using malloc; then, set data[100] to zero. What happens
when you run this program? What happens when you run this
program using valgrind? Is the program correct?
*/

/*Nothing happens*/