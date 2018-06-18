#include <stdio.h>
#pragma GCC optimize("Ofast") 
int seesaw[16384];
int main(void) {
	int n,weight=0,j,i;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d ",&seesaw[i]);
		weight+=seesaw[i];
	}
	for (int k=0;k<n;k++) {
		int x=0,y=0,w1=0,w2;
		w2=weight;
		for (i=0;i<n;i++)
			y+=seesaw[i]*(i+1);
		for (i=0;i<n;++i) {
			x+=w1;
			y-=w2;
			w1+=seesaw[i];
			w2-=seesaw[i];
			if (x==y) {
				printf("%d",i);
				return 0;
			}
		}
		seesaw[k]^=seesaw[n-k-1]^=seesaw[k]^=seesaw[n-k-1];
	}	
	return 0;
}