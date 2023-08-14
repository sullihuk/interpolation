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
void printer(int params, double** arr);
void endingDif(double** arr);
double qComp(double q, int n);

double stepX(int arg)
{
  return start + arg * h / 2; // По условию, Вариант 6
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
  return x * log(x); // По условию, Вариант 6
}

void printer(int params, double** arr)
{
  for (int i = 0; i < params; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%.3f ", arr[i][j]);
    }
    for (int j = 2; j < orderP + 2 - i; j++)
    {
      printf("%.3f ", arr[i][j]);
    }
    puts("");
  }
}

void endingDif(double** arr)
{
  for (int i = 2; i < size; i++)
  {
    for (int j = 0; j < orderP - i + 2; j++)
    {
      arr[j][i] = arr[j + 1][i - 1] - arr[j][i - 1];
    }
  }
}

void starting(double started, double finished, double step, double** netStore)
{
  double cher = (finished + step - started) / step;
  int iI = (int)cher;
  printf("x     f(x)\n");
  for (int i = 0; i < iI; i++)
  {
    netStore[i][0] = started;
    netStore[i][1] = givenFunc(started);
    for (int j = 2; j <= orderP + 3; j++)
    {
      netStore[i][j] = 0;
    }
	started += step;
  }
	endingDif(netStore);
	printer(iI, netStore);
}

void newNet(double** netStore)
{	
	double q;
	double polynom;
	double** newnetStore = malloc(size * sizeof(double*));
	for (int i = 0; i < size; i++)
	{
		newnetStore[i] = malloc(size * sizeof(double));
		newnetStore[i][0] = stepX(i);
		if (newnetStore[i][0] == netStore[i][0])
		{
			polynom = netStore[i][1];
			q = (newnetStore[i][0] - netStore[i][0])/(netStore[i+1][0] - netStore[i][0]); 
		}
		if (newnetStore[i][0] > netStore[i][0] && i!=0)
		{
			polynom = netStore[i-1][1];
			q = (newnetStore[i][0] - netStore[i-1][0])/(netStore[i][0] - netStore[i-1][0]); 
		}
		
		polynom += (qComp(q, i+1)*netStore[0][i+2])/fact(i+1);
		newnetStore[i][1] = polynom;
		for (int j = 0; j < 2; j++) {
			printf("%.3f ", newnetStore[i][j]); 
			//printf("%.3f ", netStore[i][j]); 
		}
		puts("");
	}
}

double qComp(double q, int n)
{
	double temp = q;
	for (int i = 1; i<n; i++)
		temp = temp * (q-i);
	return temp;
}

int main()
{
  system("chcp 65001");
  do {
    printf("Введите желаемую степень полинома интерполирования в пределах от 1 до %d: ", size - 1);
    if (scanf("%d", &orderP) != 1) {
      while (getchar() != '\n');
      printf("Степень полинома должна быть числом, попробуйте ещё раз: ");
      continue;
      puts("");
    }
    if (orderP < 1 || orderP > size) {
      printf("Степень полинома должна быть в заданных пределах, попробуйте ещё раз: ");
      puts("");
    }
  } while (orderP < 1 || orderP > size);

  double** netStore = malloc(size * sizeof(double*));
  for (int i = 0; i < size; i++) {
    netStore[i] = malloc((orderP + 2) * sizeof(double));
  }

  starting(start, finish, h, netStore);
  newNet(netStore);
}
