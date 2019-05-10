#include "shopping_basket.h"

DynamicVector<TrenchCoat> ShoppingBasket::getShoppingBasket()
{
	return this->basket;
}

DynamicVector<TrenchCoat> ShoppingBasket::getTrenchCoatsBySize(const Database& database, int size)
{
	DynamicVector<TrenchCoat> result;
	for (int i = 0; i < database.getAllTrenchCoats().getLength(); i++) {
		if (database.getAllTrenchCoats()[i].getSize() == size) {
			result.addTElem(database.getAllTrenchCoats()[i]);
		}
	}
	if (result.getLength() == 0) {
		result = database.getAllTrenchCoats();
	}
	return result;
}

void ShoppingBasket::addTrenchCoatToBasket(const TrenchCoat & trench_coat)
{
	this->basket.addTElem(trench_coat);
	this->total += trench_coat.getPrice();
}

int ShoppingBasket::getTotal()
{
	return this->total;
}

void ShoppingBasket::setTotal(int total)
{
	this->total = total;
}

std::string ShoppingBasket::basketString()
{
	std::string result = "";
	for (int i = 0; i < this->basket.getLength(); i++) {
		result += this->basket[i].trenchCoatString() + "\n";
	}

	result += "\nTOTAL: " + std::to_string(this->total);

	return result;
}
