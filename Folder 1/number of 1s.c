#include <stdio.h>
int num(long int);
int main(void) {
	long int n,m;
	while (1)
	{
		if (scanf("%ld",&n)==EOF)
			break;
		m=num(n);
		printf("%d\n",m);
	}
	return 0;
}
int num(long int m)
{
	if (m==1)
		return 1;
	else
	{
		if (m==0)
			return 0;
		else
			return num(m/2)+m%2;
	}
}
