#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <cstring>
#include "person.h"


using namespace std;

class BST {
	Person data;
	BST *left, *right;

public:
    int counter = 1;
	BST();
	BST(string, string, string, string, string);
	BST* Insert(BST*, string, string, string, string, string);
	void Inorder(BST*);
    BST* minValueNode(BST*);
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
	if (root == NULL) {
		return new BST(fullName, phone, mail, addrs, org);
	}

	if (strcmp(fullName.c_str(), root->data.fullName.c_str()) > 0) {
		root->right = Insert(root->right, fullName, phone, mail, addrs, org);
	}
	else if (strcmp(fullName.c_str(), root->data.fullName.c_str()) < 0){
		root->left = Insert(root->left, fullName, phone, mail, addrs, org);
	}

	return root;
}

void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
    cout << " - ";
	cout << root->data.fullName << "\n";
    counter++;
	Inorder(root->right);
    counter = 1;
}

BST* BST::minValueNode(BST* node)
{
    BST* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

BST* BST::deleteNode(BST* root, string fullName)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (strcmp(fullName.c_str(), root->data.fullName.c_str()) < 0)
        root->left = deleteNode(root->left, fullName);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (strcmp(fullName.c_str(), root->data.fullName.c_str()) > 0)
        root->right = deleteNode(root->right, fullName);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;

        // node with only one child or no child
        else if (root->left == NULL) {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        BST* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data.fullName);
    }
    return root;
}

Person BST::search(BST* root, string fullName)
{
    if (root == NULL || root->data.fullName == fullName)
       return root->data;
    
    if (strcmp(fullName.c_str(), root->data.fullName.c_str()) > 0)
       return search(root->right, fullName);
 
    if (strcmp(fullName.c_str(), root->data.fullName.c_str()) < 0)
        return search(root->left, fullName);
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
