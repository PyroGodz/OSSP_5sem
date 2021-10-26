
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>

int main()
{
pid_t pid=getpid();
for(int i=0;i<50;i++)
{
sleep(1);
printf("%d-%d \n",pid,i);
}
exit(0);
}