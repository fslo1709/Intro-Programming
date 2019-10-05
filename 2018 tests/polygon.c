#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a1,a2,b1,b2,c1,c2,d1,d2;
	scanf("%d %d %d %d %d %d %d %d",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
	printf("%d\n%d", 2*(c1-a1)+2*(c2-a2), (c1-a1)*(c2-a2)-(d1-a1)*(c2-d2)-(c1-b1)*(b2-a2));
	return 0;
}