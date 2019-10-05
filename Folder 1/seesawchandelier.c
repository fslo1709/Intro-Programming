#include <stdio.h>
#define MAX 16384
int seesaw[MAX];
int N;

void chand(int min, int max) {
	if (max - min < 2) {
		return;
	}
	int balance = -1;
	for (int i = min; i <= max; i++) {
		unsigned long long int s1 = 0, s2 = 0;
		for (int j = min; j < i; j++) {
			s1 += seesaw[j]*(i-j);
		}
		for (int j = i+1; j <= max; j++) {
			s2 += seesaw[j]*(j-i);
		}
		if (s1 == s2) {
			balance = i;
			break;
		}
	}
	if (balance > -1) {
		chand(min, balance-1);
		printf("%d\n", balance);
		chand(balance+1, max);
	}
	else
		return;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&seesaw[i]);
	chand(0,N-1);
	return 0;
}