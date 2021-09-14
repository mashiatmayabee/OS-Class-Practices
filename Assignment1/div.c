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
    if(b==0){
        write(fd1,"!zero given",12);//12 is len of string
    }
    else{
        close(fd0);
        char *div = itoa(a/b);
        // printf("divided: %s\n",div);
        write(fd1,div,strlen(div)+1);
    }
    
    
    return 0;
}
