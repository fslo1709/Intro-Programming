#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n=10;
	int num[100]={6,3,3,3,5,7,2,8};
	int i=0;
	while (i<n) {
		int j=i;
		while (j>0 && num[j-1]>num[j]) {
			int x=num[j-1];
			num[j-1]=num[j];
			num[j]=x;
			j--;
		}
		i++;
	}
	for (int k=0;k<n;k++)
		printf("%d ",num[k]);
	return 0;
}