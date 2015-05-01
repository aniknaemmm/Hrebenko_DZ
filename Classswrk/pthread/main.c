#define _POSIX_C_SOURCE 200809l
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
typedef struct Arg_
{
    int *a ;
    double b ;
    pthread_mutex_t *mut;
} Arg;
void *run(void *args)
{
    //Arg param = *(Arg *)args;
    Arg *p = (Arg *)args;
    int *a = (*p).a;
    struct timespec t = {0, 10000};
    // nanosleep(&t, NULL);

    //fprintf(stderr, "%d-%.3f\n", param.a, param.b);
    for(int i = 0; i < 50; i++)
    {
        pthread_mutex_lock((*p).mut);
        fprintf(stderr, "%d %d\n", i, *a);
        (*a)++;
  pthread_mutex_unlock((*p).mut);
        nanosleep(&t, NULL);
    }


    return NULL;
}

int main(void)
{
    //int pthread_create(pthread_t *tid,void *attribute,void* (*funk)(void*)
    // 0 good
    pthread_t tid;
    pthread_t mid;
    pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
    int a = 0;
    int b = 0;
    Arg arg = {&a, 4.34, &mut};

    if(pthread_create(&tid , NULL, run, &arg))
    {
        fprintf(stderr, "ERROR\n");
        return 1;
    }

    if(pthread_create(&mid , NULL, run, &arg))
    {
        fprintf(stderr, "ERROR\n");
        return 1;
    }

    /*pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;
      Args  arg={&a,&mut};

    */
    pthread_join(tid, NULL);
    pthread_join(mid, NULL);
    // while(1);

    //  printf("Hello World!\n");
    return 0;
}

