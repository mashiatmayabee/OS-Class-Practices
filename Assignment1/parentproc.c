#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>



int main(){
    pid_t pid,ppid,cpid;
    char processName[5][50]={"add","mul","sub","div"};
    char buffer[50];
    int arr[2];
    int status = pipe(arr);
    
    if(status == -1){
        printf("Error to call pipe()\n");
        exit(-1);
    }
    //scanning two value
    int a,b;
    // scanf("%d %d",&a,&b);
    a = 5;
    b = 9;
    for(int i=0;i<4;i++){
        cpid = fork();
        if(cpid==-1){
            printf("Error to call %d'th fork()\n",i+1);
            exit(-1);
        }

        else if(cpid>0){
            // sleep(5);
            wait(NULL);
            // close(arr[1]);
            read(arr[0],buffer,sizeof(buffer));
            printf("From child ID %u\n",cpid);
            printf("Parent- %s: %s\n",processName[i],buffer);
            // popen(arr[1]);
            // wait(NULL);
            // code here
        }
        else{
            char temp[]="./";
            strcat(temp,processName[i]);
            // printf("%s\n",temp);
            char *fd0 = itoa(arr[0]);
            char *fd1 = itoa(arr[1]);
            char *n1 = itoa(a);
            char *n2 = itoa(b);
            // printf("%s %s %s\n",fd,n1,n2);
            execlp(temp,fd0,fd1,n1,n2,NULL);
        }
    }

    return 0;
}
