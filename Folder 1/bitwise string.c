#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int twopow(int);
int main (void){
	char s[32];
	int n,let,t=4,p=0;
	scanf("%s",s);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&let);
		for (int j=31;j>=0;j--)
		{
			p+= (let&(1<<j)) ? twopow(t) : 0;
			t--;
			if (t==-1)
			{
				printf("%c",s[p]);
				t=4, p=0;
			}
		}
	}
}
int twopow(int k)
{
	int r= 1;
	for (int i=0;i<k;i++)
		r=r*2;
	return r;
}
