#include "Collection.h"

int main()
{
	Collection c;

	User u1("Ivan", 18, 180, 2, 2, Rock);
	User u2("Milen", 17, 300, 2, 2, House);
	User u3("Pilen", 21, 240, 1, 1, PopFolk);
	User u4("Gugo", 22, 300, 3, 3, PopFolk);

	c.addPopFolkBar("33", 10, 40, "Galena");
	c.addHouseBar("Yalta", 50, 50, 2);

	c.addToClub(u1, "Yalta");
	c.addToClub(u1, "33");
	c.addToClub(u2, "Yalta");
	c.addToClub(u3, "33");
	c.addToClub(u4, "33");

	c.removeFromClub("Poli", "33");
	c.removeFromClub("Ivan", "33");
	c.removeFromClub("Pilen", "33");

	c.Print();
}