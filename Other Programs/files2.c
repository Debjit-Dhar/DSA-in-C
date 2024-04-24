#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
FILE *fp;
char ch;
if(argc!=2){
printf("You forgot to enter the filename\n");
exit(0);
}
if((fp=fopen(argv[1], "r"))==NULL){
printf("Cannot open file \n");
exit(0);
}
ch=fgetc(fp);
while(ch!=EOF){
printf("%c",ch);
ch=fgetc(fp);
}
fclose(fp);
return(0);
}