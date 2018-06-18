#include <stdio.h>
#include <string.h>
int main(void) {
	char n[1000]={};
	int sum,t[2];
	while ((scanf("%s",n))&&(n[0]!='-'))
	{
		int k = strlen(n);
		sum=0;
		t[0]=0,t[1]=0;
		for (int i=0;i<k;i++)
		{
			sum+=n[i]-'0';
			t[i%2]+=n[i]-'0';
		}
		if ((n[k-1]-'0')%2==0)
			printf("yes ");
		else
			printf("no ");
		if (sum%3==0)
			printf("yes ");
		else
			printf("no ");
		if ((n[k-1]-'0')%5==0)
			printf("yes ");
		else
			printf("no ");
		if ((t[0]-t[1])%11==0)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
