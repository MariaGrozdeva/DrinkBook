#include "PopFolkBar.h"

void PopFolkBar::CopyFrom(const PopFolkBar& other)
{
	performerName = new char[strlen(other.performerName) + 1];
	strcpy(performerName, other.performerName);
}
void PopFolkBar::Free()
{
	delete performerName;
}

PopFolkBar::PopFolkBar(const char* name, double vodkaPrice, double whiskeyPrice, const char* performerName) :
	Bar(name, vodkaPrice, whiskeyPrice)
{
	capacity = MAX_CAPACITY_FOLK;
	Compare();

	this->performerName = new char[strlen(performerName) + 1];
	strcpy(this->performerName, performerName);
}

PopFolkBar::PopFolkBar() : Bar()
{
	const char DEFAULT_NAME[DEFAULT_SIZE] = "Unnamed performer";

	performerName = new char[DEFAULT_SIZE];
	strcpy(performerName, DEFAULT_NAME);
}
PopFolkBar::PopFolkBar(const PopFolkBar& other) : Bar(other)
{
	CopyFrom(other);
}
PopFolkBar& PopFolkBar::operator=(const PopFolkBar& other)
{
	if (this != &other)
	{
		Bar::operator=(other);
		Free();
		CopyFrom(other);
	}
	return *this;
}
PopFolkBar::~PopFolkBar()
{
	Free();
}

bool PopFolkBar::addUser(User user)
{
	if (user.getPrefMusic() == 2)
	{
		cout << "Bad idea, rock fans can't stand listening to pop folk" << endl;
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
		user.setBudget(user.getBudget() - 20);

	cout << "Successfully added " << user.getName() << endl;

	users[current] = user;
	current++;

	return true;
}

void PopFolkBar::setVodkaPrice(int vodkaPrice)
{
	if (vodkaPrice < MIN_VODKA_PRICE_FOLK)
		this->vodkaPrice = MIN_VODKA_PRICE_FOLK;
	this->vodkaPrice = vodkaPrice;
}
void PopFolkBar::setWhiskeyPrice(int whiskeyPrice)
{
	if (whiskeyPrice < MIN_WHISKEY_PRICE_FOLK)
		this->whiskeyPrice = MIN_WHISKEY_PRICE_FOLK;
	this->whiskeyPrice = whiskeyPrice;
}

void PopFolkBar::Compare()
{
	if (vodkaPrice < MIN_VODKA_PRICE_FOLK)
	{
		cout << "The vodka is too cheap. The price was changed to the minimal(20)" << endl;
		this->vodkaPrice = MIN_VODKA_PRICE_FOLK;
	}
	if (whiskeyPrice < MIN_WHISKEY_PRICE_FOLK)
	{
		cout << "The whiskey is too cheap. The price was changed to the minimal(35)" << endl;
		this->whiskeyPrice = MIN_WHISKEY_PRICE_FOLK;
	}
}

Bar* PopFolkBar::clone()
{
	return new PopFolkBar(*this);
}

void PopFolkBar::Print() const
{
	if (current >= 1)
	{
		cout << "Users in " << name << ":" << endl;
		PrintUsers(); 
		cout << endl;
	}
	cout << name << " " << vodkaPrice << " " << whiskeyPrice << " " << performerName;
}