#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>
//#include <common.h>
int main(int argc, char*argv[]){
    if(argc!=2){
        fprintf(stderr,"usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while(1){
//        Spin(1);
        sleep(1);
        printf("%s\n",str);
    }
    return 0;
}

// Exmaple demonstrates virtualizing CPU 
// Upon executing multiple instances of this program until interupted by a kill signal
// >  ./a.out A & ; ./a.out B &
// >[1] 11097
//  [2] 11098
// B
// B
// A
// B
// A
// B
// A

//Operating System turns single CPU to an inifinite number of CPUs allowing multiple programs to run at once