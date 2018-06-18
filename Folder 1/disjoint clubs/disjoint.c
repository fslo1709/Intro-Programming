#include <stdio.h>
#include <stdlib.h>
int n,k;
unsigned long long int clubs[101]={};
int indexes[101]={};
void check(int pos, int nk, unsigned long long int comp)
{
    if (nk+(n-pos)<k)
        return;
	if (nk==k)
	{
		for (int i=0;i<k;i++)
		{
			printf("%d\n",indexes[i]);
		}
		exit(0);
	}
	if (comp&clubs[pos]==0)
	{
		indexes[nk]=pos;
		check(pos+1,nk+1,comp|clubs[pos]);
	}
    check(pos+1,nk,comp);
    return;
}
int main(void) {
    int m,i,j;
    int p;
    scanf("%d %d",&n,&k);
    for (i=0;i<n;i++)
    {
		unsigned long long int temp=0;
        scanf("%d",&m);
        for (j=0;j<m;j++)
        {
			unsigned long long int temp2=1;
            scanf("%d",&p);
            for (int l=0;l<p;l++)
				temp2<<=l;
            temp=temp2|clubs[i];
        }
		clubs[i]= temp;
    }
    check(0,0,0);
    return 0;
}