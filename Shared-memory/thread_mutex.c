#include<stdio.h>
#include<pthread.h>
#include<sched.h>
#include<semaphore.h>
int x=10;
key_t key;
void sum_thread(){
    printf("x = %d in sum thread before operation\n",x);
    x=x+1;
   printf("x = %d in sum thread before operation\n",x);


}
void sub_thread(){
       printf("x = %d in sub thread before operation\n",x);
    x=x-1;
   printf("x = %d in sub thread before operation\n",x);



}
int main(){

    pthread_t TID1, TID2;
    pthread_create( &TID1, NULL, (void*) sum_thread,NULL);
    pthread_create( &TID2, NULL, (void*) sub_thread,NULL);
        // pthread_mutex_lock(&key);

        printf("x = %d in main thread[CPU : ] After operation\n",x );
            // pthread_mutex_unlock(&key);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);


}