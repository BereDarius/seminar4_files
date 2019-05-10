#pragma once
#include <string>

class TrenchCoat
{

private:

	int size;
	std::string colour; 
	int price;
	int quantity;
	std::string photograph;

public:
	
	/*
	Trench coat constructor
	*/
	TrenchCoat(int size = 0, std::string colour = "", int price = 0, int quantity = 0, std::string photograph = "");
	/*
	Trench coat copy constructor
	*/
	TrenchCoat(const TrenchCoat& tc) : size(tc.size), colour(tc.colour), price(tc.price), quantity(tc.quantity), photograph(tc.photograph) {};
	/*
	Trench coat destructor
	*/
	~TrenchCoat();

	/*
	The assignment operator funciton for the trench coat class
	It assigns new values from another trench coat object to the current trench coat object's members
	*/
	TrenchCoat& operator=(TrenchCoat tcoat);

	/*
	GETTERS
	*/
	int getSize() const { return this->size; }
	std::string getColour() const { return this->colour; }
	int getPrice() const { return this->price; }
	int getQuantity() const { return this->quantity; }
	std::string getPhotograph() const { return this->photograph; }

	/*
	SETTERS
	*/
	void setSize(int size) { this->size = size; }
	void setColour(std::string colour) { this->colour = colour; }
	void setPrice(int price) { this->price = price; }
	void setQuantity(int quantity) { this->quantity = quantity; }
	void setPhotograph(std::string photograph) { this->photograph = photograph; }

	/*
	Function that returns the string representation of the trench coat
	INPUT: - 
	OUTPUT: The string representation of the trench coat
	*/
	std::string trenchCoatString();

};