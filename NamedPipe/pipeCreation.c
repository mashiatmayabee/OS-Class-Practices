//			user grp others
//r:100		4	 4	 4
//w:010		2	 0	 2
//x:001		1	 0	 0
//-----------------------------
//		0	7	 4	 6


#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
//#include<stdlib.h>


int main(){
	char *pipepath;

	pipepath=  "/home/mayabee/OS-Class-Practices/NamedPipe/2ndpipe";
	mkfifo(pipepath, 0666);
	return 0;
}
