#include<stdio.h>
#include<pthread.h>
#include<sched.h>
#include<semaphore.h>
int x=10;
sem_t key;
void sum_thread(){
    sem_wait(&key);

    printf("x = %d in sum thread before operation\n",x);
    x=x+1;
   printf("x = %d in sum thread before operation\n",x);
    sem_post(&key);

}
void sub_thread(){
        sem_wait(&key);

       printf("x = %d in sub thread before operation\n",x);
    x=x-1;
   printf("x = %d in sub thread before operation\n",x);
    sem_post(&key);



}
int main(){

    pthread_t TID1, TID2;

    pthread_create( &TID1, NULL, (void*) sum_thread,NULL);
    pthread_create( &TID2, NULL, (void*) sub_thread,NULL);
      sem_wait(&key);

  //pthread_mutex_lock(&key);
    printf("x = %d in main thread[CPU : %d] After operation\n",x, sched_getcpu() );
      sem_post(&key);

  //  pthread_mutex_unlock(&key);
    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);


}