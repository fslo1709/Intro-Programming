#include <stdio.h>
const dx[]={0,1,0,-1};
const dy[]={-1,0,1,0};
const dr[]={1,0,3,2};
int w,d;
int g[128][128];
int donde(int x,int y)
{
	if (x==d)	return y;
	if (y==w)	return w+d-1-x;
	if (x==-1)	return d+w+w-1-y;
	if (y==-1)	return d+w+w+x;
	return -1;
}
int wind(int x, int y, int di)
{
	x+=dx[di], y+=dy[di];
	while (x>=0 && x<d && y>=0 && y<w)
	{	if (g[x][y])
			di=dr[di];
		x+=dx[di], y+=dy[di];
	}
	return donde(x,y);
}
int main(void) {
	scanf("%d %d",&w,&d);
	for (int i=0;i<d;i++)
		for (int j=0;j<w;j++)
			scanf("%d",&g[i][j]);
	for (int i=0;i<w;i++)
		printf("%d\n",wind(d,i,3));
	for (int i=d-1;i>=0;i--)
		printf("%d\n",wind(i,w,0));
	for (int i=w-1;i>=0;i--)
		printf("%d\n",wind(-1,i,1));
	for (int i=0;i<d;i++)
		printf("%d\n",wind(i,-1,2));
	return 0;
}
