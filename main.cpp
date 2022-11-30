#include "phonebook.h"
#include <conio.h>

int main()
{
	// Bug List:
	// - Delete contact searchByName()
	// - Delete contact showContact() cannot go back to menu
	// - Restore contact error

	Phonebook newPhonebook;
	int prompt = 4, prompt1;
	string fullName;

	while (prompt != 0)
	{
		cout << "Welcome to Phonebook!" << endl;
		cout << "What do you want to do?" << endl;
		cout << " 1) Show contacts" << endl;
		cout << " 2) Add new contacts" << endl;
		cout << " 3) Show recycle bin" << endl;
		cout << " 0) Exit" << endl;
		cout << "Enter: ";
		cin >> prompt;
		system("cls");

		if (prompt == 1)
		{
			newPhonebook.showContact();
		}
		else if (prompt == 2)
		{
			newPhonebook.addNewContactMenu();
		}
		else if (prompt ==3)
		{
			newPhonebook.showRecycleBin();
		}
	}

}
