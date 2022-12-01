#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string fullName, phoneNum, email, address, organization;
    Person(string, string, string, string, string);
    Person();
    void printPerson();
    void modify();
};

Person::Person()
{

}

Person::Person(string name, string phone, string mail, string addrs, string org)
{
    fullName = name;
    phoneNum = phone;
    email = mail;
    address = addrs;
    organization = org;
}

void Person::printPerson()
{
    cout << "  > Full Name    : " << fullName << endl;
    cout << "  > Phone Number : " << phoneNum << endl;
    cout << "  > Email        : " << email << endl;
    cout << "  > Address      : " << address << endl;
    cout << "  > Organization : " << organization << "\n" << endl;
}

void Person::modify()
{
    int prompt;

    cout << "What do you want to change?\n";
    cout << " 1) Name\n";
    cout << " 2) Phone\n";
    cout << " 3) Email\n";
    cout << " 4) Address\n";
    cout << " 5) Organization\n";
    cout << " 0) Back\n";
    cout << "Enter: ";
    cin >> prompt;
        
    switch (prompt)
    {
        case 1:
            system("cls");

            cout << "MODIFY CONTACT2\n\n";

            string newInput;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newInput);

            fullName = newInput;
            cout << "Modify again (y/n)?";
    }
}

#endif
