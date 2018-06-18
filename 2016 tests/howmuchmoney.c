#include <stdio.h>
#include <string.h>
struct materials {
	char name[51];
	int amount;
	int price;
};
struct materials savemat[100];
int main(int argc, char const *argv[])
{
	int n,m,q,am,prof,maxprof=0,maxamount,pr,prplusprof;
	char current[51];
	char max[51];
	char matcmp[51];
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%s %d %d",&savemat[i].name,&savemat[i].amount,&savemat[i].price);
	for (int i=0;i<m;i++) {
		prof = 0;
		pr = 0;
		maxamount = 10001;
		scanf("%s %d",current,&q);
		for (int j=0;j<q;j++) {
			scanf("%s %d",matcmp,&am);
			for (int k=0;k<n;k++) {
				if (strcmp(matcmp,savemat[k].name)==0) {
					int tmp = savemat[k].amount/am;
					pr += am*savemat[k].price;
					if (tmp<maxamount)
						maxamount = tmp;
					break;
				}
			}
		}
		scanf("%d",&prplusprof);
		pr *= maxamount;
		prplusprof *= maxamount;
		prof = prplusprof - pr;
		if (prof>maxprof) {
			maxprof = prof;
			strcpy(max,current);
		}
		else if (prof == maxprof) {
			if (strcmp(max,current)>0)
				strcpy(max,current);
		}
	}
	printf("%s %d",max,maxprof);
	return 0;
}