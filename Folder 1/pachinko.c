#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	long long a,b;
} Fr;
long long cd(long long t, long long u){
	int v;
	while (t%u)	v=t,t=u,u=v%u;
	return u;
}
Fr add(Fr t, Fr u){
	long long a,b,k;
	Fr z;
	a=t.a*u.b+u.a*t.b, b=t.b*u.b;
	k=cd(a,b), a/=k, b/=k;
	z.a=a, z.b=b;
	return z;
}
Fr sub(Fr t, Fr u){
	long long a,b,k;
	Fr z;
	a=t.a*u.b-u.a*t.b, b=t.b*u.b;
	k=cd(a,b), a/=k, b/=k;
	z.a=a, z.b=b;
	return z;
}
Fr mul(Fr t, Fr u){
	long long a,b,k;
	Fr z;
	a=t.a*u.a, b=t.b*u.b;
	k=cd(a,b);
	a/=k, b/=k, z.a=a, z.b=b;
	return z;
}
int main() {
	int n;
	long long a,b;
	scanf("%d",&n);
	Fr g[128][128],fz,fo;
	fz.a=0, fz.b=1;
	fo.a=1, fo.b=1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=i;j++)		
		{
			scanf("%d %d",&a,&b);
			b=a+b;
			long long t = cd(a,b);
			a/=t, b/=t;
			g[i][j].a=a, g[i][j].b=b;
		}
	}
	Fr dp[128][128];
	for (int i=0; i<128;i++)
		for (int j=0; j<128; j++)
			dp[i][j]=fz;
	dp[0][0] = fo;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			dp[i+1][j]= add(dp[i+1][j],mul(dp[i][j],g[i][j]));
			dp[i+1][j+1]= add(dp[i+1][j+1],mul(dp[i][j],sub(fo,g[i][j])));
		}
	}
	for (int i=0;i<=n;i++)
		printf("%lld/%lld\n",dp[n][i].a,dp[n][i].b);
    return 0;
}
