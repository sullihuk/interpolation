#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define size 20
#define h 0.1

float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}
 
// calculating factorial of given number n
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
 
int main()
{
    // Number of values given
    int n = size;
    float a = 1;
    float b = 2;
    float x[10];
    // y[][] is used for difference table
    // with y[][0] used for input
    float y[n][n];
    while (a==b)
    {
      int i = 0;
      x[i] = a;
      a += h;
        printf("%.0f\n",x[i]);
      i++;
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
    // Calculating the forward difference
    // table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
 
    // Displaying the forward difference table
    for (int i = 0; i < n; i++) {
        printf("%.0f\t",x[i]);
        for (int j = 0; j < n - i; j++)
        	printf("%.4f\t",y[i][j]);
	puts("");
    }
    return 0;
}
