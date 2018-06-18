#include <stdio.h>
int gcd(int x, int y)
{
	int t;
	while (x%y)
		t=x, x=y, y=t%y;
	return y;
}
void add (int x[3], int y[3])
{
	int a1=x[0]*x[2]+(x[0]<0 ? -x[1] : x[1]), b1=x[2];
	int a2=y[0]*y[2]+(y[0]<0 ? -y[1] : y[1]), b2=y[2];
	int a3=a1*b2+a2*b1, b3=b1*b2;
	int g=gcd(a3,b3);
	a3/=g; b3/=g;
	printf("%d\n%d\n%d\n",a3/b3,abs(a3)%b3,b3);
}
void sub (int x[3], int y[3])
{
	int a1=x[0]*x[2]+(x[0]<0 ? -x[1] : x[1]), b1=x[2];
	int a2=y[0]*y[2]+(y[0]<0 ? -y[1] : y[1]), b2=y[2];
	int a3=a1*b2-a2*b1, b3=b1*b2;
	int g=gcd(a3,b3);
	a3/=g; b3/=g;
	printf("%d\n%d\n%d\n",a3/b3,abs(a3)%b3,b3);
}
void mul (int x[3], int y[3])
{
	int a1=x[0]*x[2]+(x[0]<0 ? -x[1] : x[1]), b1=x[2];
	int a2=y[0]*y[2]+(y[0]<0 ? -y[1] : y[1]), b2=y[2];
	int a3=a1*a2, b3=b1*b2;
	int g=gcd(a3,b3);
	a3/=g; b3/=g;
	printf("%d\n%d\n%d\n",a3/b3,abs(a3)%b3,b3);
}
void divis (int x[3], int y[3])
{
	int a1=x[0]*x[2]+(x[0]<0 ? -x[1] : x[1]), b1=x[2];
	int a2=y[0]*y[2]+(y[0]<0 ? -y[1] : y[1]), b2=y[2];
	int a3=a1*b2, b3=b1*a2;
	int g=gcd(a3,b3);
	a3/=g; b3/=g;
	if (b3<0)	a3=-b3,b3=-b3;
	printf("%d\n%d\n%d\n",a3/b3,abs(a3)%b3,b3);
}
int main(void) {
	int x[3],y[3];
	int o=0;
	scanf("%d %d %d", x[0],x[1],x[2]);
	scanf("%d",&o);
	scanf("%d %d %d", y[0],y[1],y[2]);
	switch (o)
	{
		case 0: add(x,y); break;
		case 1: sub(x,y); break;
		case 2: mul(x,y); break;
		case 3: divis(x,y); break;
	}
	return 0;
}
