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

#endif
