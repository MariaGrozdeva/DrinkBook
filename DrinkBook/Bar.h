#include "User.h"
#pragma once

class Bar
{
protected:
	User* users;

	int capacityOfUser; // max number of users
	int current; // current number of users

	char* name;

	int capacity; // max space in the club
	double vodkaPrice;
	double whiskeyPrice;

	void CopyFrom(const Bar& other);
	void Free();

public:
	Bar(const char* name, double vodkaPrice, double whiskeyPrice);

	Bar();
	Bar(const Bar& other);
	Bar& operator=(const Bar& other);
	virtual ~Bar();

	User* getUsers() const;
	char* getName() const;

	void PrintUsers() const;

	void removeUser(const char* nameOfUser);

	virtual bool addUser(User user) = 0;

	virtual void setVodkaPrice(int vodkaPrice) = 0;
	virtual void setWhiskeyPrice(int whiskeyPrice) = 0;

	virtual void Compare() = 0;

	virtual Bar* clone() = 0;

	virtual void Print() const = 0;
};