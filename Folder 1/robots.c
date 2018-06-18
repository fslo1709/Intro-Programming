#include <stdio.h>
int main() {
	int N, M, X1, X2, Y1, Y2, F1, F2, N1, E1, N2, E2;
	while (scanf("%d %d", &N, &M) == 2) {
		scanf("%d %d %d %d %d %d %d %d %d %d", &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);
		int t = 0, f = 0;
		while (F1 > 0 || F2 > 0) {
			if (F1 > 0) {
				F1--;
				if (t%(N1 + E1) < N1)
					Y1 = (Y1+1)%M;
				else
					X1 = (X1+1)%N;
			}
			if (F2 > 0) {
				F2--;
				if (t%(N2 + E2) < E2)
					X2 = (X2+1)%N;
				else
					Y2 = (Y2+1)%M;
			}
			t++;
			if (X1 == X2 && Y1 == Y2) {
				f = 1;
				break;
			}
		}
		if (f)
			printf("robots explode at time %d\n", time);
		else
			printf("robots will not explode\n");
	}
	return 0;
}
