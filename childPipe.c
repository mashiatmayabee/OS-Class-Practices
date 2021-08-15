#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(){
	
	printf("Child Process is writing to the pipe.\n");
	close(pipeFD[0]);
	char st[20];
	gets(st);
	char *msg = "HEY";
	write(pipeFD[1], msg, strlen(msg) + 1);

	return 0;
}
