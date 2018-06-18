#include <stdio.h>
int dx[] ={-1,0,1,0};
int dy[] ={0,1,0,-1};
int main(void) {
	int n;
	int city[102][102]={};
	int cont[4];
	int temp;
	for (int i=0;i<4;i++)
		cont[i]=0;
	scanf("%d",&n);
	for (int i=0;i<102;i++)
		city[i][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&city[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			temp=0;
			if (city[i][j]==1)
			{
				for (int k=0;k<4;k++)
				{
					if (city[i][j]==city[i+dx[k]][j+dy[k]])
						temp++;
				}
				if ((temp>0)&&(temp!=2))
					cont[temp-1]++;
				else
					if (!((temp==2)&&((city[i-1][j]==city[i+1][j])||(city[i][j-1]==city[i][j+1]))))
						cont[temp-1]++;
			}
			
		}
	printf("%d\n%d\n%d\n%d\n",cont[3],cont[2],cont[1],cont[0]);
	return 0;
}
