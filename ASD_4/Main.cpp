#include <iostream>
#define N 1000

const int elt = 10;

using namespace std;

//Завдання до лабораторної роботи
//1. Для даних таблиць 1 реалізувати алгоритми пошуку вказаними
//методами.
//2. Визначити кількість порівнянь при виконанні різних алгоритмів
//
//                     Зауваження!!!
//Вхідні масиви цілих чисел містять по 500 елементів із випадковими
//числами зі значеннями від 0 до N - 1. N = 1000;
//
//----------------------Variant 4-----------------------------------
//4. Кількість елементів від 0 до N - 1, що є в масиві B, Алгоритми
//пошуку : бінарний, Фібоначі

void sortArray(int a[])
{
	int tmp;

	for (int i = 0; i < elt - 1; i++)
	{
		for (int j = 0; j < elt - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < elt; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

int binarySearch(int a[], int lB, int rB, int key)
{
	while (lB <= rB)
	{
		int middle = (lB + rB) / 2;

		if (a[middle] == key)
			return true;

		else if (a[middle] > key)
			rB = middle - 1;

		else
			lB = middle + 1;
	}
	return false;
}

int min(int x, int y) 
{ 
	return (x <= y) ? x : y; 
}

int fibanachiSearch(int a[], int key, int numElements)
{

	int fibMMm2 = 0;
	int fibMMm1 = 1;
	int fibM = fibMMm2 + fibMMm1;

	while (fibM < numElements)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	int offset = -1;

	while (fibM > 1)
	{

		int i = min(offset + fibMMm2, numElements - 1);

		if (a[i] < key)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		else if (a[i] > key)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		else 
		{
			return true;
		}
	}

	if (fibMMm1 && a[offset + 1] == key)
		return offset + 1;
	
	return false;
}

void arrayFilling(int a[], int b[])
{
	int el = 0;

	for (int i = 0; i < elt; i++)
	{
		a[i] = rand() % 20;
		b[i] = rand() % 20;
		el = i;
	}

	cout << endl << endl << el + 1 << endl;
}

int main()
{
	int i = 0, end = 500, numberOfMatchesBinary = 0, numberOfMatchesFibbanachi = 0;

	int A[elt];
	int B[elt];

	/*cout << "Enter a searched number: ";
	cin >> key;*/

	arrayFilling(A, B);

	cout << endl << endl;

	sortArray(A);
	sortArray(B);

	cout << endl << endl;

	for (int i = 0; i < N - 1; i++)
	{
		if ((binarySearch(A, 0, elt - 1, i)) && (binarySearch(B, 0, elt - 1, i)))
		{
			numberOfMatchesBinary++;
		}
	}

	cout << "Binary search matches: " << numberOfMatchesBinary << endl << endl;

	for (int i = 0; i < N - 1; i++)
	{
		if ((fibanachiSearch(A, i, elt)) && (fibanachiSearch(B, i, elt)))
		{
			numberOfMatchesFibbanachi++;
		}
	}

	cout << "Fibanachi search matches: " << numberOfMatchesFibbanachi << endl << endl;
}