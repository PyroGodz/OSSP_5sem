#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    for (int i = 0; i < 10000000; i++)
    {
    	sleep(1);
        printf("%p\n", i);
    }
    sleep(1000);
}
