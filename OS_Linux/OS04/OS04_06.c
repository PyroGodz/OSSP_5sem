#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
pid_t pid=getpid();


for(int i=0;i<1000;i++)
{
sleep(2);
printf("%d \n",pid);
}
exit(0);
}
