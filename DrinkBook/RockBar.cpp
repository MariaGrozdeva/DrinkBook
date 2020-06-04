#include "RockBar.h"

RockBar::RockBar(const char* name, double vodkaPrice, double whiskeyPrice) :
	Bar(name, vodkaPrice, whiskeyPrice)
{
	capacity = MAX_CAPACITY_ROCK;
	Compare();
}
RockBar::RockBar() : Bar()
{}

bool RockBar::addUser(User user)
{
	if (user.getPrefMusic() == 1)
	{
		cout << "Bad idea, house fans regularly leave rock clubs with not those good memories." << endl;
		return false;
	}
	if (current >= capacity)
	{
		cout << "No space for more people" << endl;
		return false;
	}
	if ((user.getWhiskeys() * whiskeyPrice) + (user.getVodkas() * vodkaPrice) > user.getBudget())
	{
		cout << "Not enough cash for " << user.getWhiskeys() << " whiskeys and " << user.getVodkas() << " vodkas" << endl;
		return false;
	}
	if (user.getYears() < 18)
	{
		cout << "Too young, sorry. You'd rather go to a pop folk club :)" << endl;
		return false;
	}
	cout << "Successfully added " << user.getName() << endl;

	users[current] = user;
	current++;

	return true;
}

void RockBar::setVodkaPrice(int vodkaPrice)
{
	if (vodkaPrice < MIN_VODKA_PRICE_ROCK)
		this->vodkaPrice = MIN_VODKA_PRICE_ROCK;
	this->vodkaPrice = vodkaPrice;
}
void RockBar::setWhiskeyPrice(int whiskeyPrice)
{
	if (whiskeyPrice < MIN_WHISKEY_PRICE_ROCK)
		this->whiskeyPrice = MIN_WHISKEY_PRICE_ROCK;
	this->whiskeyPrice = whiskeyPrice;
}

void RockBar::Compare()
{
	if (vodkaPrice < MIN_VODKA_PRICE_ROCK)
		this->vodkaPrice = MIN_VODKA_PRICE_ROCK;
	if (whiskeyPrice < MIN_WHISKEY_PRICE_ROCK)
		this->whiskeyPrice = MIN_WHISKEY_PRICE_ROCK;
}

RockBar* RockBar::clone()
{
	return new RockBar(*this);
}

void RockBar::Print() const
{
	if (current >= 1)
	{
		cout << "Users in " << name << ":" << endl;
		PrintUsers(); cout << endl;
	}
	cout << name << " " << capacity << " " << vodkaPrice << " " << whiskeyPrice;
}