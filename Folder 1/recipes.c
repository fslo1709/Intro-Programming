#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b);
int place(char s1[]);
void compare(char s1[], char s2[]);
char meals[128][16][128],s1[128],s2[128];
int n,ing[128],m;
int main(void){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s",meals[i][0]);
		scanf("%d",&ing[i]);
		for (int j=1;j<=ing[i];j++)
			scanf("%s",meals[i][j]);
		qsort(meals[i]+1,ing[i],sizeof(meals[i][0]),cmp);
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		scanf("%s %s",s1,s2);
		compare(s1,s2);
	}
	return 0;
}
int cmp(const void* a, const void* b)
{
	const char* ia= (const char*)a;
	const char* ib= (const char*)b;
	return strcmp(ia,ib);
}
int place(char s1[])
{
	for (int i=0;i<n;i++){
		if (strcmp(meals[i][0],s1)==0)
			return i;
	}
	return -1;
}
void compare(char s1[], char s2[])
{
	int f=0;
	int a=place(s1), b=place(s2);
	if (a==-1 || b==-1)
	{
		puts ("nothing");
		return;
	}
	else
	{
		for (int i=1;i<=ing[a];i++)
		{
			for (int j=1;j<=ing[b];j++)
			{
				if (strcmp(meals[a][i],meals[b][j])==0)
				{
					if (f) printf(" ");
					f=1;
					printf("%s",meals[a][i]);
					break;
				}
			}
		}
	}
	if (!f) puts("nothing");
	else puts("");
	return;
}
