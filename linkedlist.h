#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <assert.h>
#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include "person.h"

using namespace std;

class Node
{
public:
	Person data;
	Node* next;

	Node()
	{
		data = Person("","","","","");
		next = NULL;
	}

	Node(string fullName, string phone, string mail = "", string addrs = "", string org = "")
	{
		this->data = Person(fullName, phone, mail, addrs, org);
		this->next = NULL;
	}
};

class LinkedList
{
	Node* head;
	Node* sorted;

public:
	LinkedList() { head = NULL; }
	void push(string, string, string, string, string);
	void printList();
	void deleteNode(int);
	void getIndex(string);
	Person getNth(int);
};

// Method to delete Node at given index
void LinkedList::deleteNode(int index)
{
	Node *temp1 = head, *temp2 = NULL;
	int listLen = 0;

	if (head == NULL)
    {
		cout << "Recycle bin is empty.\n" << endl;
		return;
	}

	while (temp1 != NULL)
    {
		temp1 = temp1->next;
		listLen++;
	}

    temp1 = head;
	listLen -= 1;

	if (listLen < index)
    {
		cout << "Index out of range" << endl;
		return;
	}

	if (index == 0)
    {
		head = head->next;
		delete temp1;
		return;
	}

	while (index > 0)
    {
		temp2 = temp1;
		temp1 = temp1->next;
		index--;
	}

	temp2->next = temp1->next;

	delete temp1;
}

void LinkedList::push(string fullName, string phone, string mail = "", string addrs = "", string org = "")
{
	Node* newNode = new Node(fullName, phone, mail, addrs, org);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void LinkedList::printList()
{
	Node* temp = head;
	int counter = 1;

	if (head == NULL) {
		cout << "Recycle bin is empty." << endl;
		return;
	}

	while (temp != NULL) {
		cout << counter << ". " << temp->data.fullName << endl;
		temp = temp->next;
		counter++;
	}
}

Person LinkedList::getNth(int index)
{
    Node* temp = head;
    int counter = 0;

    while (temp != NULL)
    {
        if (counter == index)
            return temp->data;
        counter++;
        temp = temp->next;
    }
}

#endif
