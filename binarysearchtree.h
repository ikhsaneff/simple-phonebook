#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <cstring>
#include "person.h"
#include "linkedlist.h"


using namespace std;

class BST {
	Person data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(string, string, int);

	// Insert function.
	BST* Insert(BST*, string, string, int);

	// Inorder traversal.
	void Inorder(BST*);

    BST* minValueNode(BST*);

    BST* deleteNode(BST*, string);
};

// Default Constructor definition.
BST ::BST() : data("","",0), left(NULL), right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(string firstName, string lastName, int phone)
{
	data = Person(firstName, lastName, phone);
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, string firstName, string lastName, int phone)
{
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(firstName, lastName, phone);
	}

	// Insert data.
	if (strcmp(firstName.c_str(), root->data.firstName.c_str()) > 0) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, firstName, lastName, phone);
	}
	else if (strcmp(firstName.c_str(), root->data.firstName.c_str()) < 0){
		// Insert left node data, if the 'value'
		// to be inserted is smaller than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, firstName, lastName, phone);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
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

#endif
