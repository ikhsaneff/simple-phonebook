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
		data = Person("","",0);
		next = NULL;
	}

	Node(string fName, string lName, int phone)
	{
		this->data = Person(fName, lName, phone);
		this->next = NULL;
	}
};

class LinkedList
{
	Node* head;
	Node* sorted;

public:
	LinkedList() { head = NULL; }
	void push(string, string, int);
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

    // Check if the list is empty
	if (head == NULL)
    {
		cout << "List is empty." << endl;
		return;
	}

	// Get list length
	while (temp1 != NULL)
    {
		temp1 = temp1->next;
		listLen++;
	}

    temp1 = head;
	listLen -= 1;

	// Check if the index is out of range
	if (listLen < index)
    {
		cout << "Index out of range" << endl;
		return;
	}

	// Delete head.
	if (index == 0)
    {
		// Update head
		head = head->next;
		delete temp1;
		return;
	}

	// Traverse the list to find the node to be deleted.
	while (index > 0)
    {
		temp2 = temp1;
		temp1 = temp1->next;
		index--;
	}

	// Change the next pointer
	// of the previous node.
	temp2->next = temp1->next;

	// Delete the node
	delete temp1;
}

// Function to insert a new node.
void LinkedList::push(string fName, string lName, int phone)
{
	// Create new Node.
	Node* newNode = new Node(fName, lName, phone);

	// Assign to head
	if (head == NULL) {
		head = newNode;
		return;
	}

	// Traverse till end of list
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	// Insert data to the last.
	temp->next = newNode;
}

// Method to print list's elements
void LinkedList::printList()
{
	Node* temp = head;
	int counter = 1;

	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << counter << ". ";
		temp->data.printPerson();
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
