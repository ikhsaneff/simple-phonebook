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
	BST();
	BST(string, string, int);
	BST* Insert(BST*, string, string, int);
	void Inorder(BST*);
    BST* minValueNode(BST*);
    BST* deleteNode(BST*, string);
    Person search(BST*, string);
};

BST ::BST() : data("","",0), left(NULL), right(NULL)
{
}

BST ::BST(string firstName, string lastName, int phone)
{
	data = Person(firstName, lastName, phone);
	left = right = NULL;
}

BST* BST ::Insert(BST* root, string firstName, string lastName, int phone)
{
	if (root == NULL) {
		return new BST(firstName, lastName, phone);
	}

	if (strcmp(firstName.c_str(), root->data.firstName.c_str()) > 0) {
		root->right = Insert(root->right, firstName, lastName, phone);
	}
	else if (strcmp(firstName.c_str(), root->data.firstName.c_str()) < 0){
		root->left = Insert(root->left, firstName, lastName, phone);
	}

	return root;
}

void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	root->data.printPerson();
	Inorder(root->right);
}

BST* BST::minValueNode(BST* node)
{
    BST* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

BST* BST::deleteNode(BST* root, string firstName)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (strcmp(firstName.c_str(), root->data.firstName.c_str()) < 0)
        root->left = deleteNode(root->left, firstName);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (strcmp(firstName.c_str(), root->data.firstName.c_str()) > 0)
        root->right = deleteNode(root->right, firstName);

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
        root->right = deleteNode(root->right, temp->data.firstName);
    }
    return root;
}

Person BST::search(BST* root, string firstName)
{
    if (root == NULL || root->data.firstName == firstName)
       return root->data;
    
    if (strcmp(firstName.c_str(), root->data.firstName.c_str()) > 0)
       return search(root->right, firstName);
 
    if (strcmp(firstName.c_str(), root->data.firstName.c_str()) < 0)
        return search(root->left, firstName);
}

#endif
