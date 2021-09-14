#include<stdio.h>
#include<pthread.h>
int sum(){
	int i;
	for(i=0;i<50;i++){
		printf("sum function\n");
	}
	
}

int main(){
	int i;
	pthread_t threadID;
	pthread_create(&threadID,NULL, (void*)sum,NULL );
	sum();
	for(i=0;i<50;i++){
		printf("Main function\n");
	}
	return 0;
}
