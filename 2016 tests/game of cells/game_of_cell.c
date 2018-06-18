int *g,*h;
int secgrid[50][50]={0};
int dirx[8]={-1,0,1,-1,1,-1,0,1},diry[8]={-1,-1,-1,0,0,1,1,1};
void game_of_cell(int grid[50][50],int outcome[50][50],int N) {
	g=&grid[0][0];
	h=&secgrid[0][0];
	for (int i=0;i<N;i++) {
		for (int j=0;j<50;j++) {
			for (int k=0;k<50;k++) {
				int healthy=0,dying=0;
				for (int l=0;l<8;l++) {
					int newj=j+diry[l],newk=k+dirx[l];
					if (newk>=0 && newj>=0 && newk<50 && newj<50) {
						if (*(g+(50*newj+newk))==1)
							dying++;
						if (*(g+(50*newj+newk))==2)
							healthy++;
					}
				}
				int cmp=*(g+(50*j+k));
				int *newh=h+(50*j+k);
				*newh=cmp;
				if (cmp==0)
					if (healthy==3) {
						*newh=2;
						continue;
					}
				if (cmp==1) {
					if (healthy==2) {
						*newh=2;
						continue;
					}
				}
				if (cmp==2) {
					if (healthy<2) {
						*newh=0;
						continue;
					}
					if (healthy>3) {
						*newh=1;
						continue;
					}
				}
			}
		}
		if (g==&grid[0][0]) {
			g=&secgrid[0][0];
			h=&grid[0][0];
		}
		else {
			g=&grid[0][0];
			h=&secgrid[0][0];
		}
	}
	for (int i=0;i<50;i++)
		for (int j=0;j<50;j++)
			outcome[i][j]=*(g+50*i+j);
}