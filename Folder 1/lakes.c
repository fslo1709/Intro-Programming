#include <stdio.h>
#include <stdlib.h>
int lake(int,int);
int n,m,l=0,size[262144]={};
int map[512][512]={};
int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int main (void){
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{ 
			if (map[i][j]>0)	
				size[l++]=lake(i,j);
		}
	qsort(size,l,sizeof(int),comp);
	for (int i=0;i<l;i++)
		printf("%d\n",size[i]);
	return 0;
}
int lake(int x,int y)
{
	if (x<0 || x>=n || y<0 || y>=m || map[x][y]!=1)
		return 0;
	map[x][y]=-1;
	return 1+lake(x-1,y)+lake(x+1,y)+lake(x,y-1)+lake(x,y+1);
}