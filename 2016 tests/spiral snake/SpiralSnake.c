int G[1000][1000];
void SpiralSnake(int N, int *snake, int *result) {
	G[N/2][N/2] = snake[0];
	int count = 1,length = 2, step=1;
	while (count<N*N) {
		for (int i=0;i<length;i++)
			G[N/2-step][N/2+step-1-i] = snake[count++];
		for (int i=0;i<length;i++)
			G[N/2-step+1+i][N/2-step] = snake[count++];
		for (int i=0;i<length;i++)
			G[N/2+step][N/2-step+1+i] = snake[count++];
		for (int i=0;i<length;i++)
			G[N/2+step-1-i][N/2+step] = snake[count++];
		length+=2;
		step++;
	}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			result[i*N+j] = G[j][i];
}