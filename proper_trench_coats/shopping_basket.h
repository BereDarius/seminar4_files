#pragma once
#include "database.h"

class ShoppingBasket {

private:

	std::vector<TrenchCoat> basket;

public:

	/*
	Shopping basket constructor
	*/
	ShoppingBasket(std::vector<TrenchCoat> bask = std::vector<TrenchCoat>{}) : basket(bask) {}
	/*
	Shopping basket copy constructor
	*/
	ShoppingBasket(const ShoppingBasket& sb) : basket(sb.basket) {}
	/*
	Shopping basket destructor
	*/
	~ShoppingBasket() {}

	/*
	Function that returns the shopping basket
	INPUT: - 
	OUTPUT: The shopping basket as a dynamic vector
	*/
	std::vector<TrenchCoat> getShoppingBasket();
	/*
	Function that returns an array of trench coats having a given size
	INPUT: The database and the size
	OUTPUT: The array of trench coats having the given size
	*/
	std::vector<TrenchCoat> getTrenchCoatsBySize(const Database& database, int size);
	/*
	Functions that adds a trench coat to the shopping basket
	INPUT: The trench coat to be added
	OUTPUT: The trench coat is added to the basket
	*/
	void addTrenchCoatToBasket(const TrenchCoat& trench_coat);

	/*
	Function that returns the string representation of the shopping basket
	INPUT: - 
	OUTPUT: The string representation of the shopping basket
	*/
	std::string basketString();

};