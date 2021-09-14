#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main(){
	key_t key;
//1. generate a key
//key_t ftok(sonst char *pathname, int proj_id);

	key = ftok("MainArguments", 'o');
printf("key : %d", key);
//2 .allocate/ create shared sagment
int shmID = shmget(key, 100, IPC_CREAT | 0666);
//3. atach user space with memory segment
// voi *shmat(int shmID, const void *shmaddr)
char *str = (char *)shmat(shmID, NULL, 0);
strcpy( str, "hey\n");

return 0;
}
