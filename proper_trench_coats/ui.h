#pragma once
#include "controller.h"
#include <iostream>

class UI {

private:

	Controller controller;

public:
	UI(Controller controller) :controller(controller) {}
	UI(const UI& ui) : controller(ui.controller) {}
	~UI() {}

private:
	/*
	Function that reads a command from the user
	*/
	int getCommand();

	/*ADMIN FUNCTIONS FOR PRINTING MENU*/

	void printMenuAdminUser();

	void printMenuAdministrator();
	void uiAdminAddTrenchCoat();
	void uiAdminGetAll();
	void uiAdminDeleteTrenchCoat();
	void uiAdminUpdateTrenchCoat();

	/*USER FUNCTIONS FOR PRINTING MENU*/

	void printMenuUser();
	void uiUserGetTrenchCoatsBySize();
	void uiUserAddTrenchCoatToBasket();
	void uiUserGetBasket();

public:

	void start();
};