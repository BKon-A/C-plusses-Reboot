#include <iostream>
#include <conio.h>

using namespace std;

class Organisation
{
	string nameOfOrganisation;
	float budget;

public:
	Organisation()
	{
		nameOfOrganisation = "Meteor";
		budget = 1500000.396; // dollars
	}
	Organisation(string name, float budget)
	{
		this->nameOfOrganisation = name;
		this->budget = budget;
	}

	~Organisation()
	{

	}
};

class InsuranceProvider : public Organisation
{
	string nameOfDoutherCompanyforInsurance;
	float InsurancePayment = 0.67; // 67% compensation from losses
	float budgetLosses;

public:
	InsuranceProvider()
	{
		nameOfDoutherCompanyforInsurance = "WaHYiDM"; // We are help you in difficult moment
	}
	InsuranceProvider(string name, float losses)
	{
		this->nameOfDoutherCompanyforInsurance = name;
		this->budgetLosses = losses;
	}
	~InsuranceProvider()
	{

	}
};

class BuildingCompany : public Organisation
{
	string nameOfDoutherCompanyforBuildingCompany;
	int timeForConstruction; // days
	float costOfConstructionPerUnitOfTime;

public:
	BuildingCompany()
	{
		nameOfDoutherCompanyforBuildingCompany = "TCO"; // The Chosen Ones
		timeForConstruction = 50; // days
		costOfConstructionPerUnitOfTime = 22500; // dollars
	}
	BuildingCompany(string name, int time)
	{
		this->nameOfDoutherCompanyforBuildingCompany = name;
		this->timeForConstruction = time;
		if (time > 75)
		{
			costOfConstructionPerUnitOfTime = 15000;
		}
		if (time > 100)
		{
			costOfConstructionPerUnitOfTime = 12500;
		}
		if (time < 50 && time > 0)
		{
			costOfConstructionPerUnitOfTime = 25000;
		}
		if (time > 50 && time < 75)
		{
			costOfConstructionPerUnitOfTime = 17500;
		}
	}
};

class MetroBuildCompany : public BuildingCompany, public InsuranceProvider
{
	string nameOfBuildedObject;
	float howMuchBudgetMoneyIsSpent;
	float distant;

public:
	MetroBuildCompany()
	{
		nameOfBuildedObject = "Odessa - Kyiv";
		distant = 800; // kilometrs
	}
	MetroBuildCompany(string name, float distant)
	{
		this->nameOfBuildedObject = name;
		this->distant = distant;
	}

	~MetroBuildCompany()
	{

	}
};

int main()
{
	MetroBuildCompany newBranch();

}