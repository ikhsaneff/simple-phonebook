#include "phonebook.h"
#include <conio.h>

int main()
{
	// To Do List:
	// - Modify feature

	Phonebook newPhonebook;
	int prompt = 4, prompt1 = 4;
	string fullName;

	while (prompt != 0)
	{
		cout << "Welcome to Phonebook!" << endl;
		cout << "What do you want to do?" << endl;
		cout << " 1) Add new contact" << endl;
		cout << " 2) Show contacts" << endl;
		cout << " 3) Search contact" << endl;
		cout << " 4) Show recycle bin" << endl;
		cout << " 0) Exit" << endl;
		cout << "Enter: ";
		cin >> prompt;
		system("cls");
		
		if (prompt == 1)
		{
			newPhonebook.addNewContactMenu();
		}
		else if (prompt == 2)
		{
			newPhonebook.showContact();
		}
		else if (prompt == 3)
		{
			newPhonebook.searchMenu();
		}
		else if (prompt == 4)
		{
			newPhonebook.showRecycleBin();
		}
	}

}
