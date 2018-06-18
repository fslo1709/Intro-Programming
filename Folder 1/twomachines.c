#include <stdio.h>
int main(int argc, char const *argv[])
{
	int readyA=0,readyB=0,job,mA,mB;
	while (scanf("%d %d %d",&job,&mA,&mB)!=EOF) {
		if (job>readyA)
			readyA=job;
		readyA+=mA;
		if (readyA>readyB)
			readyB=readyA;	
		readyB+=mB;
		printf("%d\n", readyB);
	}
	return 0;
}