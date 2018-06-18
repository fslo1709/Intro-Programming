#include <stdio.h>
int cross(int ax, int ay, int bx, int by, int cx, int cy) {
	return (ax-cx)*(by-cy)-(ay-cy)*(bx-cx);
}
int min(int x, int y) {
	if (x>y)
		return y;
	else
		return x;
}
int max(int x, int y) {
	if (x>y)
		return x;
	else
		return y;
}
int dirx[4]={0,1,0,1};
int diry[4]={0,0,-1,-1};
int main(int argc, char const *argv[])
{
	int x1,x2,x3,y1,y2,y3,minx,miny,maxx,maxy,total=0;
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	minx = min(x1,x2);
	minx = min(minx,x3);
	miny = min(y1,y2);
	miny = min(miny,y3);
	maxx = max(x1,x2);
	maxx = max(maxx,x3);
	maxy = max(y1,y2);
	maxy = max(maxy,y3);
	for (int i=minx;i<=maxx;i++)
		for (int j=miny;j<=maxy;j++) {
			for (int k=0;k<4;k++){
				int a,b,c;
				a = cross(x1,y1,x2,y2,i+dirx[k],j+diry[k]);
				b = cross(x2,y2,x3,y3,i+dirx[k],j+diry[k]);
				c = cross(x3,y3,x1,y1,i+dirx[k],j+diry[k]);
				if (!((a>=0 && b>=0 && c>=0)||(a<=0 && b<=0 && c<=0)))
					break;
				if (k==3)
					total++;
			}
		}
	printf("%d",total);
	return 0;
}