#include <stdio.h>
void main()
{
    FILE*fp;
    fp=fopen("tchaikovsky-dance-of-the-sugar-plum-fairy.mp3","w+");
    while(!feof(fp))
    {
        fputc('a',fp);
        fputs("Debjit",fp);
       
    }
    fclose(fp);
}