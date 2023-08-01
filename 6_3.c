#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <Windows.h>
#define size 20

float givenFunc(float x);
float stepX(int t);
float h = 0.1;
float start = 1;
float finish = 2;

float stepX(int j)
{
  return start + j*h/2; // По условию, Вариант 6
}

float givenFunc(float x) 
{
  return x*log(x); // По условию, Вариант 6
}

void starting()
{
	int i = 0;
	printf("\tx\tf(x)\n");
	while (i != size)
	{
		printf("\t%.2f\t%.2f\n",stepX(start), givenFunc(stepX(start)));
		i++;
		start += stepX(start+h);
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
	system("chcp 65001");
	starting();
}



