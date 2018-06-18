#include <stdio.h>
int main(void) {
	unsigned int a;
	int x,y,cx=0,cy=0;
	char p,q;
	scanf("%d %d %c %c",&x,&y,&p,&q);
	while (scanf("%u",&a)==1)
	{
		for (int i=31;i>=0;i--)
		{
			unsigned int t=1;
			t=t<<i;
			if (t&a)
				putchar(p);
			else
				putchar(q);
		//	printf("%d\n",1<<i);
			cx++;
			if (cx==x)
			{
				puts("");
				cx=0;
				cy++;
			}
			if (cy==y)
				break;
		}
		if (cy==y)
			break;
	}
	return 0;
}
