#include "trench_coat.h"


TrenchCoat::TrenchCoat(int size, std::string colour, int price, int quantity, std::string photograph): 
	size(size), colour(colour), price(price), quantity(quantity), photograph(photograph) {}

TrenchCoat::~TrenchCoat() {}

TrenchCoat & TrenchCoat::operator=(TrenchCoat tcoat)
{
	if (this == &tcoat) {
		return *this;
	}

	this->size = tcoat.getSize();
	this->colour = tcoat.getColour();
	this->price = tcoat.getPrice();
	this->quantity = tcoat.getQuantity();
	this->photograph = tcoat.getPhotograph();

	return tcoat;
}

std::string TrenchCoat::trenchCoatString()
{
	std::string size = std::to_string(this->getSize());
	std::string colour = this->getColour();
	std::string price = std::to_string(this->getPrice());
	std::string quantity = std::to_string(this->getQuantity());
	std::string photograph = this->getPhotograph();
	std::string result = "Trench coat:\n - size: " + size + ";\n - colour: " + colour + ";\n - price: " + price + ";\n - quantity: " + quantity + ";\n - photograph: " + photograph + ";\n";
	return result;
}
