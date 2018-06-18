#include <stdio.h>
#include <stdlib.h>
int n,x[9];
#define swap(a,b) {int c; c=a, a=b, b=c;}
int comp(const void *, const void *);
void permutate(int A[],int p)
{
	int B[9];
	for (int i=0;i<n;i++)
		B[i]=A[i];
	if (p==n-1)
	{
		for (int i=0;i<n;i++)
			printf("%d%c",B[i],i<(n-1) ? ' ' : '\n');
		return;
	}
	for (int i=p;i<n-1;i++)
		for (int j=i+1;j<n;j++)
		{
			if (B[i]>B[j])
				swap(B[i],B[j]);
		}
	for (int i=p;i<n;i++)
	{
		swap(B[i],B[p]);
		permutate(B,p+1);
		swap(B[i],B[p]);
	}
	return;
}
int main (void){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	qsort(x,n,sizeof(int),comp);
	permutate(x,0);
	return 0;
}
int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}