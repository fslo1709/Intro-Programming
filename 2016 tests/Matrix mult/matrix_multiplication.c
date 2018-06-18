#include <stdio.h>
int matA[1000][1000],matB[1000][1000];
void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result) {
	for (int i=0;i<N;i++) 
		matA[ptrA[1][i]][ptrA[2][i]] = ptrA[0][i];
	for (int i=0;i<M;i++)
		matB[ptrB[1][i]][ptrB[2][i]] = ptrB[0][i];
	for (int i=0;i<S;i++)
		for (int j=0;j<S;j++) {
			result[i*S+j] = 0;
			for (int k=0;k<S;k++)
				result[i*S+j] += matA[i][k]*matB[k][j];
		}
}