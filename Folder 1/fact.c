#include <stdio.h>
#include <stdlib.h>
#define swap(x, y) {int z; z=y; y=x; x=z;}
int main(void) {
	int p[3],r[3];
	scanf("%d %d %d",&p[0],&p[1],&p[2]);
	int t,m,posit,sign=0;
	r[0]=0;
	r[1]=0;
	r[2]=0;
	if ((abs(p[0])/p[0])==-1)
		if ((abs(p[1])/p[1])==-1)
			if ((abs(p[2])/p[2])==-1)
				posit=2;
			else
				posit=1;
		else
			if ((abs(p[2])/p[2])==-1)
				posit=0;
			else
				posit=1;
	else
		if ((abs(p[1])/p[1])==-1)
			if ((abs(p[2])/p[2])==-1)
				posit=2;
			else
				posit=1;
		else
			if ((abs(p[2])/p[2])==-1)
				posit=2;
			else
				posit=3;
	for (int i=0;i<3;i++)
	{
		if (i>=posit)
			sign=1;	
		for (int j=1;j*j<=abs(p[2]);j++)
		{
			if ((j==r[0])||(j==r[1])||(j==r[2]))
				continue;
			t=j;
			if (sign==0)
				t=t*(-1);
			m=(t*t*t)+(p[0]*t*t)+(p[1]*t)+p[2];
			if (m==0)
			{
				if (sign==1)
					r[i]=-j;
				else
					r[i]=j;
				break;
			}
		}
	}
	if (r[0]>r[1]) swap(r[0],r[1]);
	if (r[0]>r[2]) swap(r[0],r[2]);
	if (r[1]>r[2]) swap(r[1],r[2]);
	printf("%d %d %d", r[0],r[1],r[2]);
	return 0;
}
