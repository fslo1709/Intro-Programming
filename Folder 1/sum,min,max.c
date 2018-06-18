#include <stdio.h>
int n,m;
int main(void) {
	int x,y;
	int s[1000],min[1000],max[1000];
	for (int a=0;a<1000;a++)
	{
		s[a]=0;
		min[a]=10001;
		max[a]=-1;
	}
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		y=x%m;
		s[y]+=x;
		if (min[y]>x)
			min[y]=x;
		if (max[y]<x)
			max[y]=x;
	}
	for (int i=0;i<m;i++)
		printf("%d %d %d\n",s[i],max[i],min[i]);
	return 0;
}
