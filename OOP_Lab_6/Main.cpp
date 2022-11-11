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

	string getNameOrg()
	{
		return nameOfOrganisation;
	}

	void setNameOrg(string name)
	{
		this->nameOfOrganisation = name;
	}

	float getBudget()
	{
		return budget;
	}
	void setBudget(float value)
	{
		this->budget = value;
	}

	void showInfoOrganisation()
	{
		cout << "Organisation: " << getNameOrg() 
			<< " have budget: " << getBudget() << "\n";
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
		budgetLosses = 1900000.59;
	}
	InsuranceProvider(string name, float losses)
	{
		this->nameOfDoutherCompanyforInsurance = name;
		this->budgetLosses = losses;
	}
	~InsuranceProvider()
	{

	}

	string getNameInsCompany()
	{
		return nameOfDoutherCompanyforInsurance;
	}
	void setNameInsCompany(string name)
	{
		this->nameOfDoutherCompanyforInsurance = name;
	}

	float getBudgetLosses()
	{
		return budgetLosses;
	}

	float getInsPaiment()
	{
		return InsurancePayment;
	}

	void showInfoProvider()
	{
		cout << "Insurance company: " << getNameInsCompany() 
			<< " have losses: " << getBudgetLosses() << "\n";
	}
};

class BuildingCompany : public InsuranceProvider
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

	string getNameBuildingCompany()
	{
		return nameOfDoutherCompanyforBuildingCompany;
	}

	void setNameBuildingCompany(string name)
	{
		this->nameOfDoutherCompanyforBuildingCompany = name;
	}

	int getTime()
	{
		return timeForConstruction;
	}
	void setTime(int value)
	{
		this->timeForConstruction = value;
	}
	float getCost()
	{
		return costOfConstructionPerUnitOfTime;
	}
	void showInfoBuildCompany()
	{
		cout << "Building company: " << getNameBuildingCompany() 
			<< " cost: " << getCost() << " and have time: " << getTime() << "\n";
	}
};

class MetroBuildCompany : public BuildingCompany
{
	string nameOfBuildedObject;
	float spent;
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

	string getNameOfObject()
	{
		return nameOfBuildedObject;
	}

	void setNameOfObject(string name)
	{
		this->nameOfBuildedObject = name;
	}

	float getDistance()
	{
		return distant;
	}
	void setDistance(float value)
	{
		this->distant = value;
	}

	float isSpent( float cost)
	{
		spent = distant * cost;
		return spent;
	}

	void showInfoBuidedObject()
	{
		cout << "Builded object: " << getNameOfObject() 
			<< " have distasce: " << getDistance() << " and it has been spent on him " << spent << "\n";
	}
};

int main()
{
	float compensationDef = 0, compensation = 0, cost = 0, costDef = 0;
	float budgetDef = 0, budget = 0;

	Organisation organisation, organisationConstructed("Conglomerate", 2000000.1);
	InsuranceProvider insProvider, insProviderConstructed("Unreliable", 1000000.0);
	BuildingCompany buildCompany, buildCompanyConstructed("DefBuilder", 62);
	MetroBuildCompany newBranch, newBranchConstructed("NUBiP-Washington", 7365.23);

	compensationDef = insProvider.getBudgetLosses() * insProvider.getInsPaiment();
	compensation = insProviderConstructed.getBudgetLosses() * insProviderConstructed.getInsPaiment();

	costDef = buildCompany.getTime() * buildCompany.getCost();
	cost = buildCompanyConstructed.getTime() * buildCompanyConstructed.getCost();
	
	budgetDef = organisation.getBudget() + compensationDef;
	budget = organisationConstructed.getBudget() + compensation;

	cout << "New branch: " << newBranch.getNameOfObject() << "is costed: " << newBranch.isSpent(costDef);
	cout << "\nNew branch: " << newBranchConstructed.getNameOfObject() << "is costed: " << newBranchConstructed.isSpent(cost);

	cout << "\n---------------\nAll info\n-----------------\n";
	cout << "Defoult object\n";
	organisation.showInfoOrganisation();
	insProvider.showInfoProvider();
	buildCompany.showInfoBuildCompany();
	newBranch.showInfoBuidedObject();
	cout << "\nConstructed object\n";
	organisationConstructed.showInfoOrganisation();
	insProviderConstructed.showInfoProvider();
	buildCompanyConstructed.showInfoBuildCompany();
	newBranchConstructed.showInfoBuidedObject();

	cout << "\nOrganisation: " << organisation.getNameOrg() << " incurred losses(or no losses): " << budgetDef - newBranch.isSpent(costDef);
	cout << "\nOrganisation: " << organisationConstructed.getNameOrg() << " incurred losses(or no losses): " << budget - newBranchConstructed.isSpent(cost);

	return 0;
}