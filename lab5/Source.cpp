#define SRT_SECURE_NO_WORNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bfs(int v, int** p, int n, int* vis)
{
	queue <int> q{};
	q.push(v);
	vis[v] = true;

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << ">> " << v + 1 << " ";

		for (int i = 0; i < n; i++)
		{
			if (p[v][i] == 1 and vis[i] == false)
			{
				q.push(i);
				vis[i] = true;
			}
		}
	}
}

void vivod(int** p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, j, n, v; //n - размер матрицы, v - вершина начала обхода алгоритма

	cout << "¬ведите размер матрицы ";
	cin >> n;
	cout << "¬ведите вершину дл€ начала поиска в ширину ";
	cin >> v;
	v -= 1;

	int* vis = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		vis[i] = 0;
	}

	int** p = (int**)malloc(n * sizeof(int*)); //выделение пам€ти дл€ матрицы смежности
	for (i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
	}

	srand(time(NULL));                              //заполнение массива p

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				p[i][j] = 0;
			}
			else
			{
				p[i][j] = rand() % 2;
			}
		}
	}
	for (i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (j = 0; j < n; j++)
		{
			p[j][i] = p[i][j];
		}
	}

	vivod(p, n);
	cout << endl << endl;
	bfs(v, p, n, vis);

	free(p);

	free(vis);
	cout << endl;
	system("pause");
	return 0;
}
