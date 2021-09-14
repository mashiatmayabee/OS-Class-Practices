#include<pthread.h>
#include<unistd.h>
#include<syscall.h>
void thread1(){
	pid_t pid, tid;
	pid = getpid();
	tid = syscall(SYS_gettid);
}
int main(){
	pid_t pid, tid1, tid2;
	pthread_create(%tid1, NULL, (void*) thread1, NULL);
	pthread_join();
	return 0;

}
