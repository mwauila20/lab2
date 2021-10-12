//#include "StdAfx.h""
#include <stdio.h> // задание 2
#include <malloc.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
using namespace std;


int compareubivan(const void* x1, const void* x2)
{
	
	return (*(int*)x2 - *(int*)x1);
	

}
int comparevozr(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void shellvozr(int n, int mass[])
{
	
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp > mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}
	
}

void shellubiv(int n, int mass[])
{

	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}

}






void qsubiv(int* items, int left, int right)
{
	
int i, j;
int x, y;


i = left; j = right;
/* выбор компаранда */
x = items[(left + right) / 2];


do {
	while ((items[i]>x) && (i<right)) i++;
	while ((x>items[j]) && (j>left)) j--;

	if (i <= j) {
		y = items[i];
		items[i] = items[j];
		items[j] = y;
		i++; j--;
	}
} while (i<= j);
if (left<j) qsubiv(items, left, j);
if (i<right) qsubiv(items, i, right);


}
void qsvozr(int* items, int left, int right)
{
	
	
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qsvozr(items, left, j);
	if (i < right) qsvozr(items, i, right);

}
void main()
{
	
	clock_t start, end;
	int n,left,right;
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов массива" << endl;
	cin >> n ;
	start = clock();
	int* A = new int[n];
	int* A_orig = new int[n];
	srand(time(NULL));
	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
	{
		A_orig[i] = rand() % 10;
		//cout << A_orig[i] << " ";
	}
	left = 0; right = n - 1;
	start = clock();
	qsubiv(A, left, right);
	qsvozr(A, left, right);
	if (n % 2)
	{
		qsort(A + (n / 2), n / 2 + 1, sizeof(int), comparevozr);
	}
	else {


		qsort(A + (n / 2), n / 2, sizeof(int), comparevozr);
	}

	end = clock();
	printf(" %.14f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	for (int i = 0; i < n; i++)
	{
		A[i] = A_orig[i];
		//cout << A[i] << " ";
	}
	start = clock();
	
	
	qsort(A, n / 2, sizeof(int), compareubivan);
	qsort(A, n, sizeof(int), comparevozr);
	if (n % 2)
	{
		qsort(A + (n / 2), n / 2 + 1, sizeof(int), comparevozr);
	}
	else {


		qsort(A + (n / 2), n / 2, sizeof(int), comparevozr);
	}
	end = clock();
	printf(" %.14f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	left = n/2; right = n - 1;
	//start = clock();
	//end = clock();
	//printf(" %.14f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	start = clock();
	shellubiv(n / 2, A + n / 2);
	shellvozr(n / 2, A);
	end = clock();
	printf(" %.14f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	//cout << endl << "Результирующий массив: ";
	//for (int i = 0; i < n; i++) cout << A[i] << " ";
	delete[]A;
	//end = clock();
	//printf(" %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	system("pause>>void");


}










































