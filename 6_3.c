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

void starting()
{
	for(float i = 1; i<=2.1; i+=0.1)
	{
		printf(" %.2f %.2f \n",i,givenFunc(i));
	}
}

void interpolation()
{
  for(int i = 0; i<=size; i++)
  {
    printf("%d %.2f %.2f \n",i+1,stepX(i), givenFunc(stepX(i)));
  }
}

int main()
{
	starting();
  interpolation();
}



