#include <iostream>
#include <conio.h>
#include <time.h>

//-------------------------Variant 4---------------------------------
//Відповідно варіанту завдання(таблиця 2.2), обчислити значення функції у,
//розклавши функцію f(x) у ряд Тейлора.Розробити програми згідно з
//алгоритмом з використанням рекурсивної функції та без використання
//рекурсивної функції.Оцінити час виконання та складність алгоритму.Формули
//розкладання в ряд Тейлора деяких функцій наведені в таблиці 2.1

using namespace std;

double loopFactorial(int n);

double recursionFactorial(int n)
{

	if (n < 2) 
		return 1;  
	else 
		return n * recursionFactorial(n - 1); 
}

double recursionTaylorExp (double x, int n, const double PRECISION = 0.00000001) // розклад в ряд Тейлора за допомогою рекурсії
{

	if (n == 0)
		return 1;

	double Try = recursionTaylorExp(x, n - 1);

	if (abs(Try) < PRECISION)
		return Try;

	return (Try + pow(x, n) / recursionFactorial(n));
}

double loopTaylorExp(double x, int n, const double PRECISION = 0.0000001) // розклад в ряд Тейлора за допомогою циклу
{
	int i = 1;
	double summ = 0;
	double an = 1.;

	while (an > PRECISION)
	{
		summ += an;
		an *= x / i;
		i++;
	}
	n = i;

	return summ;
}

double loopFactorial (int n)
{

	double Lock = 1;

	for (int i = 1; i <= n; i++)
	{
		Lock *= i;
	}

	return Lock;
}

double LibraryYFunction(int n, int m, double x)
{
	double result = 0;
	int variant = 0;

	while (1)
	{
		cout << "You want use recursion(1) or cycle(2): ";
		cin >> variant;
		switch (variant)
		{
		case 1:
			cout << exp(x);
			result = ((n - m) * exp(x)) / (recursionFactorial(n) - recursionFactorial(m));
			return result;
			break;
		case 2:
			cout << exp(x);
			result = ((n - m) * exp(x)) / (loopFactorial(n) - loopFactorial(m));
			return result;
			break;
		default:
			cout << "It`s not a number, try again";
			continue;
		}
	}
}

double functionYwithRec(int n, int m, double x)
{

	double result = ((n - m) * recursionTaylorExp(x, n)) / (recursionFactorial(n) - recursionFactorial(m));

	return result;
}

double functionYwithLoop(int n, int m, double x)
{

	double result = ((n - m) * loopTaylorExp(x, n)) / (loopFactorial(n) - loopFactorial(m));

	return result;
}

int main()
{
	double EnterX = 0;

	int EnterN = 0, variant = 0;
	int EnterM = 0;

	double resRec, resLoop, rex, le, resLib;

	clock_t start, end;

	cout << "We have a Y function: (n - m) + e^x / (n! - m!)\n";
	cout << "And f(x) = e^x function, which will be decomposed into a Taylor series\n\n";

	cout << "Enter n: ";
	cin >> EnterN;

	cout << "Enter m: ";
	cin >> EnterM;
	
	cout << "Enter x: ";
	cin >> EnterX;

	cout << "-------------------------------------\n"
		"Recursion version of the programme execution\n"
		"-------------------------------------\n";
	start = clock();
	rex = recursionTaylorExp(EnterX, EnterN);
	cout << "Taylor exponent: " << rex << endl;
	resRec = functionYwithRec(EnterN, EnterM, EnterX);
	cout << "Function Y with recursion: " << resRec << endl;
	end = clock();

	printf("The above code block was executed in %.8f second(s)\n\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

	cout << "-------------------------------------\n"
		"Loop version of the programme execution\n"
		"-------------------------------------\n";
	start = clock();
	le = loopTaylorExp(EnterX, EnterN);
	cout << "Taylor exponent: " << le << endl;
	resLoop = functionYwithLoop(EnterN, EnterM, EnterX);
	cout << "Function Y with loop: " << resLoop << endl;
	end = clock();

	printf("The above code block was executed in %.8f second(s)\n\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

	cout << "-------------------------------------\n"
		"Custom (library exp() function + choise: rec/loop) version of the programme execution\n"
		"-------------------------------------\n";
	start = clock();
	resLib = LibraryYFunction(EnterN, EnterM, EnterX);
	cout << endl << "Function Y with library exponent function: " << resLib << endl;
	end = clock();

	printf("The above code block was executed in %.8f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

	return 0;
}
