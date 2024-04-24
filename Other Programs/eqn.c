#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 250
double determinant(double a[MAX_SIZE][MAX_SIZE], int n);

void main() {
  double a[MAX_SIZE][MAX_SIZE],c[MAX_SIZE][MAX_SIZE],det,d;
  int n;
  printf("number of elements: \n");
  scanf("%d", &n);
  printf("Enter the elements of the first matrix: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
   c[i][j]=a[i][j];
  double b[MAX_SIZE][MAX_SIZE];
  printf("Enter elements of second matrix\n");
  for(int i=0;i<n;i++)
    scanf("%lf",&b[i][0]);
  d=determinant(a,n);
    for(int k=1;k<=n;k++)
    {    for(int j=0;j<n;j++)
          c[j][k-1]=b[j][0];
          det = determinant(c, n);
          if(d==0 && det==0){printf("Infinite many solutions.");return;}
          if(d==0 && det!=0){printf("No solutions.");return;}
          printf("x%d = %lf\n",k,(det/d));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         c[i][j]=a[i][j];
        }
      
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
  }

  return det;
}