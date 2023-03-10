#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr= (int*) malloc(100);
    free(ptr);
    printf("%d",ptr[1]);
    return 0;
}

/*Create a program that allocates an array of integers (as above), frees
them, and then tries to print the value of one of the elements of
the array. Does the program run? What happens when you use
valgrind on it?*/