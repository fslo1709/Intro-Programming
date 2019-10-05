#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
};
typedef struct treenode TreeNode;

void print_bs_tree(TreeNode *root)
{
  if (root == NULL)
    return;
  print_bs_tree(root->left);
  printf("data = %d\n", root->data);
  print_bs_tree(root->right);
}

TreeNode *insert_bs_tree(TreeNode *root, int data)
{
  struct treenode *current;
  if (root == NULL) {
    current = (TreeNode*)malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->data = data;
    current->left = NULL;
    current->right = NULL;
    return(current);
  }
  if (data < root->data) 
    root->left = insert_bs_tree(root->left,data);
  else 
    root->right =insert_bs_tree(root->right,data);
  return(root);
}
int main(void) {
  int k, q;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int n;
    scanf("%d %s %s", &n);
    if (n == 0) {
      
    }
    else {

    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("")
  }
    // int i;
    // int insert_keys[5];

    // for (i = 0; i < 5; i++)
    //   scanf("%d", &(insert_keys[i]));

    // TreeNode *root = NULL;
    // for (i = 0; i < 5; i++)
    //   root = insert_bs_tree(root, insert_keys[i]);
    // print_bs_tree(root);
    return 0;
}