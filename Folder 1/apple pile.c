#include <stdio.h>
int main(void) {
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n%d",((b*(b+1))/2-(a*(a-1)/2)), 2*(b-a-1)+b+a);
	return 0;
}