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
    char *sum = itoa(a+b);
    // printf("added: %s\n",sum);
    write(fd1,sum,strlen(sum)+1);
    
    return 0;
}
