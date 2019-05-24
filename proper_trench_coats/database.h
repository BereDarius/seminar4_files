#pragma once
#include <vector>
#include "trench_coat.h"

class Database {

private:
	
	std::vector<TrenchCoat> trenchCoats;

public:

	/*
	Database constructor
	*/
	Database(std::vector<TrenchCoat> dbase = std::vector<TrenchCoat>{}) : trenchCoats(dbase) {};
	/*
	Database copy constructor
	*/
	Database(const Database& db) : trenchCoats(db.trenchCoats) {};
	/*
	Database destructor
	*/
	~Database() {};

	/*
	Function that adds a trench coat to the trenchCoats
	INPUT: The trench coat
	OUTPUT: The trench coat is added to the trenchCoats
	*/
	void addTrenchCoat(TrenchCoat trenchcoat);
	/*
	Funciton that deletes a trench coat from the trenchCoats
	INPUT: The index at which the trench coat should be deleted
	OUTPUT: The trench coat is deleted from the trenchCoats
	*/
	void deleteTrenchCoat(int index);
	/*
	Function that updates a trench coat from the trenchCoats
	INPUT: The index at which the trench coat to be updated, the new size, colour, price, quantity and photograph
	OUTPUT: The trench coat's members' data is changed to the new data given
	*/
	void updateTrenchCoat(int index, int size, std::string colour, int price, int quantity, std::string photograph);
	/*
	Function that returns the trenchCoats
	INPUT : - 
	OUTPUT: The trenchCoats as a dynamic vector of trench coats
	*/
	std::vector<TrenchCoat> getAllTrenchCoats() const;

	/*
	Funciton that returns the string representation of the whole trenchCoats
	INPUT: - 
	OUTPUT: The string representation of the trenchCoats
	*/
	std::string databaseString();

};