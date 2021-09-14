#include<stdio.h>
#include<unistd.h>
int main(){

	pid_t cpid,pid,cpid1;
	cpid = fork();// negative value /0/child pid
	if(cpid < 0)//failing code
	{
		printf("unsucessfull");
		exit(-1);
	}
	else if(cpid==0)//for child process
	{
		cpid1= getpid();
		printf("child process - %u\n", cpid);
	}
	else if(cpid==0)//for parent process
	{
		pid= getpid();
	
		printf("parent process - %u\n", pid);
	}



	/*int i;
	for(i=0;i<1;i--){
		pid = getpid();
		ppid= getppid();
		printf("my pid= %u\n", pid);
		printf("my parents pid= %u\n", ppid);
	}*/
	
return 0;
}
