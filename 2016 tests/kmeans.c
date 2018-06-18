#include <stdio.h>
#include <string.h>

struct groupp {
	int list[50];
	int leader;
	int poslist;
};

int abs(int x) {
	if (x<0)
		return -x;
	return x;
}
int dist(char *a, char *b, int len) {
	int x=0;
	for (int i=0;i<len;i++)
		x+=abs(a[i]-b[i]);
	return x;
}

int disttomean(char *a, int *b, int len) {
	int x=0;
	for (int i=0;i<len;i++)
		x+=abs(a[i]-b[i]);
	return x;
}

struct groupp G[3];
char kmeans[50][11];
int main(int argc, char const *argv[])
{
	int n,l,r,fgroup,test;
	int mean[3][11];
	scanf("%d %d %d",&n,&l,&r);
	for (int i=0;i<n;i++)
		scanf("%s",kmeans[i]);
	for (int i=0;i<3;i++) {
		G[i].list[0] = i;
		G[i].leader = i;
		G[i].poslist = 1;
	}
	
	for (int i=0;i<r;i++) {
		for (int j=0;j<n;j++) {
			if (j==G[0].leader || j==G[1].leader || j==G[2].leader)
				continue;
			int mind=dist(kmeans[j],kmeans[G[0].leader],l);
			fgroup = 0;
			for (int k=1;k<3;k++) {
				test = dist(kmeans[j],kmeans[G[k].leader],l);
				if (test<mind) {
					mind = test;
					fgroup = k;
				}
				if (test == mind) {
					if (strcmp(kmeans[G[fgroup].leader],kmeans[G[k].leader])>0) 
						fgroup = k;
				}
			}
			G[fgroup].list[G[fgroup].poslist++] = j;
		}
		for (int j=0;j<3;j++) {
			for (int k=0;k<l;k++)	
				mean[j][k] = 0;
			for (int k=0;k<G[j].poslist;k++)
				for (int z=0;z<l;z++)
					mean[j][z]+=kmeans[G[j].list[k]][z];
			for (int k=0;k<l;k++) 
				mean[j][k] = mean[j][k]/G[j].poslist;
			int minmean = 0;
			for (int k=0;k<l;k++)
				minmean += abs(mean[j][k]-kmeans[G[j].list[0]][k]);
			int newleader = G[j].leader;
			for (int k=1;k<G[j].poslist;k++) {
				int tmp = 0;
				for (int z=0;z<l;z++)
					tmp += abs(mean[j][z]-kmeans[G[j].list[k]][z]);
				if (tmp<minmean) {
					newleader = G[j].list[k];
					minmean = tmp;
				}
				if (tmp == minmean)
					if (strcmp(kmeans[G[j].list[k]],kmeans[newleader])<0)
						newleader = G[j].list[k];
			}
			G[j].leader = newleader;
			G[j].list[0] = newleader;
			G[j].poslist = 1;
		}
	}
	int tma;
	int a1 = G[0].leader;
	int a2 = G[1].leader;
	int a3 = G[2].leader;
	if (strcmp(kmeans[a1],kmeans[a2])>0) {
		tma = a1;
		a1 = a2;
		a2 = tma;
	}
	if (strcmp(kmeans[a1],kmeans[a3])>0) {
		tma = a1;
		a1 = a3;
		a3 = tma;
	}
	if (strcmp(kmeans[a2],kmeans[a3])>0) {
		tma = a2;
		a2 = a3;
		a3 = tma;
	}
	printf("%s\n%s\n%s",kmeans[a1],kmeans[a2],kmeans[a3]);
	return 0;
}