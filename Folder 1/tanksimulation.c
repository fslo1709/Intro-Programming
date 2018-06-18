#include <stdio.h>
int main(int argc, char const *argv[])
{
	int map[501][501]={0};
	int tankxleft=0,tankxright=0,tankyup=0,tankydown=0;
	int n,m,l,w,o,x,y,inst;
	scanf("%d %d %d %d %d",&n,&m,&l,&w,&o);
	tankxright+=w-1;
	tankydown+=l-1;
	for (int i=0;i<l;i++)
		for (int j=0;j<w;j++)
			map[j][i]=1;
	for (int i=0;i<o;i++) {
		scanf("%d %d",&x,&y);
		map[x][y]=2;
	}
	while (scanf("%d",&inst)!=EOF) {
		int flag=0;
		if (inst==0) {
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++)
					printf("%d",map[j][i]);
				printf("\n");
			}
		}
		if (inst==1 && tankxright<m-1) {
			for (int i=tankyup;i<=tankydown;i++)
				if (map[tankxright+1][i]==2)
					flag++;
			if (flag<=1) {
				tankxright++;
				for (int i=tankyup;i<=tankydown;i++) {
					map[tankxleft][i]=0;
					map[tankxright][i]=1;
				}
				tankxleft++;
			}
		}
		if (inst==2 && tankydown<n-1) {
			for (int i=tankxleft;i<=tankxright;i++)
				if (map[i][tankydown+1]==2)
					flag++;
			if (flag<=1) {
				tankydown++;
				for (int i=tankxleft;i<=tankxright;i++) {
					map[i][tankyup]=0;
					map[i][tankydown]=1;
				}
				tankyup++;
			}
		}
		if (inst==3 && tankxleft>0) {
			for (int i=tankyup;i<=tankydown;i++)
				if (map[tankxleft-1][i]==2)
					flag++;
			if (flag<=1) {
				tankxleft--;
				for (int i=tankyup;i<=tankydown;i++) {
					map[tankxleft][i]=1;
					map[tankxright][i]=0;
				}
				tankxright--;
			}
		}
		if (inst==4 && tankyup>0) {
			for (int i=tankxleft;i<=tankxright;i++)
				if (map[i][tankyup-1]==2)
					flag++;
			if (flag<=1) {
				tankyup--;
				for (int i=tankxleft;i<=tankxright;i++) {
					map[i][tankyup]=1;
					map[i][tankydown]=0;
				}
				tankydown--;
			}
		}
		if (inst==5 && tankxright<m-1 && tankydown<n-1) {
			for (int i=tankxleft+1;i<=tankxright+1;i++)
				if (map[i][tankydown+1]==2)
					flag++;
			for (int i=tankyup+1;i<=tankydown;i++)
				if (map[tankxright+1][i]==2)
					flag++;
			if (flag<=1) {
				for (int i=tankyup;i<=tankydown;i++)
					map[tankxleft][i]=0;
				for (int i=tankxleft;i<=tankxright;i++)
					map[i][tankyup]=0;
				tankxleft++,tankxright++,tankyup++,tankydown++;
				for (int i=tankxleft;i<=tankxright;i++)
					map[i][tankydown]=1;
				for (int i=tankyup;i<=tankydown;i++)
					map[tankxright][i]=1;
			}
		}
	}
	return 0;
}