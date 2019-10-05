#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 20
int N, M;
int table[MAX][MAX];
int ans[MAX];
int dist = INT_MAX;
int ordered[MAX];
int check[MAX];

void order(int id, int d) {
	if (id > N) {			
		if (d < dist) {		// TEMP ANSWER, SAVE IT FOR LATER (MIN DISTANCE)
			dist = d;
			for (int i = 1; i <= N; i++)
				ans[i] = ordered[i];
		}
		return;
	}
	if (d >= dist)
		return;				// CUT SEARCH
	for (int i = 0; i < N; i++) {
		if (check[i])
			continue;		//CURRENTLY USING THIS SEATING
		int temp = d;
		for (int j = 1; j < id; j++) {
			if (table[ordered[j]][i])		//IF THEY'RE FRIENDS
				if (id - j > temp)
					temp = id - j;			//MAXIMAL DISTANCE WITH ALL PREVIOUS SEATINGS
		}
		check[i] = id;		// MARK AS USED
		ordered[id] = i;
		order(id+1, temp);	//KEEP CHECKING THIS COMBINATION
		check[i] = 0;		//UNMARK USED
	}
	return;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		char c1[2], c2[2];
		scanf("%s %s", c1, c2);
		int x = c1[0] - 'A';
		int y = c2[0] - 'A';
		table[x][y] = table[y][x] = 1;
	}
	order(1, 0);
	printf("%d\n", dist);
	for (int i = 1; i <= N; i++) {
		printf("%c", ans[i]+'A');
		if (i!=N)
			printf(" ");
	}
	printf("\n");
	return 0;
}