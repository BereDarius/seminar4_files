#include "database.h"

void Database::addTrenchCoat(TrenchCoat trenchcoat)
{
	this->database.addTElem(trenchcoat);
}

void Database::deleteTrenchCoat(int index)
{
	this->database.deleteTElem(index);
}

void Database::updateTrenchCoat(int index, int size, std::string colour, int price, int quantity, std::string photograph)
{
	this->getAllTrenchCoats()[index].setSize(size);
	this->getAllTrenchCoats()[index].setColour(colour);
	this->getAllTrenchCoats()[index].setPrice(price);
	this->getAllTrenchCoats()[index].setQuantity(quantity);
	this->getAllTrenchCoats()[index].setPhotograph(photograph);
}

DynamicVector<TrenchCoat> Database::getAllTrenchCoats() const
{
	return this->database;
}

std::string Database::databaseString() {
	std::string result = "";
	for (int i = 0; i < this->database.getLength(); i++) {
		result += this->getAllTrenchCoats()[i].trenchCoatString() + "\n";
	}
	return result;
}