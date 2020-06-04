#include "Bar.h"

void Bar::CopyFrom(const Bar& other)
{
	capacityOfUser = other.capacityOfUser;
	current = other.current;

	users = new User[capacityOfUser];
	for (int i = 0; i < current; i++)
		users[i] = other.users[i];
		
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	capacity = other.capacity;
	vodkaPrice = other.vodkaPrice;
	whiskeyPrice = other.whiskeyPrice;
}
void Bar::Free()
{
	delete[] users;
	delete name;
}

Bar::Bar(const char* name, double vodkaPrice, double whiskeyPrice)
{
	capacityOfUser = 4;
	current = 0;

	this->users = new User[capacityOfUser];

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->vodkaPrice = vodkaPrice;
	this->whiskeyPrice = whiskeyPrice;
}

Bar::Bar() : Bar("Unnamed", 0, 0)
{}
Bar::Bar(const Bar& other)
{
	CopyFrom(other);
}
Bar& Bar::operator=(const Bar& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Bar::~Bar()
{
	Free();
}

User* Bar::getUsers() const
{
	return users;
}
char* Bar::getName() const
{
	return name;
}

void Bar::PrintUsers() const
{
	for (int i = 0; i < current; i++)
	{
		users[i].Print();
		cout << endl;
	}
}

void Bar::removeUser(const char* nameOfUser)
{
	bool userExist = false;
	int posOfUser = -1;

	for (int i = 0; i < current; i++)
	{
		if (strcmp(users[i].getName(), nameOfUser) == 0)
		{
			cout << "Successfully removed "; cout << nameOfUser << endl;

			userExist = true;
			posOfUser = i;
		}
	}
	if (!userExist)
	{
		cerr << "Invalid name, such user isn't in the bar." << endl;
		return;
	}

	for (int i = posOfUser; i < current - 1; i++)
		users[i] = users[i + 1];

	current--;
	capacityOfUser--;
}