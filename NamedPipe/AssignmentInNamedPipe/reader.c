
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
//#include<stdlib.h>


int main(){
	char *pipepath,buffer[200];
	
	int fd;
	pipepath= "/home/mayabee/OS-Class-Practices/NamedPipe/AssignmentInNamedPipe/1stpipe";
	while(1){
		
		fd = open(pipepath, O_RDONLY);
		read(fd, buffer, sizeof(buffer));
		
		close(fd);
		if(!strcmp(buffer, "-999") )
		{
			break;
		}

		write(STDOUT_FILENO, buffer, strlen(buffer)+1);
		write(STDOUT_FILENO, "\n", 1);
		
	}
	return 0;
	
	
}
