#include <stdio.h>
int main(void) {
	int n,p,o1,e1;
	int od[1000];
	int ev[1000];
	o1=0;
	e1=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&p);
		if (p%2)
		{
			od[o1]=p;
			o1++;
		}
		else
		{
			ev[e1]=p;
			e1++;
		}
	}
	for (int i=0;i<o1;i++)
	{
		printf("%d",od[i]);
		if (i<o1-1)
			printf(" ");
	}
	printf("\n");
	for (int i=0;i<e1;i++)
	{
		printf("%d",ev[i]);
		if (i<e1-1)
			printf(" ");
	}
	return 0;
}
