#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <cstring>
#include "person.h"


using namespace std;

class BST 
{
	Person data;
	BST *left, *right;

public:
	BST();
	BST(string, string, string, string, string);
	BST* Insert(BST*, string, string, string, string, string);
	void Inorder(BST*);
    BST* deleteNode(BST*, string);
    Person search(BST*, string);
    Person searchByPhone(BST*, string);
};

BST ::BST() : data("","","","",""), left(NULL), right(NULL)
{
}

BST ::BST(string fullName, string phone, string mail = "", string addrs = "", string org = "")
{
	data = Person(fullName, phone, mail, addrs, org);
	left = right = NULL;
}

BST* BST ::Insert(BST* root, string fullName, string phone, string mail = "", string addrs = "", string org = "")
{
	if (root == NULL) 
    {
		return new BST(fullName, phone, mail, addrs, org);
	}

	if (strcmp(fullName.c_str(), root->data.fullName.c_str()) > 0) 
    {
		root->right = Insert(root->right, fullName, phone, mail, addrs, org);
	}
	else if (strcmp(fullName.c_str(), root->data.fullName.c_str()) < 0)
    {
		root->left = Insert(root->left, fullName, phone, mail, addrs, org);
	}

	return root;
}

void BST ::Inorder(BST* root)
{
	if (!root) 
    {
		return;
	}

	Inorder(root->left);
    cout << " - ";
	cout << root->data.fullName << "\n";
	Inorder(root->right);
}

BST* BST::deleteNode(BST* root, string fullName)
{

    if (root == NULL)
        return root;

    if (strcmp(fullName.c_str(), root->data.fullName.c_str()) < 0) 
    {
        root->left = deleteNode(root->left, fullName);
        return root;
    }
    else if (strcmp(fullName.c_str(), root->data.fullName.c_str()) > 0) 
    {
        root->right = deleteNode(root->right, fullName);
        return root;
    }
 
    if (root->left == NULL) 
    {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) 
    {
        BST* temp = root->left;
        delete root;
        return temp;
    }
 
    else {
 
        BST* successorParent = root;
 
        BST* successor = root->right;
        while (successor->left != NULL) 
        {
            successorParent = successor;
            successor = successor->left;
        }
 
        if (successorParent != root)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;
 
        root->data = successor->data;
 
        delete successor;
        return root;
    }
}

Person BST::search(BST* root, string fullName)
{
    if (root == NULL || root->data.fullName == fullName)
       return root->data;
    
    if (strcmp(fullName.c_str(), root->data.fullName.c_str()) > 0)
       return search(root->right, fullName);
 
    if (strcmp(fullName.c_str(), root->data.fullName.c_str()) < 0)
        return search(root->left, fullName);
    
    cout << "Not found.\n";
}

Person BST::searchByPhone(BST* root, string phoneNum)
{
    if (root == NULL || root->data.phoneNum == phoneNum)
       return root->data;
    
    if (strcmp(phoneNum.c_str(), root->data.phoneNum.c_str()) > 0)
       return searchByPhone(root->right, phoneNum);
 
    if (strcmp(phoneNum.c_str(), root->data.phoneNum.c_str()) < 0)
        return searchByPhone(root->left, phoneNum);
}

#endif
