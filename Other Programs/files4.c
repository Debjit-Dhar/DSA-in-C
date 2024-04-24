#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[])
{
      FILE *fp;
      if((fp=fopen(argv[1], "wb+"))==NULL){
        printf("Cannot open file \n");
      exit(1);
      }
      int a=5,a1;double b=2.3,b1;float c=1.4f,c1;long int d=1002,d1;char e[80]="Debjit Dhar",e1[80];
      fwrite(&a,sizeof(int),1,fp);
      fwrite(&b,sizeof(double),1,fp);
      fwrite(&c,sizeof(float),1,fp);
      fwrite(&d,sizeof(long int),1,fp);
      fwrite(e,sizeof(char),strlen(e),fp);
      rewind(fp);
      fread(&a1,sizeof(int),1,fp);
      fread(&b1,sizeof(double),1,fp);
      fread(&c1,sizeof(float),1,fp);
      fread(&d1,sizeof(long int),1,fp);
      fread(e1,sizeof(char),sizeof(e1),fp);
      printf("%d\n%lf\n%f\n%ld\n%s\n",a1,b1,c1,d1,e1);
      fclose(fp);
      return 0;
}
