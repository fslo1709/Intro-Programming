#include <stdio.h>
#include <string.h>
int hash(char *c, int size) {
	int x=0, len=strlen(c);
	for (int i=0;i<len;i++) {
		if (c[i]>='0' && c[i]<='9')
			x+=c[i]-'0';
		else
			x+=c[i];
	}
	x%=size;
	return x;
}
struct entries {
	int indexes[10000];
};
struct ref {
	char p[101];
};
struct ref reference[10000];
struct entries table[1000];
int count[1000]={0};
char temps[101];
int main(int argc, char const *argv[])
{
	int s,n,q,temp;
	scanf("%d %d %d",&s,&n,&q);
	for (int i=0;i<n;i++) {
		scanf("%s",reference[i].p);
		temp = hash(reference[i].p,s);
		table[temp].indexes[count[temp]++] = i;
	}
	for (int i=0;i<q;i++) {
		scanf("%s",temps);
		temp = hash(temps,s);
		int flag = -1;
		for (int j=0;j<count[temp];j++)
			if (strcmp(reference[table[temp].indexes[j]].p,temps)==0) {
				flag = temp;
				break;
			}
		printf("%d\n",flag);
	}
	return 0;
}