#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

void dfs(int v, int** p1, int n, int* vis)
{

	vis[v] = true;
	printf(">> %d ", v + 1);
	for (int i = 0; i < n; i++)
	{
		if ((p1[v][i] == 1) and (vis[i] == 0))
		{
			dfs(i, p1, n, vis);
		}
	}
}

void vivod(int n, int** p) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

}




int main() {
	
	setlocale(LC_ALL, "Rus");
	double ver, tmp;
	int i = 0, j = 0, n, v;
	printf("¬ведите размер генерируемой матрицы: >> ");
	scanf_s("%d", &n);
	printf("\n¬ведите веро€тность от 0 до 100 %: ");
	cin >> ver;
	int** p1, * vis;

	srand(time(NULL));

	p1 = (int**)malloc(n * sizeof(int*));			//выделение пам€ти под всЄ, заполнение и отзеркаливание
	for (int i = 0; i < n; i++)
	{
		p1[i] = (int*)malloc(n * sizeof(int));
	}
	vis = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)							//заполнение массива p1
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				p1[i][j] = 0;
			}
			else
			{
				tmp = rand() % 100;
				if (tmp < ver)
					p1[i][j] = 1;
				else
					p1[i][j] = 0;
			}
		}
	}
	for (i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (j = 0; j < n; j++)
		{
			p1[j][i] = p1[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	printf("\n");
	vivod(n, p1);
	printf("\n");
	printf("¬ведите вершину с которой начнетс€ обход: >> ");
	scanf_s("%d", &v);
	v -= 1;
	printf("–екурсивный\n");
	dfs(v, p1, n, vis);
	printf("\n");
	
	for (i = 0; i < n; i++)
	{
	
		if (vis[i] == 0)
		{
			dfs(i, p1, n, vis);
			printf("\n");
		}
	}
	system("pause");
}
