#pragma GCC optimize ("Ofast")
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,m,plar,pseclar,h,maxvalr,secmaxvalr,maxmaxval=-1,pmaxx,pmaxy;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		maxvalr=-1;
		secmaxvalr=-1;
		for (int j=1;j<=m;j++) {
			scanf("%d",&h);
			if (h>=maxvalr) {
				secmaxvalr=maxvalr;
				pseclar=plar;
				maxvalr=h;
				plar=j;
			}
			else 
				if (h>=secmaxvalr) {
					secmaxvalr=h;
					pseclar=j;
				}
		}
		if (maxvalr>=maxmaxval) {
			maxmaxval=maxvalr;
			pmaxx=plar;
			pmaxy=i;
		}
		printf("%d %d\n",plar,pseclar);
	}
	printf("%d %d",pmaxy,pmaxx);
	return 0;
}