#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <errno.h>
#define MAX 65
char buff[MAX];
void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
	for (int i=0;i<a;i++)
		A[i]=NULL;
	for (int i=0;i<b;i++)
		B[i]=NULL;
	while (fgets(buff,MAX,stdin)) {
		char tok1[MAX]={0},tok2[MAX]={0},n1[MAX]={0},n2[MAX]={0},trash[MAX]={0};
		long num1,num2;
		int flag=0;
		char* ptr;
		sscanf(buff,"%s %s %s %s %s",tok1,n1,tok2,n2,trash);
		if (strlen(trash)>0) {
			puts("0"); continue;
		}
		if (strlen(tok1)==0 || strlen(tok2)==0 || strlen(n1)==0 || strlen(n2)==0) {
			puts("0"); continue;
		}
		for (int i=0;i<strlen(n1);i++)
			if (n1[i]<'0' || n1[i]>'9') {
				puts("0"); flag=1; break;
			}
		if (flag==1)
			continue;
		for (int i=0;i<strlen(n2);i++)
			if (n2[i]<'0' || n2[i]>'9') {
				puts("0"); flag=1; break;
			}
		if (flag==1)
			continue;
		num1=strtol(n1,&ptr,10);
		num2=strtol(n2,&ptr,10);
		if (strlen(tok1)==1 && strlen(tok2)==1) {
			if (tok1[0]=='A' && tok2[0]=='B') {
				if (num1>=a || num1<0 || num2>=b || num2<0) {
					puts("0"); continue;
				}
				A[num1]=&B[num2];
				puts("1");
				continue;
			}
			if (tok1[0]=='B' && tok2[0]=='C') {
				if (num1>=b || num1<0 || num2>=c || num2<0) {
					puts("0"); continue;
				}
				B[num1]=&C[num2];
				puts("1");
				continue;
			}
			puts("0");
			continue;
		}
		else
			puts("0");
			continue;
	}
}