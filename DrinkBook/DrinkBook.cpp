#include "Collection.h"

int main()
{
	Collection c;
	c.addPopFolkBar("33", 10, 40, "Galena");
	c.addPopFolkBar("33", 40, 40, "Galena");
	c.addHouseBar("Yalta", 50, 50, 2);

	User u("Ivan", 18, 180, 2, 2, House);
	User u1("Milen", 18, 180, 2, 2, House);

	c.addToClub(u, "Yalta");
	c.addToClub(u, "33");
	c.addToClub(u1, "33");

	c.removeFromClub("Poli", "33");
	c.removeFromClub("Ivan", "33");

	c.Print();
}