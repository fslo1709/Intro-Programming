#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
Node *treeAND(Node *root1, Node *root2) {
	if (root1 == NULL || root2 == NULL)
		return NULL;
	Node *head = (Node *)malloc(sizeof(Node));
	head->val = root1->val * root2->val;
	head->left = treeAND(root1->left, root2->left);
	head->right = treeAND(root1->right, root2->right);
	return head;
}
Node *treeOR(Node *root1, Node *root2) {
	if (root1 == NULL && root2 == NULL)
		return NULL;
	if (root1 == NULL) {
		Node *head = (Node *)malloc(sizeof(Node));
		head->val = root2->val;
		head->left = treeOR(NULL, root2->left);
		head->right = treeOR(NULL, root2->right);
		return head;
	}
	else if (root2 == NULL) {
		Node *head = (Node *)malloc(sizeof(Node));
		head->val = root1->val;
		head->left = treeOR(root1->left, NULL);
		head->right = treeOR(root1->right, NULL);
		return head;	
	}
	else {
		Node *head = (Node *)malloc(sizeof(Node));
		head->val = root1->val + root2->val;
		head->left = treeOR(root1->left, root2->left);
		head->right = treeOR(root1->right, root2->right);
		return head;
	}
}