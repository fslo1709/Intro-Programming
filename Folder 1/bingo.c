#include <stdio.h>
char name[16][128];
int g[16][256][256],co[65536],ca[16][131072][2];
int n,m;
int check(int a, int b)
{
	return a>=0 && a<m && b>=0 && b<m;
}
int turn(int player, int a, int b)
{
	const int dirx[] = {0,0,1,-1,1,-1,1,-1};
	const int diry[] = {1,-1,0,0,1,-1,-1,1};
	for (int i=0;i<8;i+=2)
	{
		int c=0,a1,b1;
		a1=a,b1=b;
		for ( ; check(a1,b1) && g[player][a1][b1]==0;c++)
			a1+=dirx[i],b1+=diry[i];
		a1=a,b1=b;
		for ( ; check(a1,b1) && g[player][a1][b1]==0;c++)
			a1+=dirx[i+1],b1+=diry[i+1];
		if (c==m+1) return 1;
	}
	return 0;
}
int main(void) {
	int z;
	while (scanf("%d %d",&n,&m)==2)
	{
	for (int i=0;i<n;i++)
	{
		scanf("%s",name[i]);
		for (int j=0;j<m;j++)
			for (int k=0;k<m;k++)
			{
				scanf("%d",&g[i][j][k]);
				ca[i][g[i][j][k]][0]=j;
				ca[i][g[i][j][k]][1]=k;
			}
	}
	for (int i=0;i<m*m;i++)
		scanf("%d",&co[i]);
	for (int p=0;p<m*m;p++)
	{
		z=co[p];
		int ver=0;
		for (int i=0;i<n;i++)
		{
			g[i][ca[i][z][0]][ca[i][z][1]]=0;
			int w=turn(i,ca[i][z][0],ca[i][z][1]);
			ver |= w;
		}
		if (ver==1)
		{
			printf("%d",z);
			for (int i=0;i<n;i++)
			{
				int w=turn(i,ca[i][z][0],ca[i][z][1]);
				if (w) printf(" %s",name[i]);
			}
			puts("");
			break;
		}
	}
	}
	return 0;
}
