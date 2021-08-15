#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

	printf("in ex2.c\n");
	printf("pid in ex2= %d\n", getpid());
	printf("argv =%s\n", argv[0]);
	return 0;

}
