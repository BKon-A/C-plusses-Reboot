#include <iostream>
#include <conio.h>

const int numberOfElements = 12;

using namespace std;

//-------------------------Variant 5---------------------------------
//Створити клас, конструктор якого генерує динамічний масив
//чисел(див.варіанти) Розмір масиву задається параметром конструктора.
//Деструктор звільняє пам’ять, що виділена під масив.Написати для  
//класу конструктор копіювання, в якому і визначити спосіб копіювання
//одного екземпляру класу в інший.
//
//|№	   | Тип	 |   Кількість |   Вираз для обчислення   |   Вказівки до обробки|
//|варіанта| даних   |  елементів  |	 елемента масиву      |                      |
//|		   |	     |			   |   парного  | непарного   |                      |
//|--------|---------|-------------|------------|-------------|----------------------|
//|5.      | Дійсний |      12     |    i - 6.0 |      i      |   Знайти кількість   |
//|        |         |             |            |             |   від’ємних елементів|
//|________|_________|_____________|____________|_____________|______________________|


class DynanicArrayCreation
{
	float* arrayPointer;
	int numOfElements;

public:

	DynanicArrayCreation (int numOfElements)
	{
		this->numOfElements = numOfElements;

		this->arrayPointer = new float[numOfElements];

		for (int i = 0; i < numOfElements; i++)
		{
			arrayPointer[i] = rand() % 11 - 10; // -10 : +10
			cout << arrayPointer[i] << " ";
		}

		cout << "\n\nMemory allocated for this " << this << " object\n\n";
	};

	DynanicArrayCreation (const DynanicArrayCreation& replicatedObj)
	{
		this->numOfElements = replicatedObj.numOfElements;

		this->arrayPointer = new float[replicatedObj.numOfElements];

		for (int i = 0; i < numOfElements; i++)
		{
			if ((int)replicatedObj.arrayPointer[i] % 2)
			{
				this->arrayPointer[i] = replicatedObj.arrayPointer[i];
				cout << replicatedObj.arrayPointer[i] - 6.0 << " ";
			}
			else
			{
				this->arrayPointer[i] = replicatedObj.arrayPointer[i];
				cout << replicatedObj.arrayPointer[i] << " ";
			}
			
		}

		cout << "\nChinese copy constructor for this " << this << " object\n\n";

		numberOfNegativeElements(replicatedObj);
	}

	~DynanicArrayCreation()
	{
		cout << "You called for a cleanup for this " << this << " object?\n";
		delete[] arrayPointer;
	}

	void numberOfNegativeElements(const DynanicArrayCreation& replicatedObj)
	{
		int counter = 0;

		for (int i = 0; i < numberOfElements; i++)
		{
			if (replicatedObj.arrayPointer[i] < 0)
			{
				counter++;
			}
		}

		cout << "Number of negative elements for object: " << this << " is " << counter << "\n\n";
	}
};

int main()
{
	DynanicArrayCreation notCopy(numberOfElements);

	DynanicArrayCreation copy(notCopy);

	return 0;
}