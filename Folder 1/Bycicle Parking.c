#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int n,m;
	int px[10],py[10],pc[10],tot[10]={};
	int bx,by=0;
	scanf("%d",&n);
	for (int j=0;j<n;j++)
		scanf("%d %d %d",&px[j],&py[j],&pc[j]);
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d %d",&bx,&by);
		int par=-1, pos=0x3f3f3f3f;
		for (int j=0;j<n;j++)
		{
			if (pc[j]==0)
				continue;
			int dist=abs(px[j]-bx)+abs(py[j]-by);
			if (dist < pos || (dist == pos && (px[j] < px[par] || (px[j] == px[par] && py[j] < py[par]))))
				pos=dist, par=j;
		}
		tot[par]++, pc[par]--;
	}
	for (int i=0;i<n;i++)
	{
		printf("%d\n",tot[i]);
	}
	return 0;
}
