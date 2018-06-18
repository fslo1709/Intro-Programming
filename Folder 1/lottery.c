#include <stdio.h>

int main(void) {
	int sp1,sp2,sp3=0;
	int fp1,fp2,fp3=0;
	int prize=0;
	scanf("%d",&sp1);
	scanf("%d",&sp2);
	scanf("%d",&sp3);
	scanf("%d",&fp1);
	scanf("%d",&fp2);
	scanf("%d",&fp3);
	while (1==1)
	{
		int nu,p1,p2,p3=0;
		p1=fp1-(fp1/10000000)*10000000;
		p2=fp2-(fp2/10000000)*10000000;
		p3=fp3-(fp3/10000000)*10000000;
		if ((scanf("%d",&nu))!=1)
			break;
		if ((sp1==nu)||(sp2==nu)||(sp3==nu))
			prize=prize+2000000;
		if ((fp1==nu)||(fp2==nu)||(fp3==nu))
			prize=prize+200000;
		else
		{
		nu=nu-(nu/10000000)*10000000;
		if (p1==nu)
			prize=prize+40000;
		else
		if (p2==nu)
			prize=prize+40000;
		else
		if (p3==nu)
			prize=prize+40000;
		else
		{
		p1=p1-(p1/1000000)*1000000;
		p2=p2-(p2/1000000)*1000000;
		p3=p3-(p3/1000000)*1000000;
		nu=nu-(nu/1000000)*1000000;
		if (p1==nu)
			prize=prize+10000;
		else
		if (p2==nu)
			prize=prize+10000;
		else
		if (p3==nu)
			prize=prize+10000;
		else
		{
		p1=p1-(p1/100000)*100000;
		p2=p2-(p2/100000)*100000;
		p3=p3-(p3/100000)*100000;
		nu=nu-(nu/100000)*100000;
		if (p1==nu)
			prize=prize+4000;
		else
		if (p2==nu)
			prize=prize+4000;
		else
		if (p3==nu)
			prize=prize+4000;
		else
		{
		p1=p1-(p1/10000)*10000;
		p2=p2-(p2/10000)*10000;
		p3=p3-(p3/10000)*10000;
		nu=nu-(nu/10000)*10000;
		if (p1==nu)
			prize=prize+1000;
		else
		if (p2==nu)
			prize=prize+1000;
		else
		if (p3==nu)
			prize=prize+1000;
		else
		{
		p1=p1-(p1/1000)*1000;
		p2=p2-(p2/1000)*1000;
		p3=p3-(p3/1000)*1000;
		nu=nu-(nu/1000)*1000;
		if (p1==nu)
			prize=prize+200;
		else
		if (p2==nu)
			prize=prize+200;
		else
		if (p3==nu)
			prize=prize+200;
		}
		}
		}
		}
		}
	}
	printf("%d",prize);
	return 0;
}
