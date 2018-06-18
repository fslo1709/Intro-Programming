#include <stdio.h>
#include <stdlib.h>
int ways(int, int);
int main (void){
	int r,c;
	scanf("%d %d",&r,&c);
	printf("%d",ways(r,c));
	return 0;
}
int ways(int r, int c)
{
	int res=0;
	if (r==1 || c==1)
		return 1;
	else
		return ways(r-1,c)+ways(r,c-1);
}
