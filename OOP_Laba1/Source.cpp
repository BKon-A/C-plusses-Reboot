#include <iostream>
#include "Source.h"

// ------------------Варіант 5------------------------------------------
// Створити клас «конус», такий, що:
// а) його екземпляр містить розмір радіуса і висоти.
// b) його конструктор без параметра створює екземпляр зі значенням 0, а
// конструктор з параметрами створює екземпляр з відповідним значенням
// радіуса і висоти.
// c) його методи дозволяють отримувати і присвоювати значення радіуса і
// висоти та обчислювати значення об'єму.
// d) функція print_val() виводить на екран значення його радіуса, висоти та
// об’єму.

using namespace std;

class Cone
{
	double radius;
	double height;
	//double volume;

public:

	Cone()
	{
		radius = 0;
		height = 0;
		cout << "No parameters constructor for this object: " << this << endl;
	}

	Cone(double RADIUS, double HEIGHT)
	{
		radius = RADIUS;
		height = HEIGHT;
		cout << "Constructor with parameters for this object: " << this << endl;
	}

	~Cone()
	{
		cout << "\"Calling\" the deconstructor for object: " << this << endl;
	}

	double GetRadius_n_Heigth()
	{
		return radius;
		return height;
	}

	void SetRadius_n_Height(double radValue, double heiValue)
	{
		radius = radValue;
		height = heiValue;
	}

	void print_val()
	{
		const double PI = 3.14159;
		double volume = 1.0 / 3.0 * PI * (radius * radius) * height;
		cout << "--------------------\n" << "Radius for object: " << this << " " << radius << endl << "Height for object: " << this << " " << height << endl
			<< "Volume for object: " << this << " " << volume << endl << endl;
	}

	

};

int main()
{
	double storageR, storageH;

	Cone firstCone;
	cout << endl;
	cout << "Enter radius parametr: ";
	cin >> storageR;

	cout << "Enter height parametr: ";
	cin >> storageH;
	cout << endl;
	Cone secondCone(11.2, 22.2);

	Cone thirdCone;

	thirdCone.SetRadius_n_Height(storageR, storageH);
	
	firstCone.print_val();
	secondCone.print_val();
	thirdCone.print_val();

	Cone* P = new Cone[3];
	P->SetRadius_n_Height(5.5, 6.6);
	(P + 1)->SetRadius_n_Height(50.5, 36.6);
	(P + 2)->SetRadius_n_Height(45.5, 77.2);
	
	void (Cone::* pf)();
	pf = &Cone::print_val;
	(P[1].*pf)();

}