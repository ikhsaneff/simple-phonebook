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
    void insertContact(string, string, int);
    void deleteContact(string);
    void showContact();
    void showRecycleBin();
    void restoreRecycleBin(int);
    void modifyContacts();
};

void Phonebook::insertContact(string firstName, string lastName, int phoneNum)
{
    if (root == NULL)
    {
        root = contacts.Insert(root, firstName, lastName, phoneNum);
    }
    else
        contacts.Insert(root, firstName, lastName, phoneNum);
}

void Phonebook::deleteContact(string firstName)
{
    string fName, lName;
    int phone;

    tempPerson = contacts.search(root, firstName);
    fName = tempPerson.firstName;
    lName = tempPerson.lastName;
    phone = tempPerson.phoneNum;

    recycleBin.push(fName, lName, phone);
    
    contacts.deleteNode(root, firstName);
}

void Phonebook::showContact()
{
    contacts.Inorder(root);
}

void Phonebook::showRecycleBin()
{
    recycleBin.printList();
}

void Phonebook::restoreRecycleBin(int index)
{
    string fName, lName;
    int phone;

    tempPerson = recycleBin.getNth(index-1);
    fName = tempPerson.firstName;
    lName = tempPerson.lastName;
    phone = tempPerson.phoneNum;

    contacts.Insert(root, fName, lName, phone);
    
    recycleBin.deleteNode(index-1);
}

#endif // PHONEBOOK_H
