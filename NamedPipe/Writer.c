/*

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
//#include<stdlib.h>


int main(){
	char *pipepath,*msg;
	
	int fd;
	pipepath= "/home/mayabee/OS-Class-Practices/NamedPipe/2ndpipe";
	msg = "hey there\n";
	fd = open(pipepath, O_WRONLY);
	write(fd , msg, strlen(msg)+1);
	close(fd);
	
	return 0;
	
	
}*/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fd;
	char *pipePath;
	char *msg;

	pipePath = "/home/mayabee/OS-Class-Practices/NamedPipe/2ndpipe";
	msg = "Hello\n";
	fd = open(pipePath, O_WRONLY);	
	write(fd, msg, strlen(msg) + 1);
	close(fd);

	return 0;
}
