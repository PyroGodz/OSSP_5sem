
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <pthread.h>

void* os04_07_T1(void* arg)
{
pid_t pid=getpid();
for(int i=0;i<75;i++)
{
sleep(1);
printf("child %d \n",pid);
if(i==50)
{
    printf("-------------------------child is sleep-----------------\n");
    sleep(10);
}
} 
pthread_exit("Child thread");
}

int main()
{
pthread_t a_thread;
void* thread_result;
pid_t pid=getpid();
int res=pthread_create(&a_thread,NULL,os04_07_T1,NULL);

for(int i=0;i<100;i++)
{
sleep(1);
printf("%d \n",pid);
if(i==30)
{
printf("-------------------------main is sleep-------------------\n");
sleep(15);
}
}
int status=pthread_join(a_thread,(void**)&thread_result);
exit(0);
}

