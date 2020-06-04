#include "User.h"

void User::CopyFrom(const User& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	years = other.years;
	budget = other.budget;
	whiskeys = other.whiskeys;
	vodkas = other.vodkas;

	prefMusic = other.prefMusic;
}
void User::Free()
{
	delete name;
}

User::User(const char* name, int years, double budget, int whiskeys, int vodkas, preferredMusic prefMusic)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->years = years;
	this->budget = budget;
	this->whiskeys = whiskeys;
	this->vodkas = vodkas;

	this->prefMusic = prefMusic;
}

User::User() : User("Unnamed", 0, 0, 0, 0, Whatever)
{}
User::User(const User& other)
{
	CopyFrom(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
User::~User()
{
	Free();
}

void User::setBudget(double budget)
{
	this->budget = budget;
}

char* User::getName() const
{
	return name;
}
int User::getYears() const
{
	return years;
}
double User::getBudget() const
{
	return budget;
}
int User::getWhiskeys() const
{
	return whiskeys;
}
int User::getVodkas() const
{
	return vodkas;
}
preferredMusic User::getPrefMusic() const
{
	return prefMusic;
}

void User::Print() const
{
	using namespace std;

	cout << name << " " << years << " " << budget << " " << whiskeys << " " << vodkas;
}