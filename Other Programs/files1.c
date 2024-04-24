#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
FILE *fp;
char ch;
if(argc!=2){
printf("You forgot to enter the filename\n");
exit(0);
}
if((fp=fopen(argv[1], "w"))==NULL){
printf("Cannot open file \n");
exit(0);
}
ch=getchar();
while(ch!='$'){
fputc(ch, fp);
ch=getchar();
}
fclose(fp);
return(0);
}