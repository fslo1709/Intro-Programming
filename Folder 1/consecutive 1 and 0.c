#include <stdio.h>
struct numbin{
	char t[32];
	char last;
};
char printnum (int, int*, char);
int main(void) {
	int n,x,t;
	int* es;
	char k;
	es=&t;
	t=0;
	scanf("%d",&n);
	k='2';
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		k=printnum(x,es,k);
	}
	return 0;
}
char printnum(int x, int* es, char k)
{
	struct numbin y;
	for (int i=0;i<32;i++)
	{
		int z=x%2;
		x/=2;
		y.t[31-i]=z+'0';
	}
	for (int i=0;i<32;i++)
	{
		if (y.t[i]!=k && k!='2' && i==0)
		{
			if (y.t[i]!=y.t[i-1])
			{
				printf("\n");
				for (int j=0;j<(*es)%40;j++)
					printf(" ");
			}
		}
		if (y.t[i]!=y.t[i-1] && i>0)
		{
			printf("\n");
			for (int j=0;j<(*es)%40;j++)
				printf(" ");
		}
		printf("%c",y.t[i]);
		(*es)++;
	}
	return y.t[31];
}
