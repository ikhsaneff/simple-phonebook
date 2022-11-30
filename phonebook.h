#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "linkedlist.h"
#include "binarysearchtree.h"

class Phonebook
{
public:
    LinkedList recycleBin;
    Person tempPerson;
    BST contacts, *root = NULL;
    void insertContact(string, string, string, string, string);
    void deleteContact(string);
    void showContact();
    void showRecycleBin();
    void restoreRecycleBin(int);
    void searchByName(string);
    void searchByPhone(string);
    void modifyContacts();
    void addNewContactMenu();
};

void Phonebook::insertContact(string fullName, string phone, string mail = "", string addrs = "", string org = "")
{
    if (root == NULL)
    {
        root = contacts.Insert(root, fullName, phone, mail, addrs, org);
    }
    else
        contacts.Insert(root, fullName, phone, mail, addrs, org);
}

void Phonebook::deleteContact(string fullName)
{
    string fName, lName, phone, email, address, organization;

    tempPerson = contacts.search(root, fullName);
    fName = tempPerson.fullName;
    phone = tempPerson.phoneNum;
    email = tempPerson.email;
    address = tempPerson.address;
    organization = tempPerson.organization;

    recycleBin.push(fName, phone, email, address, organization);
    
    contacts.deleteNode(root, fullName);
    cout << "Contact successfully deleted!\n";
}

void Phonebook::showContact()
{
    string fullName;
    int prompt;
    char again;

    cout << "CONTACT LIST \n\n";

    contacts.Inorder(root);

    cout << "\n1: Open contact | 2: Modify contact | 3: Delete contact | 0: Back" << endl;
	cout << "Enter: ";
	cin >> prompt;

	while (prompt != 0)
	{	
		if (prompt == 1)
		{
			cout << "Enter name: ";
			cin.ignore();
			getline(cin, fullName);

			system("cls");
			searchByName(fullName);
			getche();
            return;
		}
        else if (prompt == 3)
        {
			cout << "Enter name: ";
			cin.ignore();
			getline(cin, fullName);

			deleteContact(fullName);
			getche();
            cout << "Delete again (y/n)? ";
            cin >> again;
            system("cls");

            if (again == 'n')
            {
                return;
            }
            else
            {
                addNewContactMenu();
            }  
        }
		
	}

    system("cls");
}

void Phonebook::showRecycleBin()
{
    int prompt, index;
    char again;

    cout << "RECYCLE BIN \n\n";

    recycleBin.printList();

    cout << "1: Restore contact | 2: Delete from bin | 0: Back\n";
    cout << "Enter: ";
    cin >> prompt;
    system("cls");

    if (prompt == 1)
    {
        recycleBin.printList();
        cout << "Enter index: ";
        cin >> index;
        restoreRecycleBin(index);
        cout << "Restore again (y/n)? ";
        cin >> again;
        system("cls");

        if (again == 'n')
        {
            return;
        }
        else 
        {
            showRecycleBin();
        }
    } 
    else if (prompt == 2)
    {
        recycleBin.printList();
        cout << "Enter index: ";
        cin >> index;
        recycleBin.deleteNode(index);
        cout << "Contact successfully deleted!";
        cout << "Delete again (y/n)? ";
        cin >> again;
        system("cls");

        if (again == 'n')
        {
            return;
        }
        else 
        {
            showRecycleBin();
        }
    }
    else
    {
        return;
    }
}

void Phonebook::restoreRecycleBin(int index)
{
    string fName, phone, email, address, organization;

    tempPerson = recycleBin.getNth(index-1);
    fName = tempPerson.fullName;
    phone = tempPerson.phoneNum;
    email = tempPerson.email;
    address = tempPerson.address;
    organization = tempPerson.organization;

    contacts.Insert(root, fName, phone, email, address, organization);
    
    recycleBin.deleteNode(index-1);
    cout << "Contact successfully restored!\n";
}

void Phonebook::searchByName(string name)
{
    int prompt;
    string fullName = name;

    cout << "CONTACT DETAILS\n\n";

    system("cls");
    contacts.search(root, fullName).printPerson();
    cout << "1: Delete Contact | 2: Modify Contact | 0: Back \n";
    cout << "Enter: ";
    cin >> prompt;

    if (prompt == 1)
    {
        deleteContact(fullName);
        cout << "Contact deleted...";
        getche();
        system("cls");

        return;
    }
    else if (prompt == 2)
    {
        int prompt1;

        cout << "What do you want to change?\n";
        cout << " 1) Name\n";
        cout << " 2) Phone\n";
        cout << " 3) Email\n";
        cout << " 4) Address\n";
        cout << " 5) Organization\n";
        cout << "Enter: ";
        cin >> prompt1;

        if (prompt1 == 1)
        {
            string newInput;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newInput);

            contacts.search(root, name).fullName = newInput;
            name = newInput;
            cout << "Modify again?";
        }
    }
    else
    {
        return;    
    }
}

void Phonebook::addNewContactMenu()
{
    string fName, phone, email, address, organization;
    char prompt;

    cout << "NEW CONTACT MENU\n\n";
	cout << " Enter Full Name    : ";
	cin.ignore();
	getline(cin, fName);
    cout << " Enter Phone Number : ";
    getline(cin, phone);
    cout << " Enter Email        : ";
    getline(cin, email);
    cout << " Enter Address      : ";
    getline(cin, address);
    cout << " Enter Organization : ";
    getline(cin, organization);

    insertContact(fName, phone, email, address, organization);

    cout << "\nContact successfully added!\n";
    cout << "Add again (y/n)? ";
    cin >> prompt;
    system("cls");

    if (prompt == 'n')
    {
        return;
    }
    else
    {
        addNewContactMenu();
    }
}

void Phonebook::searchByPhone(string phone)
{
    contacts.searchByPhone(root, phone).printPerson();
}

void Phonebook::modifyContacts()
{

}

#endif // PHONEBOOK_H
