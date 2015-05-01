
#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>

int main(void)
{
    fork();
    main();
    /* int i = 0;

     for(; i < 10; i++)

         fprintf(stderr, "%d\n", i);

     fork();

     for(; i < 50; i++)
     {
         fprintf(stderr, "%d\n", i);
        struct timespec t = {0,1000};
         nanosleep(&t,NULL);
          sched_yield();
     }
    */

    return 0;
}

