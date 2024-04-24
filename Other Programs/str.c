#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    struct addr
    {
        char name[100];
        char street[200];
        char city[50];
        char state[50];
        char country[50];
        long int zip;
    };
    struct addr jack={"Jack Kilby","14/3 Lincoln Street","New York","New York","USA",123456};
    printf("Name= %s\n",jack.name);
    printf("Street= %s\n",jack.street);
    printf("City= %s\n",jack.city);
    printf("State= %s\n",jack.state);
    printf("Country= %s\n",jack.country);
    printf("ZIP= %d\n",jack.zip);
    printf("%d\n",sizeof(jack));
    return 0;
}