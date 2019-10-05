#include <stdio.h>
#include <stdlib.h>
int tail[100000];
void split(int A[], int *a[], int *head[], int k) {
	int N = 0;
	while (a[N] != NULL) {
		a[N] = NULL;
		N++;
	}
	N++;
	for (int i = 0; i < N; i++) {
		int temp = A[i] % k;
		if (head[temp] == NULL) {
			head[temp] = &A[i];
			tail[temp] = i;
		}
		else {
			a[tail[temp]] = &A[i];
			tail[temp] = i;
			// a[i] = NULL;
		}
	}
}