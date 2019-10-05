#include <stdio.h>
int people[64];
int mat[64][64];
int checked[64];
int MAX, N;

void selection(int index, int sum) {
	if (index == N) {
		if (sum > MAX)
			MAX = sum;
		return;
	}
	selection(index + 1, sum);
	for (int i = 0; i < index; i++)
		if ((checked[i] == 1) && (mat[i][index] == 1))
			return;
	checked[index] = 1;
	selection(index + 1, sum + people[index]);
	checked[index] = 0;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
		scanf("%d",&people[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d",&mat[i][j]);
	selection(0, 0);
	printf("%d",MAX);
	return 0;
}