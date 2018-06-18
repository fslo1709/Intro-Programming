#include "constructTable.h"
#include <stdio.h>
int** first[100];
int* second[100][100];
int ***constructTable(int A[], int B[]) {
	int pos=0;
	int x=0,y=0;
	while (A[x]>0) {
		first[pos]=&second[pos][0];
		for (int i=0;i<A[x];i++) {
			second[pos][i]=&B[y];
			while (B[y]!=0)
				y++;
			y++;
		}
		pos++,x++;
	}
	return &first[0];
}