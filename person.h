#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string firstName, lastName;
    // string email, address, organization
    int phoneNum;
    Person(string, string, int);
    Person();
    void printPerson();
};

Person::Person()
{

}

Person::Person(string fName, string lName, int phone)
{
    firstName = fName;
    lastName = lName;
    phoneNum = phone;
}

void Person::printPerson()
{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Phone: " << phoneNum << "\n" << endl;
}

#endif
