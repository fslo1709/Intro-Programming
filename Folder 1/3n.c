#include <stdio.h>

int main(void) {
	int n,a=0;
	while (scanf("%d",&n)==1)
	{
		int i,c[3]={};
		for (i=0;i<n;i++)
			scanf("%d",&a),c[a%3]++;
		printf("%d %d %d",c[0],c[1],c[2]);
	}
	return 0;
}
