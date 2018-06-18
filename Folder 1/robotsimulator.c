#include <stdio.h>
int main(int argc, char const *argv[])
{
	int dx[5] = {0,1,-1,0,0};
	int dy[5] = {0,0,0,1,-1};
	int n,m,p,x=0,y=0;
	puts("0"); puts("0");
	scanf("%d %d",&n,&m);
	while (scanf("%d",&p)!=EOF) {
		if (p%5==0)
			continue;
		if (x+(dx[p%5]*p)>=0 && x+(dx[p%5]*p)<n && y+(dy[p%5]*p)<m && y+(dy[p%5])*p>=0) {
			x+=dx[p%5]*p; y+=dy[p%5]*p;
			printf("%d\n%d\n",x,y);
		}
	}
	return 0;
}