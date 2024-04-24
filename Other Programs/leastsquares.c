#include <stdio.h>
#include <math.h>

#define MAX_N 100   

int main()
{
    int n;             
    double x[MAX_N];   
    double y[MAX_N];   
    double sum_x = 0;  
    double sum_y = 0; 
    double sum_xy = 0; 
    double sum_x2 = 0; 
    double a, b;       

    // Read in the data
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    // Calculate the coefficients of the regression line
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    // Print the regression line
    printf("Regression line: y = %.2f + %.2f x\n", a, b);

    return 0;
}
