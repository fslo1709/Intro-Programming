#include <stdio.h>
#define MAXN 65536
long long px[MAXN], py[MAXN], pn;
int has (int x, int y)
{
	for (int i=0;i<pn;i++)
		if (px[i]==x && py[i]==y)
			return 1;
	return 0;
}
int main(void) {
	int tcases;
	scanf("%d",&tcases);
	for (int k=0;k<tcases;k++)
	{
		long long x[3]={}, y[3]={}, r[3]={};
		for (int i=0;i<3;i++)
			scanf("%lld %lld %lld", &x[i],&y[i],&r[i]);
		pn=0;
		int re=0;
		for (int i=0;i<3;i++)
		{
			for (long long pex=x[i]-r[i]; pex<=x[i]+r[i]; pex++) 
			{
				for (long long pey=y[i]-r[i]; pey<=y[i]+r[i]; pey++) 
				{
					if (!has(pex,pey)) 
					{
						pex[pn]=tx, pey[pn]=ty, pn++;
						int in = 0;
						for (int k = 0; k < 3; k++)
							in+=(pex-x[k])*(pex-x[k])+(pey-y[k])*(pey-y[k]) <= r[k]*r[k];
						re+=in&1; 
					}
				}
			}
		}
		printf("%d\n",re);
	}
	return 0;
}
