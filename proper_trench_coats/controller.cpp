#include "controller.h"

Database Controller::ctrlAdminGetDatabase()
{
	return this->database;
}

void Controller::ctrlAdminAddTrenchCoat(const TrenchCoat & trench_coat)
{
	this->database.addTrenchCoat(trench_coat);
}

void Controller::ctrlAdminDeleteTrenchCoat(int index)
{
	this->database.deleteTrenchCoat(index);
}

void Controller::ctrlAdminUpdateTrenchCoat(int index, int size, std::string colour, int price, int quantity, std::string photograph)
{
	this->database.updateTrenchCoat(index, size, colour, price, quantity, photograph);
}

ShoppingBasket Controller::ctrlUserGetShoppingBasket()
{
	return this->shopping_basket;
}

std::vector<TrenchCoat> Controller::ctrlUserGetTrenchCoatsBySize(int size)
{
	return this->shopping_basket.getTrenchCoatsBySize(this->database, size);
}

void Controller::ctrlUserAddTrenchCoatToBasket(const TrenchCoat & trench_coat)
{
	this->shopping_basket.addTrenchCoatToBasket(trench_coat);
}
