#include <stdio.h>
#include <pthread.h>

//this is a demo to show the threads in c


void *computation(void *add);

int main()
{
    pthread_t  thread1;
    pthread_t  thread2;

    long value1 =1;
    long value2 = 2;

    //pthread_create(the address of thread, attributs of the thread, address of the function, parameters of functions)
    pthread_create(&thread1,NULL,computation,(void *)&value1);

     pthread_join(thread1,NULL);
    pthread_create(&thread2,NULL,computation,(void *)&value2);

    //pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}

void *computation(void *add)
{
    long *add_num = (long *)(add);

    long sum = 0;
    for(long i = 0;i < 1000000000;i ++)
        sum += *add_num;
    printf("The reuslt of addition is : %ld\n",sum);
    return NULL;
}