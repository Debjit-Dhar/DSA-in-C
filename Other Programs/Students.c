#include <stdio.h>

struct data
{
    int roll;
    char name[100];
    float score[5];
    int is_deleted;  // Added to mark logical deletion
};

int append_rec(struct data d)
{
    FILE *fp = fopen("StudentRecords.dat", "ab");
    if (fp)
    {
        fwrite(&d, sizeof(struct data), 1, fp);
        fclose(fp);
        return 1;
    }
    else
        return 0;
}

int show()
{
    FILE *fp = fopen("StudentRecords.dat", "rb");
    if (!fp)
        return 0;
    struct data d;
    printf("ROLL\tNAME\tSCORE 1\tSCORE 2\tSCORE 3\tSCORE 4\tSCORE 5\n");
    while (fread(&d, sizeof(struct data), 1, fp))
    {
        if (!d.is_deleted)
        {
            printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", d.roll, d.name, d.score[0], d.score[1], d.score[2], d.score[3], d.score[4]);
        }
    }
    fclose(fp);
    return 1;
}

int logical_delete(int r)
{
    FILE *fp = fopen("StudentRecords.dat", "rb+");
    int c = 0;
    if (!fp)
        return -1;
    struct data d;
    while (fread(&d, sizeof(struct data), 1, fp))
    {
        if (d.roll == r && !d.is_deleted)
        {
            fseek(fp, -sizeof(struct data), SEEK_CUR);
            d.is_deleted = 1; // Mark the record as logically deleted
            fwrite(&d, sizeof(struct data), 1, fp);
            c++;
            break;
        }
    }
    fclose(fp);
    return c;
}
/**int physical_delete()
{
    FILE *fpc=fopen("temp.dat","wb");
    FILE *fp=fopen("StudentsRec.dat","rb");
    struct data d;
    if(!fp||!fpc)
        return 0;
    while(fread(&d,sizeof(struct data),1,fp))
    {
        if(d.is_deleted!=1)
            fwrite(&d,sizeof(struct data),1,fpc);
    }
    System("cp temp.dat StudentsRec.dat");
    System("rm temp.dat");
    fclose(fp);
    fclose(fpc);
    return 1;
}*/

int main()
{
    int ch, r;
    struct data d;
    while (1)
    {
        printf("Enter choice 1 to append 2 to print 3 to logical delete 4 to physical delete any other to exit.\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter roll.\n");
            scanf("%d", &(d.roll));
            printf("Enter name.\n");
            scanf("%s", d.name);
            for (int i = 0; i < 5; i++)
            {
                printf("Enter score %d.\n", i + 1);
                scanf("%f", &(d.score[i]));
            }
            d.is_deleted = 0; // Initialize is_deleted to 0 for a new record
            if (!append_rec(d))
                printf("Cannot open file.\n");
            break;
        case 2:
            if (!show())
                printf("Cannot open file.\n");
            break;
        case 3:
            printf("Enter roll to be deleted.\n");
            scanf("%d", &r);
            r = logical_delete(r);
            if (r == -1)
                printf("Cannot open file.\n");
            else if (r == 0)
                printf("Roll not found or already deleted.\n");
            else
                printf("Roll is logically deleted.\n");
            break;
        /*case 4:
            if(!physical_delete())
                printf("Cannot open file.\n");
            break;*/
        default:
            printf("Exiting.\n");
            return 0;
        }
    }
}
