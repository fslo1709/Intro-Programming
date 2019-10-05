#include <stdio.h>

int board[101][101];
int knights[11000][3];
int steps;

int posix[8] = {1,2,2,1,-1,-2,-2,-1};
int posiy[8] = {-2,-1,1,2,2,1,-1,-2};

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &knights[i][1], &knights[i][0]);
		board[knights[i][0]][knights[i][1]] = (i+1)*10000;
	}
	int kcount = m;
	while (kcount > 0) {
		steps++;
		for (int i = 0; i < m; i++) {
			if (knights[i][2] == 1)
				continue;
			int count = 10;
			int moveindex = -1;
			for (int j = 0; j < 8; j++) {
				int x = knights[i][0]+posix[j];
				int y = knights[i][1]+posiy[j];
				int temp = board[x][y];

				if (x < 0 || x>=n || y < 0 || y>= n || temp> 0)
					continue;

				int curcount = 0;
				for (int k = 0; k < 8; k++) {
					int nextx = x+posix[k];
					int nexty = y+posiy[k];
					int nexttemp = board[nextx][nexty];

					if (nextx < 0 || nextx>=n || nexty < 0 || nexty>= n || nexttemp> 0)
						continue;
					else
						curcount++;
				}
				if (curcount < count) {
					count = curcount;
					moveindex = j;
				}
			}
			if (moveindex == -1) {
				knights[i][2] = 1;
				kcount--;
			}
			else {
				knights[i][0] += posix[moveindex];
				knights[i][1] += posiy[moveindex];
				board[knights[i][0]][knights[i][1]] = (i+1)*10000 + steps;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", board[j][i]);
			if (j!=n-1)
				printf(" ");
		}
		puts("");
	}
	return 0;
}