#include <stdio.h>
#define MAX 16384
int seesaw[MAX];
int N;
void chand(int min, int max) {
	if (max-min<2)
		return;
	int bal=-1;
	long long int torque;
	for (int i=min;i<=max;i++) {
		long long int side1=0,side2=0;
		for (int j=min;j<i;j++)
			side1+=seesaw[j]*(i-j);
		for (int j=i+1;j<=max;j++)
			side2+=seesaw[j]*(j-i);
		if (side1==side2) {
			bal = i;
			break;
		}
	}
	if (bal>-1) {
		chand(min,bal-1);
		printf("%d\n",bal);
		chand(bal+1,max);
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