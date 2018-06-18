#include <stdio.h>
#include <string.h>
int table[26][26] = {0};
int main(int argc, char const *argv[])
{
	int used[27]={0};
	char train[101];
	char newprint[27];
	int t;
	scanf("%d",&t);
	while (scanf("%s",train)!=EOF) {
		int len = strlen(train);
		for (int i=1;i<len;i++)
			table[train[i-1]-'a'][train[i]-'a']++;
	}
	for (int i=0;i<26;i++) {
		for (int j=0;j<26;j++) {
			printf("%d",table[i][j]);
			if (j!=25)
				printf(" ");
		}
		puts("");
	}
	int newlen = 2;
	int max = t;
	int ix,iy;
	for (int i=0;i<26;i++)
		for (int j=0;j<26;j++) {
			if (table[i][j]>max) {
				max = table[i][j];
				ix = i, iy = j;
			}
		}
	newprint[0] = ix + 'a';
	newprint[1] = iy + 'a';
	used[ix]=1;
	used[iy]=1;
	ix = iy;
	while (newlen<26) {
		max = t;
		int flag = 0;
		for (int i=0;i<26;i++) {
			if (table[ix][i]>max && used[i]==0) {
				max = table[ix][i];
				iy = i;
				flag = 1;
			}
		}
		if (flag==0)
			break;
		newprint[newlen++] = iy + 'a';
		ix = iy;
		used[iy] = 1;
	}
	newprint[newlen] = '\0';
	printf("%s",newprint);
	return 0;
}