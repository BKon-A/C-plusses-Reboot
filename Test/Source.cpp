#include <iostream>

using namespace std;

const int numOfElements = 15;

void numbersCalculating(int mass[])
{
	int product = 1, summ = 0;
	int startIndex = NULL, endIndex = NULL;
	for (int i = 0; i < numOfElements; i++)
	{
		// перший нуль
		if(mass[i] == 0 && startIndex == NULL) 
		{
			startIndex = i;
		}

		// останній нуль
		if (mass[(numOfElements-1)-i] == 0 && endIndex == NULL) 
		{
			endIndex = (numOfElements - 1) - i;
		}
		
		// добуток і сума
		if ((startIndex != NULL && endIndex != NULL) && (i > startIndex && i < endIndex))
		{
			
			if (i % 2)
			{
				product *= mass[i]; // добуток
			}
			summ += mass[i]; // сума
		}
	}

	cout << "Product of numbers: " << product << "\nSum of numbers: " << summ;
}

void sortArray(int a[])
{
	int tmp;

	for (int i = 0; i < numOfElements - 1; i++)
	{
		for (int j = 0; j < numOfElements - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	cout << "Sorted array: ";

	for (int i = 0; i < numOfElements; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

int main()
{
	int mass[numOfElements], counter = 0;
	bool pass = false;

	cout << "|Elements of array from keyboard|\n";

	for (int i = 0; i < numOfElements; i++)
	{
		cout << "Element " << i << ": ";
		cin >> mass[i];
		if (cin.fail())
		{
			cout << "\nYou enter is (non-interger number/not number)!\n";
			cin.clear();
			cin.ignore();
			exit(0);
		}
	}

	for (int i = 0; i < numOfElements; i++)
	{
		if (mass[i] == 0)
		{
			counter++;

			if (counter > 2)
			{
				pass = true;
			}
			else
			{
				cout << "Is not enought zeroes";
				exit(0);
			}
		}
	}
	if (pass)
	{
		cout << "\n\n";

		numbersCalculating(mass);

		cout << "\n\n";

		sortArray(mass);

		return 0;
	}

	return 0;
}