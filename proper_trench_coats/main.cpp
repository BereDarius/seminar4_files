#include "ui.h"

int main()
{
	TrenchCoat trench_coat1{ 12, "red", 10, 7, "www.tcoats.com/tc1.jpg" };
	TrenchCoat trench_coat2{ 20, "blue", 15, 5, "www.tcoats.com/tc2.jpg" };
	TrenchCoat trench_coat3{ 22, "green", 10, 10, "www.tcoats.com/tc3.jpg" };
	TrenchCoat trench_coat4{ 15, "white", 13, 21, "www.tcoats.com/tc4.jpg" };
	TrenchCoat trench_coat5{ 10, "black", 9, 35, "www.tcoats.com/tc5.jpg" };
	TrenchCoat trench_coat6{ 9, "brown", 14, 12, "www.tcoats.com/tc6.jpg" };
	TrenchCoat trench_coat7{ 25, "red", 12, 10, "www.tcoats.com/tc7.jpg" };
	TrenchCoat trench_coat8{ 13, "yellow", 20, 25, "www.tcoats.com/tc8.jpg" };
	TrenchCoat trench_coat9{ 17, "blue", 25, 30, "www.tcoats.com/tc9.jpg" };
	TrenchCoat trench_coat10{ 21, "orange", 5, 1, "www.tcoats.com/tc10.jpg" };

	DynamicVector<TrenchCoat> vector{};
	Database database{vector};

	ShoppingBasket shoppingbasket{};

	database.addTrenchCoat(trench_coat1);
	database.addTrenchCoat(trench_coat2);
	database.addTrenchCoat(trench_coat3);
	database.addTrenchCoat(trench_coat4);
	database.addTrenchCoat(trench_coat5);
	database.addTrenchCoat(trench_coat6);
	database.addTrenchCoat(trench_coat7);
	database.addTrenchCoat(trench_coat8);
	database.addTrenchCoat(trench_coat9);
	database.addTrenchCoat(trench_coat10);

	Controller controller{ database, shoppingbasket };

	UI ui{ controller };

	ui.start();

	return 0;
}