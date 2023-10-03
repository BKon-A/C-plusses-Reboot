#include <iostream>

const int N = 100000;

using namespace std;

//1. ����������� ����� ��������� 1000 ��������:
//a.������������ �� ����������;
//b.� ����������� ���������� �� 0 �� 1000;
//c.������������ �� ���������.
//2. ��� ����� ������� 5.2 ���������� ��������� ���������� �� ����������,
//��������� ��� ���� :
//a.������� ��������;
//10
//b.������� �����.
//3. ���������� ������������ ����������� � ������ �������
//----------------------------Variant 4----------------------------------
//4. |���������� �������| |����� �����|  |����� �����|

void sortingBySelection(int a[], bool growing)
{
	int numOfComparisons = 0, numOfExchanges = 0;

	if(growing)
	{
		for (int i = 0; i < N - 1; i++)
		{
			numOfComparisons++;
			int minNum = i;

			for (int j = i + 1; j < N; j++)
			{
				if (a[minNum] > a[j])
				{
					minNum = j;
				}
			}

			swap(a[i], a[minNum]);
			numOfExchanges++;
		}
		//numOfComparisons = 3 * (N - 1);
	}	
	else
	{
		for (int i = 0; i < N - 1; i++)
		{
			numOfComparisons++;
			int maxNum = i;
			for (int j = i + 1; j < N; j++)
			{
				if (a[maxNum] < a[j])
				{
					maxNum = j;
				}
			}

			swap(a[i], a[maxNum]);
			numOfExchanges++;
		}
		//numOfComparisons = N * 2 / 4 + 3 * (N - 1);
	}

	cout << "\nComparisons: " << numOfComparisons << "\t Changes: " << numOfExchanges << "\n";
}

void sortingByShellMethod(int a[], bool growing)
{
	int numOfComparisons = 0, numOfExchanges = 0, i = 0, j = 0;

	int step = 0, temp = 0;
	if (growing)
	{
		for (step = N / 2; step > 0; step /= 2)
		{
			numOfComparisons++;
			for (i = step; i < N; i++)
			{
				temp = a[i];
				for (j = i; j >= step; j -= step)
				{
					if (temp < a[j - step])
						a[j] = a[j - step];
					else
						break;
				}
				a[j] = temp;
				numOfExchanges++;
			}
		}
	}

	else
	{
		for (step = N / 2; step > 0; step /= 2)
		{
			numOfComparisons++;
			for (i = step; i < N; i++)
			{
				temp = a[i];
				for (j = i; j >= step; j -= step)
				{
					if (temp > a[j - step])
						a[j] = a[j - step];
					else
						break;
				}
				a[j] = temp;
				numOfExchanges++;
			}
		}
	}

	cout << "\nComparisons: " << numOfComparisons << "\t Changes: " << numOfExchanges << "\n";
}

void sortingByHoarrMethod(int a[], int startInt, int endInt, bool growing, int *pNumberOfComparisons, int *pNumberOfExchanges)
{
	if (growing)
	{
		int start = startInt;
		int end = endInt;
		int temp = 0;

		if (start >= end)
		{
			return;
		}

		int middle = a[(start + end) / 2];
		while (start <= end)
		{
			while (a[start] < middle)
				start++; // ������ ����
			(*pNumberOfComparisons)++;
			while (a[end] > middle)
				end--; // ��� ������������
			(*pNumberOfComparisons)++;

			if (start <= end)
			{
				temp = a[start]; // ������ ������
				a[start] = a[end];
				a[end] = temp;
				start++; // �������� ���
				end--;
				(*pNumberOfExchanges)++;
			}
		}
		if (startInt < end)
		{
			sortingByHoarrMethod(a, startInt, end, growing, pNumberOfComparisons, pNumberOfExchanges);
		}
		if (start < endInt)
		{
			sortingByHoarrMethod(a, start, endInt, growing, pNumberOfComparisons, pNumberOfExchanges);
		}
	}
	else
	{
		int start = startInt;
		int end = endInt;
		int temp = 0;

		if (start >= end)
		{
			return;
		}

		int middle = a[(start + end) / 2];
		while (start <= end)
		{
			while (a[start] > middle)
				start++; // ������ ����
			(*pNumberOfComparisons)++;
			while (a[end] < middle)
				end--; // ��� ������������
			(*pNumberOfComparisons)++;

			if (start <= end)
			{
				temp = a[start]; // ������ ������
				a[start] = a[end];
				a[end] = temp;
				start++; // �������� ���
				end--;
				(*pNumberOfExchanges)++;
			}
		}
		if (startInt < end)
		{
			sortingByHoarrMethod(a, startInt, end, growing, pNumberOfComparisons, pNumberOfExchanges);
		}
		if (start < endInt)
		{
			sortingByHoarrMethod(a, start, endInt, growing, pNumberOfComparisons, pNumberOfExchanges);
		}
	}
}

void arrayFilling(int a[])
{
	int el = 0;

	for (int i = 0; i < N; i++)
	{
		a[i] = (time(NULL) * rand()) % 1000;
		el = i;
	}

	cout << "\nFilled array: ";

	/*for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}*/
	cout << endl << endl << el + 1 << endl;
}

int main()
{
	int array[N];
	bool choise;

	arrayFilling(array);

	cout << "(Selection)Sort by growing or decreasing (1/0): ";
	cin >> choise;

	sortingBySelection(array, choise);

	/*for (int i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}*/

	arrayFilling(array); // sorting reset

	cout << "(Shell)Sort by growing or decreasing (1/0): ";
	cin >> choise;

	sortingByShellMethod(array, choise);

	/*for (int i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}*/
	arrayFilling(array); // sorting reset

	cout << "(Quick Sort == Hoarr)Sort by growing or decreasing (1/0): ";
	cin >> choise;

	int numberOfComparisons = 0, numberOfExchanges = 0;

	sortingByHoarrMethod(array, 0, N-1, choise, &numberOfComparisons, &numberOfExchanges);

	cout << "\nComparisons: " << numberOfComparisons << "\t Changes: " << numberOfExchanges << "\n";

	/*for (int i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}*/

	return 0;
}