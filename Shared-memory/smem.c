#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main(){
	key_t key;
	int shmID
//3. atach user space with memory segment
// voi *shmat(int shmID, const void *shmaddr)
char *str = (char *)shmat(shmID, NULL, 0);
printf("%s", str);

return 0;
}
