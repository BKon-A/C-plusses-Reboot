#include <iostream>

using namespace std;

//----------------------------VARIANT 4-----------------------------------
//Згенерувати і вивести на екран масив з цілого числа n випадкових
//чисел від - 120 до 120. Вивести номер передостаннього додатного елемента.
//Чисто n вводить користувач.
//------------------------------------------------------------------------

int Random(int min, int max) 
{
	return min + rand() % (max - min);
}

void bublleSort(int capasity, int *arrayPointer)
{
	int tmp;

	for (int i = 0; i < capasity - 1; i++)
	{
		for (int j = 0; j < capasity - 1; j++)
		{
			if (arrayPointer[j + 1] > arrayPointer[j])
			{
				tmp = arrayPointer[j + 1];
				arrayPointer[j + 1] = arrayPointer[j];
				arrayPointer[j] = tmp;
			}
		}
	}
}

void dynamicArrayFilling(int capasity, int *arrayPointer)
{
	for (int i = 0; i < capasity; i++)
	{
		arrayPointer[i] = Random(-120, 120);
	}

	cout << "Unsorted array: ";
	for (int i = 0; i < capasity; i++)
	{
		cout << arrayPointer[i] << " ";
	}
}

int main()
{
	int value, positive = 0;

	cout << "Enter number of elements is array: ";
	cin >> value;

	int* arrayPointer = new int[value];

	dynamicArrayFilling(value, arrayPointer);

	//bublleSort(value, arrayPointer);

	for (int val = value - 1; val > 0; val--)
	{
		if (arrayPointer[val] > 0)
		{
			positive++;

			if (positive == 2)
			{
				cout << "\n\nNumber(index) of second positive element is: " << val;
				break;
			}
		}
	}

	return 0;
		
}