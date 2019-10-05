#include "node.h"
#include <stdio.h>
#include <stdlib.h>
int path[1001];
void search(struct node *root, int index) {
	path[index] = root->data;
	if (root->left == NULL && root->right == NULL) {
		for (int i = 0; i <= index; i++)
			printf("%d ", path[i]);
		puts("");
		return;
	}
	if (root->left != NULL)
		search(root->left, index + 1);
	if (root->right != NULL)
		search(root->right, index + 1);
}
void print_all_paths(struct node *root) {
	search(root, 0);
}