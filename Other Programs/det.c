#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 250

double determinant(double a[MAX_SIZE][MAX_SIZE], int n);

int main() {
  double a[MAX_SIZE][MAX_SIZE];
  int n;

  // Read in the size of the matrix and the matrix elements
  printf("Enter the size of the matrix: ");
  scanf("%d", &n);
  printf("Enter the elements of the matrix: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }

  // Calculate and print the determinant
  double det = determinant(a, n);
  printf("The determinant of the matrix is: %.2lf\n", det);

  return 0;
}

// Function to calculate the determinant of an nxn matrix
double determinant(double a[MAX_SIZE][MAX_SIZE], int n) {
  double det = 0;

  if (n == 1) {
    // Base case: 1x1 matrix
    det = a[0][0];
  } else if (n == 2) {
    // Base case: 2x2 matrix
    det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
  } else {
    // Recursive case: nxn matrix
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