#include <stdio.h>
#include <stdlib.h>
#include "polynomialADT.c"
#define FACTOR_OF_SAFETY 0.2
#define MAX_TERMS 120
int main() {
    int choice;
    int avail = 0,availc,beg=0,p1,p2;
    int sf[2][MAX_TERMS]; 
    int i,j,n,e;
    float c;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter polynomials\n");
        printf("2. Add polynomials\n");
        printf("3. Multiply polynomials\n");
        printf("4. Display polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:                  
                printf("Enter number of terms of poly.\n");
                scanf("%d",&n);
                printf("Enter poly.\n");
                sf[0][beg]=avail;
                sf[1][beg]=avail+n-1;
                for(i=sf[0][beg];i<=sf[1][beg];i++)
                {
                    printf("Enter coeff.\n");
                    scanf("%f",&c);
                    printf("Enter exp.\n");
                    scanf("%d",&e);
                    attach(c,e,avail);  
                    avail++;  
                }   
                beg+=1;                  
                break;
            case 2: 
                printf("Which two to add?\n");
                scanf("%d",&p1);
                scanf("%d",&p2);
                availc=avail;
                avail=add(sf[0][p1-1],sf[1][p1-1],sf[0][p2-1],sf[1][p2-1],avail);
                printf("Sum= ");
                print(availc,avail-1);
                break;           
            case 3: 
                printf("Which two to multiply?\n");
                scanf("%d",&p1);
                scanf("%d",&p2);
                availc=avail;
                avail=mult(sf[0][p1-1],sf[1][p1-1],sf[0][p2-1],sf[1][p2-1],avail);
                printf("Product= ");
                print(availc,avail-1);
                printf("\n");
                break;
            case 4: 
                print(0,avail-1);
                printf("\n");
                break;
            default:
                printf("Exiting...\n");
                return 0;
        }
    }
}