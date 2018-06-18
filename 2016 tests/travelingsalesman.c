#include <stdio.h>
int N;
int visit[14];
int mat[14][14];
int min = 10000000;
void minroute(int point, int dist, int amount) {
	if (dist>=min)
		return;
	if (amount==N) {
		dist+=mat[point][0];
		if (dist<min)
			min = dist;
		return;
	}
	for (int i=1;i<N;i++) {
		if (visit[i]==0 && i!=point) {
			visit[i]=1;
			minroute(i,dist+mat[point][i],amount+1);
			visit[i]=0;
		}
	}
	return;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			scanf("%d",&mat[i][j]);
	visit[0]=1;
	minroute(0,0,1);
	printf("%d",min);
	return 0;
}