#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
Node*newNode(int val) {
	Node* new = (Node *)malloc(sizeof(Node));
	new->large = val;
	new->small = -1;
	new->left = NULL;
	new->mid = NULL;
	new->right = NULL;
	return new;
}
Node*insert(Node *root, int val) {
	if (root == NULL)
		return newNode(val);
	if (val < root->large) {
		if (root->small == -1) {
			root->small = val;
		}
		else {
			if (val < root->small)
				root->left = insert(root->left, val);
			else if (val > root->small)
				root->mid = insert(root->mid, val);
		}
	}
	else if (val > root->large) {
		if (root->small == -1) {
			root->small = root->large;
			root->large = val;
		}
		else {
			root->right = insert(root->right, val);
		}
	}
	return root;
}
Node*ConstructTree(int sequence[], int N) {
	Node* head = newNode(sequence[0]);
	for (int i = 1; i < N; i++) {
		insert(head, sequence[i]);
	}
	return head;
}