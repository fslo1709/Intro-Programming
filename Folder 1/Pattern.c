#include <stdio.h>

int main(void) {
	int i,n,j=0;
	scanf("%d",&n);
	for (i=0;i<=n;i++)
		for (j=1;j<=i;j++)
			printf("%d",j);
	return 0;
}
