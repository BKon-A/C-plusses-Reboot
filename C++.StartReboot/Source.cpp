#include <iostream>

//4. Визначити, у якому відношенні розбиває задана точка заданий відрізок.

using namespace std;

int main()
{
	int startSegment, endSegment, point, counterStart, counterEnd;

	cout << "Enter the start of the segment: ";
	while (!(cin >> startSegment))
	{
		cin.clear();
		while (cin.get() != '\n');

		cout << "Try again!" << endl;
		cout << "Enter the start of the segment again: ";
	}

	cout << "Enter the end of the segment: ";
	while (!(cin >> endSegment))
	{
		cin.clear();
		while (cin.get() != '\n');

		cout << "Try again!" << endl;
		cout << "Enter the end of the segment again: ";
	}

	cout << "Put a point: ";
	while (!(cin >> point))
	{
		cin.clear();
		while (cin.get() != '\n');

		cout << "Try again!" << endl;
		cout << "Put a point again: ";
	}

	for (counterStart = 0; startSegment < point; startSegment++, counterStart++)
	{
		
	}

	for (counterEnd = 0; point < endSegment; point++, counterEnd++)
	{

	}

	if (counterStart == counterEnd)
	{
		cout << "Party attitude: 1 to 1";
	}
	else
	{
		cout << "Party attitude: " << counterStart << " to " << counterEnd << endl;
	}

}