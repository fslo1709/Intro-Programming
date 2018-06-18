#include <stdio.h>
int dx[8]={-1,0,1,-1,1,-1,0,1},dy[8]={-1,-1,-1,0,0,1,1,1};
int grid1[100][100];
int grid2[100][100];
int livecount[100][100];
int *g,*h;
int main(int argc, char const *argv[])
{
	int n,k,posx,posy,max=-1;
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			scanf("%d",&grid1[i][j]);
			if (grid1[i][j]==1)
				livecount[i][j]=1;
			else
				livecount[i][j]=0;
		}
	g=&grid1[0][0];
	h=&grid2[0][0];
	for (int i=0;i<k;i++) {
		for (int a=0;a<n;a++) {
			for (int b=0;b<n;b++) {
				int liv = 0;
				for (int y=0;y<8;y++) {
					int newa = a+dy[y], newb = b+dx[y];
					if (newa>=0 && newa<n && newb>=0 && newb<n) 
						if (*(g+(100*newa+newb))==1)
							liv++;
				}
				*(h+100*a+b)=*(g+100*a+b);
				if (*(g+100*a+b)==1) {
					if (liv<2 || liv>3)
						*(h+100*a+b)=0;
					else {
						*(h+100*a+b)=1;
						livecount[a][b]++;
					}
				}
				else {
					if (liv==3) {
						*(h+100*a+b)=1;
						livecount[a][b]++;
					}
					else
						*(h+100*a+b)=0;
				}
			}
		}
		if (g==&grid1[0][0]) {
			g=&grid2[0][0];
			h=&grid1[0][0];
		}
		else {
			g=&grid1[0][0];
			h=&grid2[0][0];
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (livecount[i][j]>=max) {
				max = livecount[i][j];
				posx = i;
				posy = j;
			}
			printf("%d ",*(g+100*i+j));
		}
		printf("\n");
	}
	printf("%d %d",posx+1,posy+1);
	return 0;
}