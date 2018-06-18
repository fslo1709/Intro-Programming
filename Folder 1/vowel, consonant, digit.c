#include <stdio.h>
#include <string.h>
int main(void) {
	char p;
	int x[4]={};
	while (scanf("%c",&p)!=EOF)
	{
		p=tolower(p);
		if (p>='0' && p<='9')
			x[0]++;
		if (p>='a' && p<='z')
		{
			x[1]++;
			if (p=='a' || p=='e' || p=='i' || p=='o' || p=='u')
				x[2]++;
			else
				x[3]++;
		}
	}
	printf("%d %d %d %d",x[0],x[1],x[2],x[3]);
	return 0;
}
