#include <stdio.h>
#include <stdlib.h>
int n,c;
unsigned int countries[20];

int main (void)
{
	int p;
	scanf("%d%d%d",&n,&c,&p);
	for (int i=0;i<p;i++)
	{
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		countries[c1]|=1u<<c2;
		countries[c2]|=1u<<c1;
	}
}