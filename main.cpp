#include "phonebook.h"

int main()
{
	// delete by full name
	// search by full name
	// delete by phone
	// search by phone
	// add more details
	// modify details

	Phonebook newPhonebook;
	
	newPhonebook.insertContact("User0F", "User0L", 50);
	newPhonebook.insertContact("User1F", "User1L", 60);
	newPhonebook.insertContact("User2F", "User2L", 70);

    newPhonebook.deleteContact("User2F");

	cout << "Contact List: \n";
    newPhonebook.showContact();

	cout << "Recycle Bin List: \n";
    newPhonebook.showRecycleBin();

    newPhonebook.restoreRecycleBin(1);

	cout << "Restored Contacts: \n";
	newPhonebook.showContact();
	return 0;
}
