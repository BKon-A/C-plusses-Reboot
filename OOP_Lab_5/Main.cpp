#include <iostream>
#include <conio.h>

using namespace std;

class Cone
{
	float radius;
	float height;
	float volume;
	int value;

public:

	Cone()
	{
		radius = 0;
		height = 0;

		cout << "Non-param constructor for this object: " << this <<"\n\n";
	}

	Cone(float radius, float height)
	{
		this->radius = radius;
		this->height = height;
	}

	~Cone()
	{
		cout << "Object " << this << " destroyed\n";
	}

	float getRadius()
	{
		return radius;
	}
	void setRadius(float radius)
	{
		this->radius = radius;
	}

	float getHeight()
	{
		return height;
	}
	void setHeight(float height)
	{
		this->height = height;
	}

	float getVolume()
	{
		return volume;
	}
	void setVolume(float volume)
	{
		this->volume = volume;
	}

	void setValue(int value)
	{
		this->value = value;
	}
	float getValue()
	{
		return value;
	}

	void volumeCalculate()
	{
		const double PI = 3.14159;
		volume = 1.0 / 3.0 * PI * (radius * radius) * height;
	}

	void show()
	{
		cout << "--------------------\n" << "Radius for object: " << this << " " << radius << endl << "Height for object: " << this << " " << height << endl
			<< "Volume for object: " << this << " " << volume << endl << endl;
	}

	friend ostream& operator << (ostream& value, Cone& obj1); // new left shift
	friend Cone operator + (Cone& cone1, Cone& cone2);

	Cone operator ++ (); //prefix ver. op-r ++
	Cone operator ++ (int value); //postfix ver. op-r ++
};

ostream& operator << (ostream& value, Cone& obj1)
{
	value << obj1.radius << endl;
	value << obj1.height << endl;
	value << obj1.volume << endl;

	return value;
}

Cone operator + (Cone& cone1, Cone& cone2)
{
	Cone newCone(cone1.radius + cone2.radius, cone1.height + cone2.height);
	
	newCone.volume = 0;

	return newCone;
}

Cone Cone :: operator ++ ()
{
	radius++;
	height++;

	return *this;
}

Cone Cone :: operator ++ (int usefull)
{
	Cone temp = *this;

	radius = radius + value;
	height = height + value;

	return temp;
}

int main()
{
	Cone nonParamObj, paramObj(9.5, 15.2), newCone;

	nonParamObj.setRadius(2.0);
	nonParamObj.setHeight(4.5);
	nonParamObj.setValue(1);
	paramObj.setValue(1);

	nonParamObj.volumeCalculate();
	paramObj.volumeCalculate();

	cout << "---------------------------------------\n\n";
	cout << "Prefix version for operator ++: \n\n";
	++nonParamObj;
	++paramObj;
	cout << "\nNon-parametrs object: \n" << nonParamObj;
	cout << "\nParametrised object: \n" << paramObj;

	cout << "\n---------------------------------------\n\n";
	cout << "Postfix version for operator ++: \n\n";
	nonParamObj++;
	paramObj++;
	cout << "\nNon-parametrs object: \n" << nonParamObj;
	cout << "\nParametrised object: \n" << paramObj << "\n";

	newCone = nonParamObj + paramObj;
	cout << "\n---------------------------------------\n";
	cout << "\nNew cone: \n" << newCone << "\n";
	cout << "---------------------------------------\n\n";

	cout << "Use new \"Left shift\"\n";
	cout << "\nNon-parametrs object: \n" << nonParamObj;
	cout << "\nParametrised object: \n" << paramObj << "\n";
	cout << "New cone: \n" << newCone << "\n";

	return 0;
}