#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,m,r,w,c1,c2;
	scanf("%d %d %d",&n,&m,&r);
	if (r==0) {
		while (scanf("%d",&w)!=EOF) {
			if (n-w>=0) 
				n-=w;
			else
				if (m-w>=0)
					m-=w;
			printf("%d %d\n",n,m);
		}
	}
	else
	{	
		while (scanf("%d",&w)!=EOF) {
			if (m-w>=0) {
				if ((n-w)<=(m-w) && (n-w>=0))
					n-=w;
				else
					m-=w;
			}
			else
				if (n-w>=0)
					n-=w;
			printf("%d %d\n",n,m);
		}
	}
	return 0;
}