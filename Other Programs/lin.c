#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 250
double determinant(double a[MAX_SIZE][MAX_SIZE], int n);
int main() {
  double a[MAX_SIZE][MAX_SIZE];
  int n,N,m;
  char *ptr;
  printf("Enter the number of variables: ");
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
  char eqn[1000];
  char str[100];
  printf("Enter equation.\n");
  fflush(stdin);
   scanf("[^\n]s",eqn);
   N=strlen(eqn);
   for(int j=0,k=0;k,N;k++)
  {if(eqn[k]==' ')
  m=0;
  while(eqn[k]<'a'&& eqn[k]>'z')
  str[m++]=eqn[k++];
  a[i-1][j]=strtod(str,&ptr);
}
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    printf("%lf\t",a[i][j]);
    printf("\n");
  }
  double det = determinant(a, n);
  printf("The determinant of the matrix is: %.2lf\n", det);
  return 0;
}
double determinant(double a[MAX_SIZE][MAX_SIZE], int n) {
  double det = 0;
  if (n == 1) {
      det = a[0][0];
  } else if (n == 2) {    
    det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
  } else {    
    for (int i = 0; i < n; i++) 
    {
      double submatrix[MAX_SIZE][MAX_SIZE];
      for (int j = 1; j < n; j++) 
      {
        int sub_i = 0;
        for (int k = 0; k < n; k++)
         {
          if (k == i) {
            continue;
          }
          submatrix[sub_i][j - 1] = a[j][k];
          sub_i++;
        }
      }
      det += a[0][i] * determinant(submatrix, n - 1) * (i % 2 == 0 ? 1 : -1);
    }
   return det;
  }
}