#include <stdio.h>
#include <string.h>
typedef struct {
	char A[51];
	int cost;
	int len;
} words;
words X[20];
int N,mincost = 2147483647;
int check[26];
void recurs(int num, int c, int tmp[26]) {
	if (c>mincost)
		return;
	if (num==N) {
		int v = 1;
		for (int i=0;i<26;i++)
			v &= tmp[i];
		if (v && (c<mincost))
			mincost = c;
		return;
	}
	int comp[26];
	for (int i=0;i<26;i++) 
		comp[i] = tmp[i];
	recurs(num+1,c,comp);
	for (int i=0;i<X[num].len;i++)
		tmp[X[num].A[i]-'a'] = 1;
	recurs(num+1,c+X[num].cost,tmp);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%s %d",&X[i].A,&X[i].cost);
		X[i].len = strlen(X[i].A);
	}
	recurs(0,0,check);
	printf("%d",mincost);
	return 0;
}