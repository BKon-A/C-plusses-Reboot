#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

//	1. Написати програму на мові С++, яка створює одномірний масив з
//N елементів відповідно варіанту.
//	2. Написати програму на мові С++ для дослідження опису та
//використання двовимірних масивів, відповідно варіанту завдання.
//--------------------------Variant 4---------------------------------
//Task1.Згенерувати і вивести на екран масив з цілого числа n випадкових
//чисел від - 120 до 120. Вивести номер передостаннього додатного елемента.
//Task2.Ввести матрицю розмірності m  n і число k.Видалити k - й стовпець із
//матриці.Вивести вхідну і отриману матриці.

using namespace std;

int Random(int min, int max) {
	return min + rand() % (max - min);
}

int task1 ()
{
	int n = 0, i = 0, resultTask1;

	cout << "Enter a number of elements in array: ";
	cin >> n;

	int *M = new int[n];

	for (i = 0; i < n; i++)
	{
		M[i] = Random(-120, 120);
		cout << M[i] << " ";
	}

	cout << endl << endl;

	reverse(M, M + n);

	for (i = 0; i < n; i++)
	{
		cout << M[i] << " ";
	}

	cout << endl << endl;


	for (i = 0; i < n;)
	{
		
		if (M[i] >= 0)
		{	
			if (M[i] >= 0 && M[i] != M[0]) 
			{
				resultTask1 = n - i;
				cout << "Number of element: " << resultTask1 << " in array";
				break;
			}

			i++;
			continue;
		}

		else
		{
			i++;
			continue;
		}		
	}

	return 0;	
}

int task2 ()
{
	int m = 0, n = 0, k = 0, max_i = 0, max_j = 0;

	cout << "Enter number of rows: ";
	cin >> m;
	cout << "Enter number of columns: ";
	cin >> n;
	cout << "Enter number of deleted column: ";
	cin >> k;

	k = k - 1;

	int** dynMas = new int* [m];
	for (int i = 0; i < m; i++)
	{
		dynMas[i] = new int [n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dynMas[i][j] = rand() % 9;
		}
	}

	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dynMas[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	int** temp = new int* [m];
	for (int i = 0; i < m; i++)
	{
		temp[i] = new int[n - 1];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0, j1 = 0; j < n; j++)
		{
			if (j != k)
				temp[i][j1++] = dynMas[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		delete[] dynMas[i];
	}
	delete[] dynMas;

	dynMas = temp;
	--n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dynMas[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		delete[] dynMas[i];
	}
	delete[] dynMas;

	return 0;
}

int main() 
{
	cout << "Task1" << endl << endl;
	task1();

	cout << endl << endl;

	cout << "Task2" << endl << endl;
	task2();
}
