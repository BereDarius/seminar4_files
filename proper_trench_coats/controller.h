#pragma once
#include "shopping_basket.h"

class Controller {

private:

	Database database;
	ShoppingBasket shopping_basket;

public:

	/*
	Controller constructor
	*/
	Controller(Database dbase, ShoppingBasket sbasket) : database(dbase), shopping_basket(sbasket) {}
	/*
	Controller copy constructor
	*/
	Controller(const Controller& ctrl) : database(ctrl.database), shopping_basket(ctrl.shopping_basket) {}
	/*
	Controller destructor
	*/
	~Controller() {}

	/*
	Controller function that returns an array of all trench coats from the database
	*/
	Database ctrlAdminGetDatabase();
	/*
	Controller function that adds a trench coat to the database
	*/
	void ctrlAdminAddTrenchCoat(const TrenchCoat& trench_coat);
	/*
	Controller function that deletes a trench coat from the database
	*/
	void ctrlAdminDeleteTrenchCoat(int index);
	/*
	Controller function that updates a trench coat
	*/
	void ctrlAdminUpdateTrenchCoat(int index, int size, std::string colour, int price, int quantity, std::string photograph);
	
	/*
	Controller function that returns the shopping basket
	*/
	ShoppingBasket ctrlUserGetShoppingBasket();
	/*
	Controller function that returns an array of trench coats having a certain size
	*/
	std::vector<TrenchCoat> ctrlUserGetTrenchCoatsBySize(int size);
	/*
	Controller function that adds a trench coat to the shopping basket
	*/
	void ctrlUserAddTrenchCoatToBasket(const TrenchCoat& trench_coat);
	
};