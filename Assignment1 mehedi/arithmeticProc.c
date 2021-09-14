#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

char *converter(int n){
    char *str;
    str = malloc(20*sizeof(char));
    sprintf(str,"%d",n);
    return (char *)str;
}


int main(){
    pid_t cpid;
    int pipeFD[2];
    int status = pipe(pipeFD);

    char expression[5][50]={"addition","subtraction","multiplication","division"};
    
    if(status == -1){
        printf("Error!!\n");
        exit(-1);
    }
    
    int no1,no2,i;
    printf("Enter two Numbers: ");
    scanf("%d %d",&no1,&no2);
   

    for(i=0;i<4;i++){
        
        cpid = fork();
        
        if(cpid<0){ //for unsucessful fork
            printf("Error in %d'th fork\n",i+1);
            exit(-1);
        }
        
        else if(cpid == 0) { //for child process

            char path[]="./";
            strcat(path,expression[i]);

            char *pipe1 = converter(pipeFD[0]);
            char *pipe2 = converter(pipeFD[1]);
            char *num1 = converter(no1);
            char *num2 = converter(no2);
            
            execlp(path,pipe1,pipe2,num1,num2,NULL);
        }

        else if(cpid>0){ //for parent process
            
            wait(NULL);

            char buffer[50];
            read(pipeFD[0],buffer,sizeof(buffer));
            
            printf("Parent ID: %u Child ID : %u\n",getpid(),cpid);
            printf("Result of %s: %s\n",expression[i],buffer);
            
        }
    }

    return 0;
}