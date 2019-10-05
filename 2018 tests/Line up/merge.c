#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[]) {
	int counta = 0, countb = 0, pointa = 0, pointb = 0, sizeA = 0, sizeB = 0;
	int** pointar;
	int* pospointar;
	while (a[sizeA] != NULL) 
		sizeA++;
	while (b[sizeB] != NULL) 
		sizeB++;
	sizeA++;
	sizeB++;
	// printf("%d %d\n", sizeA, sizeB);
	if (A[0] < B[0]) {
		counta++;
		pointar = &a[0];
		pospointar = &pointa;
	}
	else {
		countb++;
		pointar = &b[0];
		pospointar = &pointb;
	}
	while (counta < sizeA && countb < sizeB) {
		if (A[counta] < B[countb]) {
			*(pointar + *pospointar) = &A[counta];
			*pospointar = *pospointar + 1;
			if (pointar == &b[0]) {
				pointar = &a[0];
				pospointar = &pointa;
			}
			counta++;
		}
		else {
			*(pointar + *pospointar) = &B[countb];
			*pospointar = *pospointar + 1;
			if (pointar == &a[0]) {
				pointar = &b[0];
				pospointar = &pointb;
			}
			countb++;
		}
		// printf("\n");
	}
	if (counta == sizeA && countb != sizeB) {
		a[sizeA-1] = &B[countb++];
		for (int i = countb; i < sizeB; i++)
			b[pointb++] = &B[i];
		b[pointb] = NULL;
	}
	else if (counta != sizeA && countb == sizeB){
		b[sizeB-1] = &A[counta++];
		for (int i = counta; i < sizeA; i++)
			a[pointa++] = &A[i];
		a[pointa] = NULL;
	}
}