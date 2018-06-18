#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int distance(char[], char[]);
char strings[1000][11];
int main (void){
	int i=0,id1=0,id2=0,min=10000,pair;
	char s1[10],s2[10];
    while (scanf("%s",&strings[i][0])==1)
		i++;
	for (int j=0;j<i-1;j++)
		for (int k=j+1;k<i;k++)
		{
			strcpy(s1,&strings[j][0]);
			strcpy(s2,&strings[k][0]);
			int comp=distance(s1,s2);
			if (comp<min)
			{
				min=comp;
				id1=j;
				id2=k;
				pair=1000*j+k;
			}
			if (comp==min)
			{
				if ((1000*j+k)<pair)
				{
					pair=1000*j+k;
					id1=j;
					id2=k;
				}
			}
		}
	printf("%d %d %d",min,id1,id2);
    return 0;
}
int distance(char a[], char b[])
{
	char c[10]={},d[10]={};
	strcpy(c,&a[1]);
	strcpy(d,&b[1]);
	if (strlen(a)==0)
		return strlen(b);
	if (strlen(b)==0)
		return strlen(a);
	if (a[0]==b[0])
		return distance(c,d);
	int x=distance(a,d);
	int y=distance(c,b);
	if (x>y)
		return 1+y;
	return 1+x;
}