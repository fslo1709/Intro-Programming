#include <stdio.h>
#include "validMoveNum.h"
#include "nextMove.h"

int board[100][100];
int knights[10000][3];
int movex[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int main()
{
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &knights[i][0], &knights[i][1]);
		board[knights[i][0]][knights[i][1]] = 10000*(i+1);
	}
	int step = 0, count = m;
	while (count > 0) {
		step++;
		for (int i = 0; i < m; i++) {
			if (knights[i][2]!=0)
				continue;
			int temp = nextMove(knights[i][0], knights[i][1], n, board);
			if (temp == -1) {
				knights[i][2] = 1;
				count--;
			}
			else {
				knights[i][0] += movex[temp][0];
				knights[i][1] += movex[temp][1];
				board[knights[i][0]][knights[i][1]] = 10000*(i+1) + step;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", board[i][j]);
			if (j<n-1)
				printf(" ");
			else puts("");
		}
	}
	return 0;
}