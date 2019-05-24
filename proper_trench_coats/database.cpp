#include "database.h"

void Database::addTrenchCoat(TrenchCoat trenchcoat)
{
	this->trenchCoats.push_back(trenchcoat);
}

void Database::deleteTrenchCoat(int index)
{
	this->trenchCoats.erase(this->trenchCoats.begin()+index-1);
}
void Database::updateTrenchCoat(int index, int size, std::string colour, int price, int quantity, std::string photograph)
{
	this->getAllTrenchCoats()[index].setSize(size);
	this->getAllTrenchCoats()[index].setColour(colour);
	this->getAllTrenchCoats()[index].setPrice(price);
	this->getAllTrenchCoats()[index].setQuantity(quantity);
	this->getAllTrenchCoats()[index].setPhotograph(photograph);
}

std::vector<TrenchCoat> Database::getAllTrenchCoats() const
{
	return this->trenchCoats;
}

std::string Database::databaseString() {
	std::string result = "";
	for (int i = 0; i < this->trenchCoats.size(); i++) {
		result += this->getAllTrenchCoats()[i].trenchCoatString() + "\n";
	}
	return result;
}