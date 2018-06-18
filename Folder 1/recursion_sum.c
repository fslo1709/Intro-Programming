#include <stdio.h>
int mult(int n);
int main(void) {
	int n,r;
	scanf("%d",&n);
	r=mult(n);
	printf("%d",r);
	return 0;
}
int mult(int n)
{
	if (n==1)
		return (1);
	else
		return mult(n-1)+(n*n);
}
