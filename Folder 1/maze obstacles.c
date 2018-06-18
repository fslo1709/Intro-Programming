#include <stdio.h>
#include <stdlib.h>
int ways(int, int);
int r,c;
int maze[12][12];
int main (void){
    scanf("%d %d",&r,&c);
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
			scanf("%d",&maze[j][i]);
    printf("%d",ways(0,r-1));
    return 0;
}
int ways(int x, int y)
{
	int res=0;
	if (x==c-1 && y==0)
		return 1;
	if (maze[x][y]==0)
		return 0;
    if (y>0)
        res=ways(x,y-1);
    if (x<c-1)
		res+=ways(x+1,y);
    return res;
}