#include <stdio.h>	
#include <stdlib.h>
#define MAX 65536
int el[MAX]={};
int main (void){
	for (int i=0;i<MAX;i++)
		el[i]=0;
	char name[201];
	int n;
	scanf("%s",name);
	FILE *fin;
	fin = fopen(name,"rb");
	fread(&n,sizeof(int),1,fin);
	for (int i=0;i<n;i++)
	{
		signed short temp;
		fread(&temp,sizeof(signed short),1,fin);
		el[temp+32768]++;
	}
	int max=el[0];
	int indexmax=-32768;
	for (int i=1;i<MAX;i++)
	{
		if (el[i]>=max)
		{
			max=el[i];
			indexmax=i-32768;
		}
	}
	printf("%d\n%d",indexmax,max);
	fclose(fin);
}