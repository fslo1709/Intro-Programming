int dirx[8] = {1,2,2,1,-1,-2,-2,-1};
int diry[8] = {-2,-1,1,2,2,1,-1,-2};

int validMoveNum(int r, int c, int n, int visited[100][100]) {
	if (r<0 || c<0 || r>=n || c>=n || visited[r][c]!=0)
		return -1;
	int count = 0;
	for (int i = 0; i < 8; i++) {
		int tempx = r+dirx[i];
		int tempy = c+diry[i];
		if (tempx >= n || tempy >= n || tempx<0 || tempy<0)
			continue;
		if (visited[tempx][tempy] == 0)
			count++;
	}
	return count;
}