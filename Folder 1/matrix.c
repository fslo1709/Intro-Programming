#include <stdio.h>
int main(void) {
	int n,j;
	double x[16][16];
	double y[16];
	double res[16];
	for (int i=0;i<16;i++)
		res[i]=1;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%lf",&x[i][j]);
	for (int i=0;i<n;i++)
	{
		scanf("%lf",&y[i]);
	}
	for (int i=n-1;i>=0;i--)
	{
		double d=0.0;
		for (j=i+1;j<n;j++)
			d+=(-1.0)*res[j]*x[i][j];
		res[i]=(y[i]+d)/x[i][i];
	}
	for (int i=0;i<n;i++)
		printf("%.6lf\n",res[i]);
	return 0;
}
