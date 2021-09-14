#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>



int main(int argn,char *argv[]){
    // for(int i=0;i<argn;i++){
    //     printf("%s\n",argv[i]);
    // }
    int fd0 = atoi(argv[0]);
    int fd1 = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    close(fd0);
    char *mul = itoa(a*b);
    // printf("multiplied: %s\n",mul);
    write(fd1,mul,strlen(mul)+1);
    
    return 0;
}
