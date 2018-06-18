#include <stdio.h>
int main(void) {
	int n,m;
	int a[200000];
	int b[200000];
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=0;i<n;i++)
		b[abs(a[i])%m]++;
	for (int i=0;i<m;i++)
		printf("%d\n",b[i]);
	return 0;
}
