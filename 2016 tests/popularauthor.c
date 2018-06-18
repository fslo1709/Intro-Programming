#include <stdio.h>
#include <string.h>
struct authors {
	char name[51];
	int indexes[100];
};
struct books {
	char name[51];
	int number;
};
struct authors A[100];
struct books B[100];
int countA=0,countB=0,countIndex[100]={0};
char tmp[51];
int main(int argc, char const *argv[])
{
	int m,j,x;
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		scanf("%s %s",tmp,B[countB].name);
		for (j=0;j<countA;j++)
			if (strcmp(A[j].name,tmp)==0)
				break;
		if (j==countA)
			strcpy(A[countA++].name,tmp);
		A[j].indexes[countIndex[j]++] = countB++;
	}
	for (int i=0;i<m;i++) {
		scanf("%s %d",tmp,&x);
		for (j=0;j<countB;j++) 
			if (strcmp(B[j].name,tmp)==0)
				break;
		if (j==countB)
			continue;
		B[j].number = x;
	}
	int max = -1, indmax = 0;
	for (int i=0;i<countA;i++) {
		int count=0;
		for (j=0;j<countIndex[i];j++)
			count += B[A[i].indexes[j]].number;
		if (count>max) {
			max = count;
			indmax = i;
		}
		if (max == count) 
			if (strcmp(A[i].name,A[indmax].name)<0) {
				max = count;
				indmax = i;
			}
	}
	printf("%s %d",A[indmax].name,max);
	return 0;
}