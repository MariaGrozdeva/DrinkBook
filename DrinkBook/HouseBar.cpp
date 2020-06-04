#include "HouseBar.h"

HouseBar::HouseBar(const char* name, double vodkaPrice, double whiskeyPrice, int DJs) :
	Bar(name, vodkaPrice, whiskeyPrice)
{
	Compare();
	
	this->DJs = DJs;
}
HouseBar::HouseBar() : Bar()
{
	DJs = 0;
}

bool HouseBar::addUser(User user)
{
	if (user.getPrefMusic() == 0)
	{
		cout << "Bad idea, house music is not to pop folk fans' taste" << endl;
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

void HouseBar::setVodkaPrice(int vodkaPrice)
{
	if (vodkaPrice < MIN_VODKA_PRICE_HOUSE)
		this->vodkaPrice = MIN_VODKA_PRICE_HOUSE;
	this->vodkaPrice = vodkaPrice;
}
void HouseBar::setWhiskeyPrice(int whiskeyPrice)
{
	if (whiskeyPrice < MIN_WHISKEY_PRICE_HOUSE)
		this->whiskeyPrice = MIN_WHISKEY_PRICE_HOUSE;
	this->whiskeyPrice = whiskeyPrice;
}

void HouseBar::Compare()
{
	if (vodkaPrice < MIN_VODKA_PRICE_HOUSE)
		this->vodkaPrice = MIN_VODKA_PRICE_HOUSE;
	if (whiskeyPrice < MIN_WHISKEY_PRICE_HOUSE)
		this->whiskeyPrice = MIN_WHISKEY_PRICE_HOUSE;
}

HouseBar* HouseBar::clone()
{
	return new HouseBar(*this);
}

void HouseBar::Print() const
{
	if (current >= 1)
	{
		cout << "Users in " << name << ":" << endl;
		PrintUsers(); cout << endl;
	}

	cout << name << " " << capacity << " " << vodkaPrice << " " << whiskeyPrice << " " << DJs;
}