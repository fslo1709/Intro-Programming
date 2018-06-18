#include <stdio.h>
int puzzle[4][4];
int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};
int main(int argc, char const *argv[])
{
	int cx,cy,move,flag = 0, last = 0;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++) {
			scanf("%d",&puzzle[i][j]);
			if (puzzle[i][j]==0)
				cy = i, cx = j;
		}
	while (scanf("%d",&move)!=EOF) {
		if (move==0)
			break;
		int f3 = 0;
		for (int i=0;i<4;i++) {
			int tx = cx+dirx[i],ty = cy+diry[i];
			if (tx>=0 && tx<4 && ty>=0 && ty<4)
				if (puzzle[ty][tx]==move) {
					int tmp = puzzle[ty][tx];
					puzzle[ty][tx] = puzzle[cy][cx];
					puzzle[cy][cx] = tmp;
					cx = tx;
					cy = ty;
					f3 = 1;
					break;
				}
		}
		if (f3==0)
			continue;
		int f2 = 0;
		for (int i=0;i<15;i++) {
			if (puzzle[i/4][i%4]!=i+1) {
				f2 = 1;
				break;
			}
		}
		if (f2 == 0) {
			flag = 1;
			last = move;
			break;
		}
	}
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			printf("%d",puzzle[i][j]);
			if (j<3)
				printf(" ");
		}
		puts("");
	}
	printf("%d",flag);
	if (last>0)
		printf(" %d",last);
	return 0;
}