#include <stdio.h>
#include "node.h"
struct node *getNode(struct node *head, unsigned int i) {
	struct node *new=head;
	int j=0;
	while (new->nex!=NULL) {
		new=new->next;
		j++;
	}
	if (i>j)
		return NULL;
	new=head;
	for (int k=0;k<j-i;k++)
		new=new->next;
	return new;
}