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
void printer(int params, double arr[params][orderP+2]);
void endingDif(double arr[size][orderP+2]);

void printer(int params, double arr[params][orderP+2])
{
	for (int i = 0; i < params+2; i++)
	{
		for (int j = 0; j < orderP+2-i; j++)
		{
			printf("%.3f ", arr[i][j]);
		}
		puts("");
	}
	printf("%d", params);
}

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
	int iI = (int)((finished+step-started)/step);
	double netStore[iI][orderP+2];
	printf("x     f(x)\n");
	for (int i = 0; i < iI+1; i++)
	{
		netStore[i][0] = started;
		netStore[i][1] = givenFunc(started);
		for (int j = 2; j<=orderP+2; j++)
		{
			netStore[i][j] = 0;
		}
		started += step;
	}

	/*for (started; started<finished+h; started+=step)
	{
		int i = 0;
		netStore[i][0] = started;
		netStore[i][1] = givenFunc(started);
		for (int j = 2; j<=orderP+2; j++)
		{
			//netStore[i][j] = 0;
		}
		i++;
	}*/
	//endingDif(netStore);
	printer(iI,netStore);
}

void newNet()
{
	//double netStore[size][orderP+2];
	printf("xj    f(xj)\n");
	for (int i = 0; i < size; i++)
	{
		//netStore[i][0] = stepX(i);
		//netStore[i][1] = givenFunc(stepX(i));
		for (int j = 2; j<=orderP+2; j++)
		{
			//netStore[i][j] = 0;
		}
	}
	//endingDif(netStore);
	//printer(netStore);
}

void endingDif(double arr[size][orderP+2])
{
	for (int i = 2; i<size; i++)
	{
		for (int j = 0; j<orderP-i+2; j++)
		{
			arr[j][i] = arr[j+1][i-1] - arr[j][i-1];
		}
	}
}

void interpolation()
{
	for(int i = 0; i<orderP; i++)
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
	//newNet();
}



