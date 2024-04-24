#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[]){
      char str[80];
      FILE *fp;
    if((fp=fopen(argv[1], "w+"))==NULL){
        printf("Cannot open file \n");
      exit(1);
      }
   do{
      printf("Enter a string (CR to quit):\n");
      gets(str);
      strcat(str, "\n");
      fputs(str, fp);
     }while(*str!='\n');
   rewind(fp);
   while(!feof(fp))
   {
     fgets(str,79,fp);
     printf(str);
   }
   fclose(fp);
    return 0;
}