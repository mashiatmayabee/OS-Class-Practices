
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
//#include<stdlib.h>


int main(){
	char *pipepath,buffer[200];
	
	int fd;
	pipepath= "/home/mayabee/OS-Class-Practices/NamedPipe/2ndpipe";
	fd = open(pipepath, O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	close(fd);
	write(STDOUT_FILENO, buffer, strlen(buffer)+1);
	return 0;
	
	
}
