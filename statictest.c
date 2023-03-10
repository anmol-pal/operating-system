#include <stdio.h>
#include <stdlib.h>
    int c=0;

int fun(){
    c++;
    printf("%d",c);
}
int main(){
    printf("%d ", c++);
    printf("%d ", c);
    fun();
        return 0;
}