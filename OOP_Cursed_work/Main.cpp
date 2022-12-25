#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

const int SIZE = 3;

class Organizer
{
	string name;
	string initials;
	string telNum;
	int birthDate[SIZE];

public:
	Organizer()
	{
		name = "";
		initials = "";
		telNum = "";

		for (int i = 0; i < SIZE; i++)
		{
			birthDate[i] = 0;
		}
	}

	Organizer(string name, string initials, string telNum, int birthDate[])
	{
		this->name = name;
		this->initials = initials;
		this->telNum = telNum;
		for (int i = 0; i < SIZE; i++)
		{
			this->birthDate[i] = birthDate[i];
		}
	}
	~Organizer()
	{
		
	}

	string getName()
	{
		return name;
	}
	string getInitials()
	{
		return initials;
	}
	string getTelefone()
	{
		return telNum;
	}
	int getDate()
	{
		return birthDate[0];
	}
	int getMonth()
	{
		return birthDate[1];
	}
	int getYear()
	{
		return birthDate[2];
	}

	void dateOutput()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << this->birthDate[i] << " ";
		};
		cout << endl;
	}

	void tokenize(string const& str, const char delim, vector<string>& out)
	{
		stringstream ss(str); // побудова строкового потоку

		string s;
		while (getline(ss, s, delim))
		{
			out.push_back(s);
		}
	}

	void show()
	{
		cout << "\nName: " << this->name << "\nInitials: " << this->initials << "\nTelephone number: " << this->telNum <<
			"\nBirth date: " << this->birthDate[0] << "." << this->birthDate[1] << "." << this->birthDate[2] << endl;
	}

	friend ofstream& operator << (ofstream& write, Organizer& obj);
};

ofstream& operator << (ofstream& write, Organizer& obj)
{
	write << "\nName: " << obj.getName();
	write << "\nInitials: " << obj.getInitials();
	write << "\nTelephone number: " << obj.getTelefone();
	write << "\nBirth date: ";
	for (int i = 0; i < SIZE; i++)
	{
		write << obj.birthDate[i];
		if (!(i == SIZE - 1))
		{
			write << ".";
		}
	}
	write << "\n\n";

	return write;
}

int main()
{
	string info;
	int infoA[SIZE];
	
	int counter = 0;

	ifstream fin("in.txt");
	ofstream fout("out.txt");

	if (fin)
	{
		while (!fin.eof())
		{
			getline(fin, info, '\n');
			counter++;
		}

		Organizer* dataPointer = new Organizer[counter];

		fin.clear();
		fin.seekg(0);

		for (int i = 0; i < counter; i++)
		{	
			vector <string> res;
			vector <int> intDate;
			string name;
			string initials;
			string telNum;
			string date;
			const char delimiter = '.';
			int dateMass[SIZE];
			
			fin >> name;
			fin >> initials;
			fin >> telNum;
			fin >> date;

			dataPointer[i].tokenize(date, delimiter, res);

			transform(res.begin(), res.end(), back_inserter(intDate), [&](string s)
			{
				stringstream ss(s);
				int i;
				ss >> i;
				return i;
			});

			copy(intDate.begin(), intDate.end(), dateMass);

			dataPointer[i] = Organizer(name, initials, telNum, dateMass);

		}
		
		for (int i = 0; i < counter; i++)
		{
			for (int j = i + 1; j < counter; j++)
			{
				if (dataPointer[i].getName() > dataPointer[j].getName())
				{
					swap(dataPointer[i], dataPointer[j]);
				}
			}
		}

		cout << "\nEnter date of birth on format(no dotes): XX.XX.XXXX (day/month/year)\n";
		cin >> infoA[0] >> infoA[1] >> infoA[2];
		cout << endl;

		cout << "\n-------Our birthdayters/jubilees------\n\n";

		if (!fout.is_open())
		{
			cout << "File can`t opened!\n";
		}
		else
		{
			//cout << "File is opened for recoding!\n\n";
		}

		int num = 0;

		for (int i = 0; i < counter; i++)
		{	
			bool jubileer = true;
			bool birthdater = true;
			int result = 0;
				
			result = dataPointer[i].getYear() - infoA[2];
			
			if ((dataPointer[i].getDate() == infoA[0]) && (dataPointer[i].getMonth() == infoA[1]))
			{
				num++;
				if (dataPointer[i].getYear() == infoA[2])
				{
					cout << "Greating for birthdater: ";
					dataPointer[i].show();
					cout << endl;
					birthdater = false;
					jubileer = false;
					fout << "Greating for birthdater!";
					fout << dataPointer[i];
				}
				if (!(abs(result) % 10) && jubileer != false)
				{
					cout << "\"Special\" greating for jubileer: ";
					dataPointer[i].show();
					cout << endl;
					birthdater = false;
					jubileer = false;
					fout << "\"Special\" greating for jubileer!";
					fout << dataPointer[i];
				}
				if (jubileer != false)
				{
					cout << "Greating for birthdater: ";
					dataPointer[i].show();
					cout << endl;
					jubileer = false;
					fout << "Greating for birthdater!";
					fout << dataPointer[i];
				}
			}
			else
			{
				if (num == 0 && i == counter - 1)
				{
					cout << "Birthdaters/jubileers not found!\n\n";	
				}
			}
		}
		cout << "------------------END-------------------\n\n";

		fin.close();
		fout.close();
	}

	return 0;
}