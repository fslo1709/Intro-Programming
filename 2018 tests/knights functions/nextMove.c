int moved[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int nextMove(int r, int c, int n, int visited[100][100]) {
	if (validMoveNum(r, c, n, visited)==0)
		return -1;
	int index = -1, min = 10, temp = -1;
	for (int i = 0; i < 8; i++) {
		int tempx = r+moved[i][0];
		int tempy = c+moved[i][1];
		temp = validMoveNum(tempx, tempy, n, visited);
		if (temp == -1)
			continue;
		if (temp < min) {
			min = temp;
			index = i;
		}
	}
	return index;
}