#include <iostream>

using namespace std;

template <class Arrays> class OneDementionalArray;

const int SIZE = 10;

template <class Arrays>
class OneDementionalArray
{

public:

	Arrays mass[SIZE];

	OneDementionalArray() 
	{

		/*for (int i = 0; i < SIZE; i++)
		{
			mass[i] = rand() % 13;
			cout << mass[i] << " ";
		}*/

		for (int i = 0; i < SIZE; i++) // for equal check
		{
			mass[i] = i;
			cout << mass[i] << " ";
		}

		cout << endl;
	}
	
	~OneDementionalArray()
	{
		
	}

	int getSize()
	{
		return SIZE;
	}
	template <class Arrays> friend ostream& operator << (ostream& out, OneDementionalArray<Arrays>& obj);
	template <class T> friend bool operator == (OneDementionalArray<Arrays>& array1, OneDementionalArray<Arrays>& array2);
};

template<class Arrays>
ostream& operator << (ostream& out, OneDementionalArray<Arrays>& obj)
{
	for (int i = 0; i < SIZE; i++)
	{
		out << obj.mass[i] << " ";
	}
	out << "\n";
	return out;
}

template<class Arrays>
bool operator == (OneDementionalArray<Arrays>& array1, OneDementionalArray<Arrays>& array2)
{
	if (array1.mass[SIZE] == array2.mass[SIZE])
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (array1.mass[i] == array2.mass[i])
			{	
				if (i == SIZE-1)
				{
					cout << "\nArrays is equal!\n";
					return true;
				}
				continue;
			}
			else
			{
				break;
			}
			
		}
		cout << "\nArrays is unequal!\n";
		return false;
	}
	else
	{
		cout << "\nArrays is unequal!\n";
		return false;
	}
}

//template<class Operators>
//bool operator == (OneDementionalArray<Arrays>, OneDementionalArray<Arrays>& array2)
//{
//	if (SIZE == array1.SIZE && SIZE == array2.SIZE)
//	{
//
//		//for (int i = 0; i < SIZE; i++)		out << obj[i] << " ";

//		//{
//		//	if (array1[i] == array2[i])
//		//	{
//		//		//cout << "Hits: " << i;
//		//	}
//		//	else if (i == SIZE)
//		//	{
//		//		cout << "\nArrays is equal!\n";
//		//		//return true;
//		//	}
//		//	else
//		//	{
//		//		break;
//		//	}
//		//	
//		//	cout << "\nArrays is unequal!\n";
//		//	/*return false;*/
//		//}
//	}
//	else
//	{
//		cout << "\nArrays is unequal!\n";
//		/*return false;*/
//	}
//}
		
int main()
{
	OneDementionalArray<int> obj1;
	OneDementionalArray<int> obj2;

	cout << "\nArray1 is equal Array2?\n";

	obj1 == obj2;

	cout << "\nMass1: " << obj1;
	cout << "Mass2: " << obj2;

	return 0;
}