#include <stdio.h>
#include <string.h>
#define MAX 10000000
char W[MAX];
char **firstlev[1024];
int numfirst[1024];
char *seclev[16384];
int main(int argc, char const *argv[])
{
	int N,M,x=0,pos=0,pointsec = 0, l1,l2,w1,w2;
	char new;
	scanf("%d",&N);
	for (int i=0;i<N;i++){
		firstlev[i]=&seclev[pointsec];
		while (scanf("%s%c",&W[pos],&new)==2) {
			seclev[pointsec++] = &W[pos];
			numfirst[i]++;
			pos += strlen(&W[pos])+1;
			if (new=='\n')
				break;
		}
	}
	scanf("%d",&M);
	for (int i=0;i<M;i++) {
		scanf("%d %d %d %d",&l1,&w1,&l2,&w2);
		char *tmp = firstlev[l1][w1];
		firstlev[l1][w1] = firstlev[l2][w2];
		firstlev[l2][w2] = tmp;
	}
	for (int i=0;i<N;i++) {
		for (int j=0;j<numfirst[i];j++) {
			printf("%s",firstlev[i][j]);
			if (j<numfirst[i]-1)
				printf(" ");
		}
		puts("");
	}
	return 0;
}