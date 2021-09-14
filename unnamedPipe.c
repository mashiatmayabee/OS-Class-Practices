#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>


int main(){
	int pipeFD[2], status;
	pid_t childPID;
	
	// Create a pipe. pipeFD[0]: Read purpose & pipeFD[1]: Write purpose
	status = pipe(pipeFD);
	if (status == -1){// Failure case.
		printf("Error!!!");
		exit(-1);
	}
	printf("Pipe descriptors: %d, %d\n", pipeFD[0], pipeFD[1]);

	// Create a child
	childPID = fork();
	
	if (childPID == -1){ // Failure case.
		printf("Error!!!");
		exit(-1);
	}
	else if (childPID == 0){ // Child will execute this part.
		
	     static char *argv[]={"echo","Foo is my name.",NULL};
        execv("/childPipe",argv);
        exit(-1); 

	
	}
	else if (childPID > 0){// Parent will execute this part.
		

		printf("Parent Process is reading from the pipe.\n");
		printf("kfej");
		close(pipeFD[1]);

		char buffer[200];
		read(pipeFD[0], buffer, sizeof(buffer));
		printf(" buffer %s\n", buffer);
		wait(NULL);		
	}
		
	return 0;

}
