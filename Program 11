#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *thread_function(void *arg)
{
    int *value = (int *)arg;  
    printf("Hello SSE from thread %d\n", *value);  

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2; 
    int value1 = 1, value2 = 2; 
    pthread_create(&thread1, NULL, thread_function, &value1);
    pthread_create(&thread2, NULL, thread_function, &value2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
