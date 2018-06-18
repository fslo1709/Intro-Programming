#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[8];
}S;
S plates[30],first[30],second[30];
int indf,inds;
int main(int argc, char const *argv[])
{
	int N,flag;
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%s",plates[i].name);
		flag = 0;
		int sumdig = 0, digits = 0;
		if (plates[i].name[2]=='-') {
			for (int j=0;j<7;j++) {
				if (j!=2) {
					if (plates[i].name[j]<'0' || (plates[i].name[j]>'9' && plates[i].name[j]<'A') || (plates[i].name[j]>'Z' && plates[i].name[j]<'a') || plates[i].name[j]>'z') {
						flag = 1;
						break;
					}
					if (plates[i].name[j]>='0' && plates[i].name[j]<='9') {
						sumdig+=plates[i].name[j]-'0';
						digits = 1;
					}
				}
			}
			if (flag == 1 || digits == 0 || sumdig%7==0)
				continue;
			if (plates[i].name[0]=='4' && plates[i].name[1]=='4' || plates[i].name[3]=='4' && plates[i].name[4]=='4' || plates[i].name[4]=='4' && plates[i].name[5]=='4' || plates[i].name[5]=='4' && plates[i].name[6]=='4')
				continue;
			for (int j=0;j<6;j++) {
				if (j==2)
					continue;
				int count = 1;
				for (int k=j+1;k<7;k++) {
					if (k==2)
						continue;
					if (plates[i].name[k] == plates[i].name[j])
						count++;
					if (count>2) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
				continue;
			strcpy(first[indf++].name,plates[i].name);
		}
		else if (plates[i].name[3]=='-') {
			for (int j=0;j<7;j++) {
				if (j!=3) {
					if (plates[i].name[j]<'0' || (plates[i].name[j]>'9' && plates[i].name[j]<'A') || (plates[i].name[j]>'Z' && plates[i].name[j]<'a') || plates[i].name[j]>'z') {
						flag = 1;
						break;
					}
					if (plates[i].name[j]>='0' && plates[i].name[j]<='9') {
						sumdig+=plates[i].name[j]-'0';
						digits = 1;
					}
				}
			}
			if (flag == 1 || digits==0 || sumdig%7==0)
				continue;
			if (plates[i].name[0]=='4' && plates[i].name[1]=='4' || plates[i].name[1]=='4' && plates[i].name[2]=='4' || plates[i].name[4]=='4' && plates[i].name[5]=='4' || plates[i].name[5]=='4' && plates[i].name[6]=='4')
				continue;
			for (int j=0;j<6;j++) {
				if (j==3)
					continue;
				int count = 1;
				for (int k=j+1;k<7;k++) {
					if (k==3)
						continue;
					if (plates[i].name[k] == plates[i].name[j])
						count++;
					if (count>2) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
				continue;
			strcpy(second[inds++].name,plates[i].name);
		}
	}
	for (int i=0;i<indf-1;i++)
		for (int j=i+1;j<indf;j++)
			if (strcmp(first[i].name,first[j].name)>0) {
				char tmp[8];
				strcpy(tmp,first[i].name);
				strcpy(first[i].name,first[j].name);
				strcpy(first[j].name,tmp);
			}
	for (int i=0;i<inds-1;i++)
		for (int j=i+1;j<inds;j++)
			if (strcmp(second[i].name,second[j].name)>0) {
				char tmp[8];
				strcpy(tmp,second[i].name);
				strcpy(second[i].name,second[j].name);
				strcpy(second[j].name,tmp);
			}
	for (int i=0;i<indf;i++)
		printf("%s\n",first[i].name);
	for (int i=0;i<inds;i++)
		printf("%s\n",second[i].name);
	return 0;
}