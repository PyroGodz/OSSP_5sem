#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void cycle(int k, char* s)
{
	for(int i=0; i < k; i++)
	{
		sleep(1);
		printf("%s: %d\n", s, i);
	}
};

int main()
{
	pid_t pid;
	switch(pid = fork())
	{
		case -1: perror("fork error"); 		exit(-1);
		case 0: execl("os03_05_01","",NULL);		exit(0);
		default: cycle(100,"main");			wait(NULL);
	}
	exit(0);
}
