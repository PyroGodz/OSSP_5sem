#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
if(execl("os03_05_01","",(char*)NULL)==-1)
    {
        printf("Error!\n");
    }
else
    {
        printf("Program is run!\n");
    }
pid_t pid=getpid();
for(int i=0;i<100;i++)
{
	sleep(1);
	printf("%d-%d \n",pid, i);
	}


exit(0);
}