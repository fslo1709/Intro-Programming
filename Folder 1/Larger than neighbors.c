#include <stdio.h>
int main(void) {
	int r,c;
	int a[102][102]={};
	scanf("%d %d",&r,&c);
	for (int i=0;i<102;i++)
		for (int j=0;j<102;j++)
			a[i][j]=0;
	for (int i=1;i<=c;i++)
		for (int j=1;j<=r;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=c;i++)
		for (int j=1;j<=r;j++)
		{
			if ((a[i][j]>a[i-1][j])&&(a[i][j]>a[i][j-1])&&(a[i][j]>a[i+1][j])&&(a[i][j]>a[i][j+1]))
				printf("%d\n",a[i][j]);
		}
	return 0;
}
