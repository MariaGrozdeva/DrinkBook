#include "Collection.h"

void Collection::CopyFrom(const Collection& other)
{
	capacity = other.capacity;
	current = other.current;

	collection = new Bar * [capacity];
	for (int i = 0; i < current; i++)
		collection[i] = other.collection[i]->clone();
}
void Collection::Free()
{
	for (int i = 0; i < current; i++)
		delete collection[i];
	delete[] collection;
}

void Collection::Resize()
{
	Bar** helper = new Bar * [capacity *= 2];

	for (int i = 0; i < current; i++)
		helper[i] = collection[i];

	delete[] collection;
	collection = helper;
}

void Collection::addNewBar(Bar*& newBar)
{
	if (current == capacity)
		Resize();

	collection[current] = newBar;
	current++;
}
int Collection::checkIfBarExist(const char* barName)
{
	for (int i = 0; i < current; i++)
	{
		if (strcmp(collection[i]->getName(), barName) == 0)
			return i;
	}
	return -1;
}

Collection::Collection()
{
	capacity = 4;
	current = 0;

	collection = new Bar * [capacity];
}
Collection::Collection(const Collection& other)
{
	CopyFrom(other);
}
Collection& Collection::operator=(const Collection& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Collection::~Collection()
{
	Free();
}

void Collection::addPopFolkBar(const char* name, double vodkaPrice, double whiskeyPrice,
	const char* performerName)
{
	cout << "Successfully added "; cout << name << endl;

	Bar* newPopFolkBar = new PopFolkBar(name, vodkaPrice, whiskeyPrice, performerName);
	addNewBar(newPopFolkBar);
}
void Collection::addHouseBar(const char* name, double vodkaPrice, double whiskeyPrice, int DJs)
{
	cout << "Successfully added "; cout << name << endl;

	Bar* newHouseBar = new HouseBar(name, vodkaPrice, whiskeyPrice, DJs);
	addNewBar(newHouseBar);
}
void Collection::addRockBar(const char* name, double vodkaPrice, double whiskeyPrice)
{
	cout << "Successfully added "; cout << name << endl;

	Bar* newRockBar = new RockBar(name, vodkaPrice, whiskeyPrice);
	addNewBar(newRockBar);
}

void Collection::removeBar(const char* barName)
{
	if (checkIfBarExist(barName) == -1)
	{
		cout << "Sorry, such bar doesn't exist." << endl;
		return;
	}

	int posOfBar = checkIfBarExist(barName);

	cout << "Successfully removed "; cout << barName << endl;

	for (int i = posOfBar; i < current - 1; i++)
		collection[i] = collection[i + 1];

	current--;
	capacity--;
}

bool Collection::addToClub(User user, const char* barName)
{
	if (checkIfBarExist(barName) == -1)
	{
		cout << "Sorry, such bar doesn't exist." << endl;
		return false;
	}
	int posOfBar = checkIfBarExist(barName);

	if (!collection[posOfBar]->addUser(user))
		return false;
	return true;
}
void Collection::removeFromClub(const char* nameOfUser, const char* barName)
{
	if (checkIfBarExist(barName) == -1)
	{
		cout << "Sorry, such bar doesn't exist." << endl;
		return;
	}

	int posOfBar = checkIfBarExist(barName);

	collection[posOfBar]->removeUser(nameOfUser);
}

void Collection::Print() const
{
	for (int i = 0; i < current; i++)
	{
		collection[i]->Print();
		cout << endl;
	}
}