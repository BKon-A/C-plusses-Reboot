#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>


//-----------------------------¬ар≥ант 5-------------------------------
// —творити клас Ђцил≥ндрї, такий, що:
// а) його екземпл€р м≥стить розм≥р рад≥уса ≥ висоти.
// b) його конструктор без параметра створюЇ екземпл€р з≥ значенн€м 0, а
// конструктор з параметрами створюЇ екземпл€р з в≥дпов≥дним значенн€м
// рад≥уса ≥ висоти.
// c) його методи дозвол€ють отримувати ≥ присвоювати значенн€ рад≥уса ≥
// висоти та обчислювати значенн€ об'Їму.
// d) функц≥€ print_val() виводить на екран значенн€ його рад≥уса, висоти
// обТЇму.
// e) дружн€ функц≥€ frd в €кост≥ параметр≥в отримуЇ екземпл€ри двох
// цил≥ндр≥в ≥ повертаЇ новий цил≥ндр, обТЇм €кого дор≥внюЇ сум≥ обТЇм≥в
// цих двох цил≥ндр≥в, а рад≥ус дор≥внюЇ максимальному серед цих двох
// цил≥ндр≥в

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