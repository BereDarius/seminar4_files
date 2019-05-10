#pragma once
#include "dynamic_vector.h"
#include "trench_coat.h"

class Database {

private:
	
	DynamicVector<TrenchCoat> database;

public:

	/*
	Database constructor
	*/
	Database(DynamicVector<TrenchCoat> dbase = DynamicVector<TrenchCoat>{}) : database(dbase) {};
	/*
	Database copy constructor
	*/
	Database(const Database& db) : database(db.database) {};
	/*
	Database destructor
	*/
	~Database() {};

	/*
	Function that adds a trench coat to the database
	INPUT: The trench coat
	OUTPUT: The trench coat is added to the database
	*/
	void addTrenchCoat(TrenchCoat trenchcoat);
	/*
	Funciton that deletes a trench coat from the database
	INPUT: The index at which the trench coat should be deleted
	OUTPUT: The trench coat is deleted from the database
	*/
	void deleteTrenchCoat(int index);
	/*
	Function that updates a trench coat from the database
	INPUT: The index at which the trench coat to be updated, the new size, colour, price, quantity and photograph
	OUTPUT: The trench coat's members' data is changed to the new data given
	*/
	void updateTrenchCoat(int index, int size, std::string colour, int price, int quantity, std::string photograph);
	/*
	Function that returns the database
	INPUT : - 
	OUTPUT: The database as a dynamic vector of trench coats
	*/
	DynamicVector<TrenchCoat> getAllTrenchCoats() const;

	/*
	Funciton that returns the string representation of the whole database
	INPUT: - 
	OUTPUT: The string representation of the database
	*/
	std::string databaseString();

};