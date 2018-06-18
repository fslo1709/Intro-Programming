#include <stdio.h>
int main(void) {
	int x,y,u,d,l,r;
	scanf("%d %d",&l,&u),r=l,d=u;
	while (scanf("%d %d",&x,&y)==2)
	{
		if (x>l)
			l=x;
		if (x<r)
			r=x;
		if (y>u)
			u=y;
		if (y<d)
			d=y;
	}
	printf("%d\n",(l-r)*(u-d));
	return 0;
}
