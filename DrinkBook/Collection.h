#include "PopFolkBar.h"
#include "HouseBar.h"
#include "RockBar.h"

class Collection
{
private:
	Bar** collection;

	int capacity;
	int current;

	void CopyFrom(const Collection& other);
	void Free();

	void Resize();

	void addNewBar(Bar*& newBar);
	int checkIfBarExist(const char* barName);

public:
	Collection();
	Collection(const Collection& other);
	Collection& operator=(const Collection& other);
	~Collection();

	void addPopFolkBar(const char* name, double vodkaPrice, double whiskeyPrice, const char* performerName);
	void addHouseBar(const char* name, double vodkaPrice, double whiskeyPrice, int DJs);
	void addRockBar(const char* name, double vodkaPrice, double whiskeyPrice);
	void removeBar(const char* barName);

	bool addToClub(User user, const char* barName);
	void removeFromClub(const char* nameOfUser, const char* barName);

	void Print() const;
};