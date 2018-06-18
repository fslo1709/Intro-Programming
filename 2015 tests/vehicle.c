#include <stdio.h>
void pos(int *t) {
	if (*t<0)
		*t=-(*t);
}
int dir(int a, int b, int x, int y) {
	int t=a*x+b*y;
	pos(&t);
	return t%4;
}
int gold(int c, int d, int e, int x, int y) {
	int t=c*x+d*y;
	pos(&t);
	return t%e;
}
int main(int argc, char const *argv[])
{
	int dirx[4]={0,1,0,-1};
	int diry[4]={1,0,-1,0};
	int a,b,c,d,e,p,q,r,s,x,y,F,totalg=0,trans=0;
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&p,&q,&r,&s,&x,&y,&F);
	while (F>=0) {
		if (trans==0)
			totalg+=gold(c,d,e,x,y);
		if (F==0)
			break;
		int newdir=dir(a,b,x,y);
		x+=dirx[newdir];
		y+=diry[newdir];
		F--;
		if (x==p && y==q) {
			x=r;
			y=s;
			trans=1;
		}
		else 
			if (x==r && y==s) {
				x=p;
				y=q;
				trans=1;
			}
			else
				trans=0;
	}
	printf("%d\n%d %d",totalg,x,y);
	return 0;
}