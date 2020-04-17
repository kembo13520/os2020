#include <stdio.h>
#include <pthread.h>

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
            printf("Prime number: %d\n",i);
        }
    }
}
void *fibo()
{
    int a = 0;
    int b = 1;
    int c;
    int i;
    for (i = 0; i <= 1000000; i++)
    {
        c = a + b;
        a = b;
        b = c;
        printf("Fabonaci number: %d\n",c);
    }
}
int main()
{
    int thread1;
    int thread2;
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1,NULL,songuyento,NULL);
    pthread_create(&tid2,NULL,fibo,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}

