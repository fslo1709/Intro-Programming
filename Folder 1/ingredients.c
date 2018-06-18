#include <stdio.h>
#include <stdlib.h>
int DA,DB,DC,EA,EB,EC,FA,FB,FC,n;
void read(int);
int ing(int, int, int);
int main (void){
	scanf("%d %d %d",&DA,&DB,&DC);
	scanf("%d %d %d",&EA,&EB,&EC);
	scanf("%d %d %d",&FA,&FB,&FC);
	scanf("%d",&n);
	read(n);
	return 0;
}
int ing(int a, int b, int c)
{
	if (a==0 && b==0 && c==0)
		return 1;
	if (a<0 || b<0 || c<0)
		return 0;
	return ing(a-DA,b-DB,c-DC) || ing(a-EA,b-EB,c-EC) || ing(a-FA,b-FB,c-FC);
}
void read(int n)
{
	int a,b,c;
	if (n==0)
		return;
	scanf("%d %d %d",&a,&b,&c);
	int x=ing(a,b,c);
	if (x==1)
		puts("yes");
	else
		puts("no");
	read(n-1);
}
