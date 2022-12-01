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
    void searchMenu();
    void searchByName(string);
    void searchByPhone(string);
    void modifyContacts(string);
    void addNewContactMenu();
};

void Phonebook::insertContact(string fullName, string phone, string mail = "", string addrs = "", string org = "")
{
    if (root == NULL)
        root = contacts.Insert(root, fullName, phone, mail, addrs, org);
    else
        contacts.Insert(root, fullName, phone, mail, addrs, org);
}

void Phonebook::deleteContact(string fullName)
{
    string fName, phone, email, address, organization;

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
            cout << "Enter full name: ";
            cin.ignore();
            getline(cin, fullName);

            transform(fullName.begin(), fullName.end(), fullName.begin(), ::toupper);

            searchByName(fullName);
        }
        else if (prompt == 2)
        {
            cout << "Enter full name: ";
            cin.ignore();
            getline(cin, fullName);

            transform(fullName.begin(), fullName.end(), fullName.begin(), ::toupper);

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

    transform(fName.begin(), fName.end(), fName.begin(), ::toupper);

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
    system("cls");
    
    int prompt;
    string name;

    cout << "CONTACT DETAILS\n\n";

    contacts.searchByPhone(root, phone).printPerson();
    
    tempPerson = contacts.searchByPhone(root, phone);
    name = tempPerson.fullName;

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

void Phonebook::modifyContacts(string name)
{
    system("cls");

    string fName, phone, email, address, organization;
    string tempName = name;
    string newInput;

    int prompt;
    char again;

    tempPerson = contacts.search(root, tempName);
    fName = tempPerson.fullName;
    phone = tempPerson.phoneNum;
    email = tempPerson.email;
    address = tempPerson.address;
    organization = tempPerson.organization;

    while (true)
    {
        cout << "MODIFY CONTACT\n\n";

        contacts.search(root, tempName).printPerson();

        cout << "What do you want to change?\n";
        cout << " 1) Name\n";
        cout << " 2) Phone\n";
        cout << " 3) Email\n";
        cout << " 4) Address\n";
        cout << " 5) Organization\n";
        cout << " 0) Back\n";
        cout << "Enter: ";
        cin >> prompt;

        system("cls");

        cout << "MODIFY CONTACT\n\n";

        contacts.search(root, tempName).printPerson();
            
        switch (prompt)
        {
            case 1: 
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newInput);

                transform(newInput.begin(), newInput.end(), newInput.begin(), ::toupper);

                fName = newInput;

                root = contacts.deleteNode(root, tempName);

                tempName = newInput;

                insertContact(fName, phone, email, address, organization);
                cout << "Modify again (y/n)?";
                cin >> again;

                if (again == 'n')
                {
                    return;
                }
                break;

            case 2: 
                cout << "Enter new phone number: ";
                cin.ignore();
                getline(cin, newInput);

                phone = newInput;

                root = contacts.deleteNode(root, tempName);

                insertContact(fName, phone, email, address, organization);
                cout << "Modify again (y/n)?";
                cin >> again;

                if (again == 'n')
                {
                    return;
                }
                break;

            case 3:
                cout << "Enter new email: ";
                cin.ignore();
                getline(cin, newInput);

                email = newInput;

                root = contacts.deleteNode(root, tempName);

                insertContact(fName, phone, email, address, organization);
                cout << "Modify again (y/n)?";
                cin >> again;

                if (again == 'n')
                {
                    return;
                }
                break;
            
            case 4:
                cout << "Enter new address: ";
                cin.ignore();
                getline(cin, newInput);

                address = newInput;

                root = contacts.deleteNode(root, tempName);

                insertContact(fName, phone, email, address, organization);
                cout << "Modify again (y/n)?";
                cin >> again;

                if (again == 'n')
                {
                    return;
                }
                break;
            
            case 5:
                cout << "Enter new organization: ";
                cin.ignore();
                getline(cin, newInput);

                organization = newInput;

                root = contacts.deleteNode(root, tempName);

                insertContact(fName, phone, email, address, organization);
                cout << "Modify again (y/n)?";
                cin >> again;

                if (again == 'n')
                {
                    return;
                }
                break;
            case 0:
                return;
        }
    }
}

void Phonebook::searchMenu()
{
    while (true)
    {
        int prompt;
        string fullName, phoneNum;

        cout << "SEARCH MENU\n\n";

        cout << "How do you want to search:\n";
        cout << " 1) By Full Name\n";
        cout << " 2) By Phone Number\n";
        cout << " 0) Back\n";
        cout << "Enter: ";
        cin >> prompt;
        system("cls");

        if (prompt == 1)
        {
            cout << "SEARCH MENU\n\n";

            cout << "Enter full name: ";
            cin.ignore();
            getline(cin, fullName);

            transform(fullName.begin(), fullName.end(), fullName.begin(), ::toupper);

            if (contacts.search(root, fullName).fullName == "Not found")
            {
                cout << "Contact not found.";
                getche();
            }
            else
            {
                searchByName(fullName);
            }

        }
        else if (prompt == 2)
        {
            cout << "SEARCH MENU\n\n";
            
            cout << "Enter phone number: ";
            cin.ignore();
            getline(cin, phoneNum);

            if (contacts.searchByPhone(root, phoneNum).fullName == "Not found")
            {
                cout << "Contact not found.";
                getche();
            }
            else
            {
                searchByPhone(phoneNum);
            }

        }
        else
        {
            system("cls");
            return;
        }
        
        system("cls");
    }
    
}
#endif // PHONEBOOK_H
