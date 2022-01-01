#include<stdio.h>
#include<pthread.h>
int sum(){
	int i;
		printf("sum function\n");
	
}
int main(){
	int i;
	pthread_t threadID;
	pthread_create(&threadID,NULL, (void*)sum,NULL );
	
		printf("Main function\n");
	
	return 0;
}
