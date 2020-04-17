#include <stdio.h>
#include <pthread.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;

void *songuyento()
{
    int i;
    int j;
    for(i = 2; i <= 1000000; i++)
    {
        for(j = 2; j <= i; j++)
        {
            if(i % j == 0)
            {
                break;
            }
        }
        if(i == j)
        {
            sem_wait(&s);
            printf("Prime number: %d\n",i);
            sem_post(&s);
        }
    }
}
void *fibo()
{
    int a = 0;
    int b = 1;
    int c;
    int i;
    printf("%d ", a);
    printf("%d ", b);
    for (i = 0; i <= 1000000; i++)
    {
        c = a + b;
        a = b;
        b = c;
        sem_wait(&s);
        printf("Fabonaci number: %d\n",c);
        sem_post(&s);
    }
}
int main()
{
    sem_init(&s, 0, 1);
    printf("prim_num\nfibo_num\n");
    int thread1;
    int thread2;
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1,NULL,songuyento,NULL);
    pthread_create(&tid2,NULL,fibo,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    sem_destroy(&s);
    printf("\n");
    return 0;
}

