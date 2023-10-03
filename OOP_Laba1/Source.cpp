#include <iostream>
#include "Source.h"

// ------------------������ 5------------------------------------------
// �������� ���� ������, �����, ��:
// �) ���� ��������� ������ ����� ������ � ������.
// b) ���� ����������� ��� ��������� ������� ��������� � ��������� 0, �
// ����������� � ����������� ������� ��������� � ��������� ���������
// ������ � ������.
// c) ���� ������ ���������� ���������� � ����������� �������� ������ �
// ������ �� ����������� �������� ��'���.
// d) ������� print_val() �������� �� ����� �������� ���� ������, ������ ��
// �ᒺ��.

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

	void setRadius(double radValue)// double heiValue)
	{
		radius = radValue;
		//height = heiValue;
	}
	void setHeight(double heiValue)// double heiValue)
	{
		//radius = radValue;
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

	thirdCone.setRadius_n_Height(storageR);
	
	firstCone.print_val();
	secondCone.print_val();
	thirdCone.print_val();

	Cone* P = new Cone[4];
	P->setRadius_n_Height(5.5);
	P->setHeight(6.5);
	(P + 1)->setRadius_n_Height(50.5);
	(P + 2)->setRadius_n_Height(45.5);
	
	void (Cone::* pf)();
	pf = &Cone::print_val;
	(P[0].*pf)();

}