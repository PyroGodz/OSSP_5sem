#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>

void main(int argc, char *argv[])
{  
  FILE *fp = fopen("./os09_05.txt","r");
  int ch=0;
  int lines=0;

  if (fp == NULL) 
    return 0;

  while(!feof(fp))
    {
  ch = fgetc(fp);
  if(ch == '\n')
    {
      lines++;
    }
  }
  fclose(fp);
  printf("Count of lines: %d\n",lines);      
}
