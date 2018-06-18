#include <stdio.h>
int main(void) {
	int y,m,f,l,da,d=0;
	scanf("%d %d %d",&y,&m,&f);
	if (((y%4==0)&&(y%100!=0))||(y%400==0))
		l=1;
	if (m==2)
		da=28+l;
	if ((m==4)||(m==6)||(m==9)||(m=11))
		da=31;
	else
		da=30;
	if ((m<1)||(m>12)||(f<0)||(f>6)||(y<1000)||(y>3000))
		printf("invalid\n");
	else
	{
		printf(" Su Mo Tu We Th Fr Sa\n");
		printf("=====================\n");
		d=1;
		while (1==1)
		{
			for (int j=0;j<7;j++)
				{
					if (d==(da))
						break;
					if (d==1)
					{
						for (int k=0;k<f;k++)
						{	
							printf(" ");
							printf(" ");
							printf(" ");
						}
					}
					printf("%3d",d);	
					d++;
					if(d==(8-f))
						break;
				}
			printf("\n");
			if (da==d)
				break;
		}
	}
	printf("=====================\n");
	return 0;
}
