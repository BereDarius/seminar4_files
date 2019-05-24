#include "shopping_basket.h"

std::vector<TrenchCoat> ShoppingBasket::getShoppingBasket()
{
	return this->basket;
}

std::vector<TrenchCoat> ShoppingBasket::getTrenchCoatsBySize(const Database& database, int size)
{
	std::vector<TrenchCoat> result;
	for (int i = 0; i < database.getAllTrenchCoats().size(); i++) {
		if (database.getAllTrenchCoats()[i].getSize() == size) {
			result.push_back(database.getAllTrenchCoats()[i]);
		}
	}
	if (result.size() == 0) {
		result = database.getAllTrenchCoats();
	}
	return result;
}

void ShoppingBasket::addTrenchCoatToBasket(const TrenchCoat & trench_coat)
{
	this->basket.push_back(trench_coat);
}

std::string ShoppingBasket::basketString()
{
	int total = 0;

	std::string result = "";
	for (int i = 0; i < this->basket.size(); i++) {
		result += this->basket[i].trenchCoatString() + "\n";
		total += this->basket[i].getPrice();
	}

	result += "\nTOTAL: " + std::to_string(total);

	return result;
}
