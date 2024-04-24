#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
void main(int argc, char *argv[])
{
  printf("Name of the program= %s\n",argv[0]);
  if(argc==1)
   printf("No name entered.\n");
  for(int i=1;i<argc;i++)
   printf("%s\n",argv[i]);
}