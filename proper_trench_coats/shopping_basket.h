#pragma once
#include "database.h"

class ShoppingBasket {

private:

	DynamicVector<TrenchCoat> basket;
	int total;

public:

	/*
	Shopping basket constructor
	*/
	ShoppingBasket(DynamicVector<TrenchCoat> bask = DynamicVector<TrenchCoat>{}) : basket(bask) {};
	/*
	Shopping basket copy constructor
	*/
	ShoppingBasket(const ShoppingBasket& sb) : basket(sb.basket) {};
	/*
	Shopping basket destructor
	*/
	~ShoppingBasket() {};

	/*
	Function that returns the shopping basket
	INPUT: - 
	OUTPUT: The shopping basket as a dynamic vector
	*/
	DynamicVector<TrenchCoat> getShoppingBasket();
	/*
	Function that returns an array of trench coats having a given size
	INPUT: The database and the size
	OUTPUT: The array of trench coats having the given size
	*/
	DynamicVector<TrenchCoat> getTrenchCoatsBySize(const Database& database, int size);
	/*
	Functions that adds a trench coat to the shopping basket
	INPUT: The trench coat to be added
	OUTPUT: The trench coat is added to the basket
	*/
	void addTrenchCoatToBasket(const TrenchCoat& trench_coat);
	/*
	Funciton that returns the total sum of the shopping basket
	INPUT: - 
	OUTPUT: The total sum
	*/
	int getTotal();
	/*
	Function that changes the value of the total sum of the shopping basket
	INPUT: The new value for the total
	OUTPUT: The current value of the total is changed to the new value
	*/
	void setTotal(int total);

	/*
	Function that returns the string representation of the shopping basket
	INPUT: - 
	OUTPUT: The string representation of the shopping basket
	*/
	std::string basketString();

};