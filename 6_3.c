#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <Windows.h>
#define size 21

double givenFunc(double x);
double stepX(int t);
double h = 0.1;
double start = 1;
double finish = 2;
int orderP;

double stepX(int arg)
{
  return start + arg*h/2; // По условию, Вариант 6
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

double givenFunc(double x) 
{
  return x*log(x); // По условию, Вариант 6
}

void starting(double started, double finished, double step)
{
	printf("\tx\tf(x)\n");
	for (started; started<finished+h; started+=step)
	{
		printf("\t%.2f\t%.2f\n", started, givenFunc(started));
	}
}

void newNet()
{
	int j = 0;
	double netStore[size][orderP];
	printf("xj\t\tf(xj)\n");
	for (int i = 0; i < size; i++)
	{
		netStore[i][0] = stepX(i);
		netStore[i][1] = givenFunc(stepX(i));
		//printf("x_%d: %.2f\ty_%d: %.2f\n", i, netStore[i][0], i, netStore[i][1]);
		for (int j = 0; j<=orderP; j++)
		{
			netStore[j][i+2] = givenFunc(stepX(j+1))-givenFunc(stepX(j));
			printf("dy_%d: %.2f  ", j+1, netStore[i][j]); 
		}
		puts("");
	}
	/*while (j != size)
	{
		printf("\tx_%d: %.2f\ty_%d: %.2f\tdy_%d: %.2f\n", j, stepX(j), j, givenFunc(stepX(j)), j, givenFunc(stepX(j+1))-givenFunc(stepX(j)));
		j++;
	}*/
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
	do {
		printf("Введите желаемую степень полинома интерполирования в пределах от 1 до %d: ", size-1);
		if (scanf("%d", &orderP) != 1){
			while(getchar() != '\n');
			printf("Степень полинома должна быть числом, попробуйте ещё раз: ");
			continue;
			puts("");
		}
		if (orderP < 1 || orderP> size) {
			printf("Степень полинома должна быть в заданных пределах, попробуйте ещё раз: ");
			puts("");
		}
	} while(orderP <1 || orderP>size);

	starting(start, finish, h);
	newNet();
}



