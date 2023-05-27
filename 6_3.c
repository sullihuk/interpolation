#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define size 20

float givenFunc(float x);
float stepX(int t);
float h = 0.1;
//int n[size];

float stepX(int j)
{
  return 1+j*h/2;
}

float givenFunc(float x)
{
  return x*log(x);
}

void interpolation()
{
  for(int i = 0; i<=size; i++)
  {
    printf("%d %.2f  \n",i+1, givenFunc(stepX(i)));
  }
}

int main()
{
  interpolation();
}



