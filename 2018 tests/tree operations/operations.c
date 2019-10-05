#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

Node *FlipTree(Node *root) {
	if (root == NULL)
		return NULL;
	Node* new = (Node *)malloc(sizeof(Node));
	new->n = root->n;
	new->right = FlipTree(root->left);
	new->left = FlipTree(root->right);
	return new;
}
int isIdentical(Node *tree1, Node *tree2) {
	if (tree1==NULL && tree2==NULL)
		return 1;
	if (tree1==NULL || tree2==NULL)
		return 0;
	if (tree1->n != tree2->n)
		return 0;
	else {
		if (isIdentical(tree1->left, tree2->left)==1 &&
			isIdentical(tree1->right, tree2->right)==1)
			return 1;
	}
	return 0;
}
int count;
int leafcount(Node *root, int depth) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		count += depth;
		return 1;
	}
	int leftl = leafcount(root->left, depth+1);
	int rightl = leafcount(root->right, depth+1);
	return (leftl + rightl);
}
void depthAvg(Node *root) {
	count = 0;
	printf("%d/%d\n", count, leafcount(root, 0));
}