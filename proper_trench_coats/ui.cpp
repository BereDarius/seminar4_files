#include "ui.h"

using namespace std;

UI::UI(Controller controller)
{
	this->controller = controller;
}

int UI::getCommand()
{
	int command;
	cout << "Please enter a command: ";
	cin >> command;
	return command;
}

void UI::printMenuAdminUser()
{
	cout << "1. Admin;" << endl;
	cout << "2. User;" << endl;
	cout << "0. Exit." << endl;
}


void UI::printMenuAdministrator()
{
	cout << "1. Get all trench coats from the database;" << endl;
	cout << "2. Add a trench coat to the database;" << endl;
	cout << "3. Delete a trench coat from the database;" << endl;
	cout << "4. Update a trench coat from the database;" << endl;
	cout << "0. Back;" << endl;
}

void UI::uiAdminAddTrenchCoat()
{
	int size;
	string colour;
	int price;
	int quantity;
	string photograph;

	cout << "Please enter the trench coat's size: " << endl;
	cin >> size;

	cout << "\nPlease enter the trench coat's colour: " << endl;
	cin >> colour;

	cout << "\nPlease enter the trench coat's price: " << endl;
	cin >> price;

	cout << "\nPlease enter the quantity: " << endl;
	cin >> quantity;

	cout << "\nPlease enter the trench coat's photograph link: " << endl;
	cin >> photograph;

	TrenchCoat new_trench_coat{ size, colour, price, quantity, photograph };

	this->controller.ctrlAdminAddTrenchCoat(new_trench_coat);
}

void UI::uiAdminGetAll()
{
	string result = "";
	for (int i = 0; i < this->controller.ctrlAdminGetAll().getAllTrenchCoats().getLength(); i++) {
		result += this->controller.ctrlAdminGetAll().getAllTrenchCoats()[i].trenchCoatString() + "\n";
	}
	cout << result << endl;
}

void UI::uiAdminDeleteTrenchCoat()
{
	int index;
	cout << "Please enter the index at which you want the trench coat to be deleted: ";
	cin >> index;
	cout << "\n";

	this->controller.ctrlAdminDeleteTrenchCoat(index);
}

void UI::uiAdminUpdateTrenchCoat()
{
	int index, size, price, quantity;
	string colour, photograph;
	cout << "Please enter the index at which you want the trench coat to be updated: ";
	cin >> index;
	cout << "\nPlease enter the new size: ";
	cin >> size;
	cout << "\nPlease enter the new colour: ";
	cin >> colour;
	cout << "\nPlease enter the new price: ";
	cin >> price;
	cout << "\nPlease enter the new quantity: ";
	cin >> quantity;
	cout << "\nPlease enter the new photograph: ";
	cin >> photograph;

	this->controller.ctrlAdminUpdateTrenchCoat(index, size, colour, price, quantity, photograph);
}

void UI::printMenuUser()
{
	cout << "1. Get trench coats from the database having a particular size;" << endl;
	cout << "2. Add this trench coat to shopping basket;" << endl;
	cout << "3. See shopping basket;" << endl;
	cout << "0. Back;" << endl;
}

void UI::uiUserGetTrenchCoatsBySize()
{
	string result = "";
	int size;
	cout << "Please enter the size: ";
	cin >> size;
	if (size != 0) {
		for (int i = 0; i < this->controller.ctrlUserGetTrenchCoatsBySize(size).getLength(); i++) {
			result += this->controller.ctrlUserGetTrenchCoatsBySize(size)[i].trenchCoatString() + "\n";
		}
	}
	else {
		result = this->controller.ctrlAdminGetAll().databaseString() + "\n";
	}
	cout << result << endl;
}

void UI::uiUserAddTrenchCoatToBasket()
{
	int choice = 0;
	int index = 0;
	while (true) {
		cout << "1. Next;\n2. Previous;\n3. Add to basket;\n0. Done;\nYour choice: " << endl;
		cin >> choice;
		switch (choice) {
			case 1:
			{
				index++;
				cout << this->controller.ctrlAdminGetAll().getAllTrenchCoats()[index].trenchCoatString() << endl;
			}
			case 2:
			{
				index--;
				cout << this->controller.ctrlAdminGetAll().getAllTrenchCoats()[index].trenchCoatString() << endl;
			}
			case 3:
				this->controller.ctrlUserGetShoppingBasket().addTrenchCoatToBasket(this->controller.ctrlAdminGetAll().getAllTrenchCoats()[index]);
			case 0:
				break;
			default:
				cout << "Option not valid. Please try again." << endl;
		}
	}
}

void UI::uiUserGetBasket()
{
	cout << this->controller.ctrlUserGetShoppingBasket().basketString();
}

void UI::start() 
{
	this->printMenuAdminUser();
	int command1 = this->getCommand();
	while (true)
	{
		switch (command1)
		{
			case 0:
				break;
			case 1:
			{
				int admin_command;
				while (true)
				{
					this->printMenuAdministrator();
					admin_command = this->getCommand();
					switch (admin_command)
					{
					case 0:
					{
						break;
					}
					case 1:
					{
						this->uiAdminGetAll();
						break;
					}
					case 2:
					{
						this->uiAdminAddTrenchCoat();
						break;
					}
					case 3:
					{
						this->uiAdminDeleteTrenchCoat();
						break;
					}
					case 4:
						this->uiAdminUpdateTrenchCoat();
						break;
					default:
						cout << "Please enter a valid command: " << endl;
					}
				}
			}
			
			case 2:
			{
				int index = 0;
				int usercommand;
				while (true)
				{
					this->printMenuUser();
					usercommand = this->getCommand();
					switch (usercommand)
					{
					case 0:
						break;
					case 1:
						this->uiUserGetTrenchCoatsBySize();
						break;
					case 2:
						this->uiUserAddTrenchCoatToBasket();
						break;
					case 3:
						this->uiUserGetBasket();
						break;
					default:
						cout << "Please enter a valid command: " << endl;
					}
				}
			}
			default:
				cout << "Please enter a valid command: " << endl;
		}
	}
}