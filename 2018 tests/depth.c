#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b,c,d,h;
	scanf("%d %d %d %d %d",&a,&b,&h,&c,&d);
	printf("%d\n",(a*b*h)/((a-c)*b+c*(b-d)));
	return 0;
}