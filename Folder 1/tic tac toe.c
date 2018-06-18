#include <stdio.h>
int main(void) {
	int n,cx,cy,turn,color,i,r;
	int tt[3][3];
	turn=0;
	color=1;
	r=0;
	for (i=0;i<3;i++)
		for (int j=0;j<3;j++)
			tt[i][j]=0;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&cx,&cy);
		if (((cx>=0)&&(cx<=2))&&((cy>=0)&&(cy<=2)))
		{
			if (tt[cx][cy]>0)
			{
				tt[cx][cy]=color;
				turn++;
				color=turn%2+1;
			}
			else	
				continue;
		}
		else
			continue;	
		if (turn>4)
		{
			if ((tt[cx][0]==tt[cx][1])&&(tt[cx][0]==tt[cx][2]))
			{
				r++;
				break;
			}
			if ((tt[0][cy]==tt[1][cy])&&(tt[0][cy]==tt[2][cy]))
			{
				r++;
				break;
			}
			if (cx==cy)
			{
				if ((tt[0][0]==tt[1][1])&&(tt[0][0]==tt[2][2]))
				{
					r++;
					break;
				}
				if ((tt[0][2]==tt[1][1])&&(tt[0][0]==tt[2][0]))
				{
					r++;
					break;
				}
			}
		}
	}
	if (r!=0)
	{
		if (color==1)
			printf("White wins.");
		else
			printf("Black wins.");
	}
	else
		printf("There is a draw.");
}
