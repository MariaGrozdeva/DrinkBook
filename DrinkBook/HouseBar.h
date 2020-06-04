#include "Bar.h"

const int MIN_VODKA_PRICE_HOUSE = 30;
const int MIN_WHISKEY_PRICE_HOUSE = 40;

class HouseBar : public Bar
{
private:
	int DJs;

	void Compare() override;

public:
	HouseBar(const char* name, double vodkaPrice, double whiskeyPrice, int DJs);
	HouseBar();

	bool addUser(User user) override;

	void setVodkaPrice(int vodkaPrice) override;
	void setWhiskeyPrice(int whiskeyPrice) override;

	HouseBar* clone() override;

	void Print() const override;
};