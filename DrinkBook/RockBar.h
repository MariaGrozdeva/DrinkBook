#include "Bar.h"

const int MAX_CAPACITY_ROCK = 30;
const int MIN_VODKA_PRICE_ROCK = 40;
const int MIN_WHISKEY_PRICE_ROCK = 30;

class RockBar : public Bar
{
private:
	void Compare() override;

public:
	RockBar(const char* name, double vodkaPrice, double whiskeyPrice);
	RockBar();

	bool addUser(User user) override;

	void setVodkaPrice(int vodkaPrice) override;
	void setWhiskeyPrice(int whiskeyPrice) override;

	RockBar* clone() override;

	void Print() const override;
};