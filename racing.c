#include <stdio.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t lock;

void *computation()
{
    // use a critical section to protect the access to the shared variable sum
    for(long i = 0;i < 100000;i ++)
    {
        pthread_mutex_lock(&lock); 
        sum ++;
        pthread_mutex_unlock(&lock); 
    }
    return NULL;
}

int main()
{
    pthread_t  thread1;
    pthread_t  thread2;

    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread1,NULL,computation,NULL);
    pthread_create(&thread2,NULL,computation,NULL);

    //since the access of the memory is not synchronized, the final result is not correct
    // this is called a racing condition
    // to sovle this issue, we need to use mutex to lock the memory access
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_mutex_destroy(&lock);
    printf("The final sum is : %d\n",sum);
    return 0;
}