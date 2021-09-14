#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void signal_handler(int c){
	printf("Im fine\n");

}
int main(ing argc , char **argv){
	int i;
	pid_t pid;
	pid= getpid();
	signal(SIGTERM, signal_handler)
	for (i=0;i<780000;i++){
		printf("%d. PID = %d\n",i,pid );
		sleep(3);
}
}
