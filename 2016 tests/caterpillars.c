#include <stdio.h>
int grid[1000][1000]={0};
int pos[1000][2]={0};
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int main(int argc, char const *argv[])
{
	int n,m,sx,sy,ex,ey,q,d,head=0,tail,len;
	scanf("%d %d %d %d %d %d %d",&n,&m,&sx,&sy,&ex,&ey,&q);
	if (sx==ex) 
		if (sy>ey) {
			for (int i=sy;i>=ey;i--) {
				grid[sx][i]=1;
				pos[sy-i][0]=sx;
				pos[sy-i][1]=i;
			}
			len=tail=sy-ey;
		}
		else {
			for (int i=sy;i<=ey;i++) {
				grid[sx][i]=1;
				pos[i-sy][0]=sx;
				pos[i-sy][1]=i;
			}
			len=tail=ey-sy;
		}
	if (sy==ey)
		if (sx>ex) {
			for (int i=sx;i>=ex;i--) {
				grid[i][sy]=1;
				pos[sx-i][0]=i;
				pos[sx-i][1]=sy;
			}
			len=tail=sx-ex;
		}
		else {
			for (int i=sx;i<=ex;i++) {
				grid[i][sy]=1;
				pos[i-sx][0]=i;
				pos[i-sx][1]=sy;
			}
			len=tail=ex-sx;
		}
	for (int i=0;i<q;i++) {
		scanf("%d",&d);
		if (pos[head][0]+dirx[d]==n || pos[head][0]+dirx[d]<0 || pos[head][1]+diry[d]==m || pos[head][1]+diry[d]<0)
			break;
		if (grid[pos[head][0]+dirx[d]][pos[head][1]+diry[d]]==1)
			if (pos[head][0]+dirx[d]==pos[tail][0] && pos[head][1]+diry[d]==pos[tail][1])
				;
			else
				break;
		grid[pos[tail][0]][pos[tail][1]]=0;
		pos[tail][0]=pos[head][0]+dirx[d];
		pos[tail][1]=pos[head][1]+diry[d];
		tail--,head--;
		if (tail<0)
			tail=len;
		if (head<0)
			head=len;
		grid[pos[head][0]][pos[head][1]]=1;
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++)
			printf("%d",grid[i][j]);
		puts("");
	}
	return 0;
}