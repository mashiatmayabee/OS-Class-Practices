#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	
	printf("pid in ex1= %d\n", getpid());
	
	if(!vfork()){
    // child
		printf("argv =%s\n", argv[1]);
		char *args[] = {"hey", "mehedi", "bee", NULL};
		execv("./ex2", args);
		printf("!vfork");
	}
// parent continues after child is gone
	
	else{
		printf("back to ex 1");
	}
	return 0;

}
