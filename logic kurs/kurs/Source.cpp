#define CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

void dfs(int v, int** p1, int n, int* vis, ofstream & FILE)
{

	vis[v] = true;
	printf(">> %d ", v + 1);

	FILE << v + 1 << " ";
	for (int i = 0; i < n; i++)
	{
		if ((p1[v][i] == 1) and (vis[i] == 0))
		{
			dfs(i, p1, n, vis, FILE);
		}
	}
}

void vivod(int n, int** p, ofstream & FILE ) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", p[i][j]);
			FILE << p[i][j] << " ";
		}
		printf("\n");
		FILE << endl;
	}

}




int main() {
	setlocale(LC_ALL, "Rus");

	ofstream FILE("vivod.txt");

	double ver, tmp;
	int i = 0, j = 0, n, v, vibor;
	int** p1, * vis;
	bool proverka = false;

	cout << "�������� ��� �� ������ ������ ������� ���������: "
		<< endl << "1. �������� �������������"
		<< endl << "2. ������ �������"
		<< endl << "3. ������ �� �����"
		<< endl;

	while (!proverka)
	{
		cin >> vibor;
		if (vibor == 1 || vibor == 2 || vibor == 3) {
			proverka = true;
		}
		else
		{
			printf("������� ������� ������� ��� � �� ����������. ���������� ��� ���.\n");
		}
	}

	if (vibor == 1)
	{
		printf("������� ������ ������������ �������: >> ");
		scanf_s("%d", &n);
		printf("\n������� ����������� �� 0 �� 100 %: ");
		cin >> ver;


		srand(time(NULL));

		p1 = (int**)malloc(n * sizeof(int*));			//��������� ������ ��� ��, ���������� � ��������������
		for (int i = 0; i < n; i++)
		{
			p1[i] = (int*)malloc(n * sizeof(int));
		}
		vis = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)							//���������� ������� p1
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
		for (i = 0; i < n; i++)							//�������������� �������
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
		vivod(n, p1, FILE);
		printf("\n");
		printf("������� ������� � ������� �������� �����: >> ");
		scanf_s("%d", &v);
		v -= 1;
		printf("�����������\n");
		dfs(v, p1, n, vis, FILE);
		printf("\n");

		for (i = 0; i < n; i++)
		{

			if (vis[i] == 0)
			{
				dfs(i, p1, n, vis, FILE);
				printf("\n");
			}
		}
	}
	if (vibor == 2)
	{
		cout << "������� ���������� ������ � �������: ";
		scanf_s("%d", &n);
		cout << endl;
		int** matrix;
		int numb;
		p1 = (int**)malloc(n * sizeof(int*));			//��������� ������ ��� ��, ���������� � ��������������
		for (int i = 0; i < n; i++)
		{
			p1[i] = (int*)malloc(n * sizeof(int));
		}
		vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			cout << "���� " 
				<< i + 1 
				<< "-� ������" 
				<< endl 
				<< endl;
			for (int j = 0; j < n; j++) {
				if (i == j)
				{
					cout << j + 1 
						<< "-� ������� ������� �� ��������� 0" 
						<< endl;
					p1[i][j] = 0;
				}

				else
				{
					proverka = false;
					while (!proverka) {
						cout << "������� "
							<< j + 1
							<< "-� ������� �������: ";
						cin >> numb;
						cout << endl;
						if (numb == 0 || numb == 1) {
							p1[i][j] = numb;
							proverka = true;
						}

						else
						{
							cout << "���������� ������ 0 ��� 1. ��������� �������"
								<< endl;
							proverka = false;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
		}
		printf("\n");
		vivod(n, p1, FILE);
		printf("\n");
		printf("������� ������� � ������� �������� �����: >> ");
		scanf_s("%d", &v);
		v -= 1;
		printf("�����������\n");
		dfs(v, p1, n, vis, FILE);
		printf("\n");

		for (i = 0; i < n; i++)
		{

			if (vis[i] == 0)
			{
				dfs(i, p1, n, vis, FILE);
				printf("\n");
			}
		}
	}
	if (vibor == 3)
	{
		ifstream file("matrix.txt");
		if (!file.is_open()) { // ���� ���� �� ������
			cout << "���� �� ����� ���� ������!\n";
			system("pause");
			return 1;
		}
		file >> n;
		cout << "���������� ������ � ������� �����: "
			<< n
			<< endl;

		p1 = (int**)malloc(n * sizeof(int*));			//��������� ������ ��� ��, ���������� � ��������������
		for (int i = 0; i < n; i++)
		{
			p1[i] = (int*)malloc(n * sizeof(int));
		}
		vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				file >> p1[i][j];
				if (p1[i][j] != 0 && p1[i][j] != 1) {
					cout << "� ������� ��������� ������� �������� 0 ��� 1. ��������� �������."
						<< endl;
					system("pause");
					return 1;
				}
				if (i == j) {
					if (p1[i][j] != 0) {
						cout << "� ������� �� ��� �������� ������� ��������� ����. ��������� �������."
							<< endl;
						system("pause");
						return 1;
					}
				}
			}
		}
		printf("\n");
		vivod(n, p1, FILE);
		printf("\n");
		printf("������� ������� � ������� �������� �����: >> ");
		scanf_s("%d", &v);
		v -= 1;
		printf("�����������\n");
		dfs(v, p1, n, vis, FILE);
		printf("\n");

		for (i = 0; i < n; i++)
		{

			if (vis[i] == 0)
			{
				dfs(i, p1, n, vis, FILE);
				printf("\n");
			}
		}
	}
	FILE.close();

	system("pause");
}
