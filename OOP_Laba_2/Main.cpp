#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>


//-----------------------------������ 5-------------------------------
// �������� ���� �������, �����, ��:
// �) ���� ��������� ������ ����� ������ � ������.
// b) ���� ����������� ��� ��������� ������� ��������� � ��������� 0, �
// ����������� � ����������� ������� ��������� � ��������� ���������
// ������ � ������.
// c) ���� ������ ���������� ���������� � ����������� �������� ������ �
// ������ �� ����������� �������� ��'���.
// d) ������� print_val() �������� �� ����� �������� ���� ������, ������
// �ᒺ��.
// e) ������ ������� frd � ����� ��������� ������ ���������� ����
// ������� � ������� ����� ������, �ᒺ� ����� ������� ��� �ᒺ��
// ��� ���� �������, � ����� ������� ������������� ����� ��� ����
// �������

using namespace std;

class Cylinder
{
	double radius;
	double height;
	double volume;

public:

	Cylinder()
	{
		radius = 5.6;
		height = 9.1;
		cout << "No parameters constructor for this object: " << this << endl << endl;
	}

	Cylinder(double RADIUS, double HEIGHT)
	{
		radius = RADIUS;
		height = HEIGHT;
		cout << "Constructor with parameters for this object: " << this << endl;
	}

	~Cylinder()
	{
		cout << "\"Calling\" the deconstructor for object: " << this << endl;
	}

	double getRadius()
	{
		return radius;
	}

	void setRadius(double radius)
	{
		this -> radius = radius;
	}

	double getHeight()
	{
		return height;
	}

	void setHeight(double height)
	{
		this -> height = height;
	}

	void print_val()
	{
		const double PI = 3.14159;
		volume = 1.0 / 3.0 * PI * (radius * radius) * height;
		cout << "--------------------\n" << "Radius for object: " << this << " " << radius << endl << "Height for object: " << this << " " << height << endl
			<< "Volume for object: " << this << " " << volume << endl << endl;
	}
	
	void printInfoForNewCylinder()
	{
		cout << "--------------------\n" << "Radius for object: " << this << " " << radius << endl << "Height for object: " << this << " " << height << endl
			<< "Volume for object: " << this << " " << volume << endl << endl;
	}

	friend Cylinder frd (Cylinder& firstC, Cylinder& secondC, double hei);
};

Cylinder frd (Cylinder& firstC, Cylinder& secondC, double hei)
{

	double newVolume = firstC.volume + secondC.volume;
	double x = firstC.radius;
	double y = secondC.radius;

	double radius = max(x, y);

	Cylinder newCyl (radius, hei);

	newCyl.volume = newVolume;

	newCyl.printInfoForNewCylinder();

	return newCyl;

}

int main()
{
	double storageR, storageH;
	
	cout << "Enter radius for second cylinder\n";
	cin >> storageR;
	cout << "Enter heigth for second amd new cylinders\n";
	cin >> storageH;

	Cylinder cyl1, cyl2(storageR, storageH);

	cyl1.print_val();
	cyl2.print_val();

	Cylinder newCyl = frd(cyl1, cyl2, storageH);

	return 0;
}