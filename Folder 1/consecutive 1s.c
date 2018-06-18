#include <stdio.h>
void conv(int, char*);
void max(char*);
int main(void) {
	int num;
	char x[64];
	char *y;
	y=&x;
	for (int i=0;i<64;i++)
		x[i]='\0';
	while (1)
	{
		if (scanf("%d",&num)==EOF)
			break;
		conv(num,y);
		max(y);
	}
	return 0;
}
void conv(int num, char *y)
{
	int p=0;
	y=y+31;
	for (int i=32;i>0;i--)
	{
		p=num%2;
		num=num/2;
		*y=p+'0';
		y--;
	}
	y++;
	return;
}
void max(char *y)
{
	int count=0,m=0;
	for (int i=0;i<32;i++)
	{
		if (*(y+i)=='1')
			count++;
		else
			count=0;
		if (count>m)
			m=count;
	}
	printf("%d\n",m);
	return;
}
