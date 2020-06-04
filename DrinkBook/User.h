#include <iostream>
using namespace std;

#pragma warning (disable : 4996)
#pragma once

enum preferredMusic { PopFolk, House, Rock, Whatever };

class User
{
private:
	char* name;

	int years;
	double budget;
	int whiskeys;
	int vodkas;
	preferredMusic prefMusic;

	void CopyFrom(const User& other);
	void Free();

public:
	User(const char* name, int years, double budget, int whiskeys, int vodkas, preferredMusic prefMusic);

	User();
	User(const User& other);
	User& operator=(const User& other);
	~User();

	void setBudget(double budget);

	char* getName() const;
	int getYears() const;
	double getBudget() const;
	int getWhiskeys() const;
	int getVodkas() const;
	preferredMusic getPrefMusic() const;

	void Print() const;
};