#include "Bar.h"

const int DEFAULT_SIZE = 18;
const int MAX_CAPACITY_FOLK = 70;
const int MIN_VODKA_PRICE_FOLK = 20;
const int MIN_WHISKEY_PRICE_FOLK = 35;

class PopFolkBar : public Bar
{
private:
	char* performerName;

	void CopyFrom(const PopFolkBar& other);
	void Free();

	void Compare() override;

public:
	PopFolkBar(const char* name, double vodkaPrice, double whiskeyPrice, const char* performerName);

	PopFolkBar();
	PopFolkBar(const PopFolkBar& other);
	PopFolkBar& operator=(const PopFolkBar& other);
	~PopFolkBar();

	bool addUser(User user) override;

	void setVodkaPrice(int vodkaPrice) override;
	void setWhiskeyPrice(int whiskeyPrice) override;

	Bar* clone() override;

	void Print() const override;
};