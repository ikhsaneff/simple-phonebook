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
    void modifyContacts(string);
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
    
    root = contacts.deleteNode(root, fullName);
    cout << "Contact successfully deleted!\n";
}

void Phonebook::showContact()
{
    while (true)
    {
        int prompt;
        string fullName;

        cout << "CONTACT LIST\n\n";

        contacts.Inorder(root);

        cout << "\n1: Open contact | 2: Delete contact | 0: Back" << endl;
        cout << "Enter: ";
        cin >> prompt;

        if (prompt == 1)
        {
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, fullName);

            searchByName(fullName);
        }
        else if (prompt == 2)
        {
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, fullName);

            deleteContact(fullName);
            getche();
        }
        else
        {
            system("cls");
            return;
        }

        system("cls");
    }


}

void Phonebook::showRecycleBin()
{
    int prompt, index;
    char again;

    while (true)
    {
        cout << "RECYCLE BIN \n\n";

        recycleBin.printList();

        cout << "\n1: Restore contact | 2: Delete from bin | 0: Back\n";
        cout << "Enter: ";
        cin >> prompt;
        system("cls");
        
        if (prompt == 1)
        {
            while (true)
            {
                cout << "RESTORE CONTACT\n\n";

                recycleBin.printList();
                
                cout << "\nEnter index: ";
                cin >> index;
                restoreRecycleBin(index);
                cout << "Restore again (y/n)? ";
                cin >> again;
                system("cls");

                if (again == 'n')
                {
                    break;
                }
            }
        } 
        else if (prompt == 2)
        {
            while (true)
            {
                cout << "DELETE TRASH\n\n";

                recycleBin.printList();
                
                cout << "\nEnter index: ";
                cin >> index;
                recycleBin.deleteNode(index-1);
                cout << "Contact successfully deleted!\n";
                cout << "Delete again (y/n)? ";
                cin >> again;
                system("cls");

                if (again == 'n')
                {
                    break;
                }
            }
        }
        else
        {
            return;
        }
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

    insertContact(fName, phone, email, address, organization);
    
    recycleBin.deleteNode(index-1);
    cout << "Contact successfully restored!\n";
}

void Phonebook::searchByName(string name)
{
    system("cls");
    
    int prompt;

    cout << "CONTACT DETAILS\n\n";

    contacts.search(root, name).printPerson();

    cout << "1: Delete Contact | 2: Modify Contact | 0: Back \n";
    cout << "Enter: ";
    cin >> prompt;

    if (prompt == 1)
    {
        deleteContact(name);
        getche();
    }
    else if (prompt == 2)
    {
        modifyContacts(name);
    }
    else
    {

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

void Phonebook::modifyContacts(string name)
{
    string newName = name;

    while (true)
    {
        system("cls");

        cout << "MODIFY CONTACT1\n\n";

        contacts.search(root, newName).printPerson();

        int prompt1;
        
        cout << "What do you want to change?\n";
        cout << " 1) Name\n";
        cout << " 2) Phone\n";
        cout << " 3) Email\n";
        cout << " 4) Address\n";
        cout << " 5) Organization\n";
        cout << " 0) Back\n";
        cout << "Enter: ";
        cin >> prompt1;
        
        switch (prompt1)
        {
            case 1:
                system("cls");

                cout << "MODIFY CONTACT2\n\n";

                contacts.search(root, newName).printPerson();

                string newInput;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newInput);

                contacts.search(root, newName).fullName = newInput;
                newName = newInput;
                cout << "Modify again (y/n)?";
        }
    }
}

#endif // PHONEBOOK_H
