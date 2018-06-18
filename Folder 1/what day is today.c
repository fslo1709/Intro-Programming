#include <stdio.h>
int main(void) {
	int i,year,wkd,n=0;
	int m,d,leap=0;
	scanf("%d %d",&year,&wkd);
	scanf("%d",&n);
	if (((year%4==0)&&(year%100!=0))||(year%400==0))
		leap=1;
	for (i=0;i<n;i++)
	{
		int r=-3;
		scanf("%d %d",&m,&d);
		switch(m)
		{
			case 1:	r=(wkd+(d-1)%7)%7;
				break;
			case 2:	if (d<=(28+leap))
					r=(wkd+(d+30)%7)%7;
				break;
			case 3:	r=(wkd+(d+58+leap)%7)%7;
				break;
			case 4:	if (d<=30)
					r=(wkd+(d+89+leap)%7)%7;
				break;
			case 5:	r=(wkd+(d+119+leap)%7)%7;
				break;
			case 6:	if (d<=30)
					r=(wkd+(d+150+leap)%7)%7;
				break;
			case 7:	r=(wkd+(d+180+leap)%7)%7;
				break;
			case 8:	r=(wkd+(d+211+leap)%7)%7;
				break;
			case 9:	if (d<=30)
					r=(wkd+(d+242+leap)%7)%7;
				break;
			case 10:	r=(wkd+(d+272+leap)%7)%7;
				break;
			case 11:	if (d<=30)
					r=(wkd+(d+303+leap)%7)%7;
				break;
			case 12:	r=(wkd+(d+333+leap)%7)%7;
				break;
			default:	r=-1;
				break;
		}
		if ((m<1)||(m>12))
		{	r=-1;}
		else
		{
		if ((d>31)||(d<1)||(r==-3))
			r=-2;
		}
		printf("%d\n",r);
	}
	return 0;
}
