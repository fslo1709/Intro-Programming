#include <stdio.h>
int N,M,Q,res,T,weights[16][16],image[16][16];
int h() {
	int res=0;
	for (int i=0;i<M;i++)
		for (int j=0;j<M;j++)
			res+=image[i][j]*weights[i][j];
	return res;
}
void duplex() {
	for (int i=0;i<M;i++)
		for (int j=0;j<M;j++)
			if (image[i][j])
				weights[i][j]*=2;
}
void div() {
	for (int i=0;i<M;i++)
		for (int j=0;j<M;j++) 
			if (image[i][j]) {
				weights[i][j]/=2;
				if (weights[i][j]==0)
					weights[i][j]=1;
			}
}
int main(int argc, char const *argv[])
{
	int comp;
	for (int i=0;i<16;i++)
		for (int j=0;j<16;j++)
			weights[i][j]=1;
	scanf("%d %d",&N,&M);
	T=2*M*M;
	for (int i=0;i<N;i++) {
		scanf("%d",&res);
		for (int j=0;j<M;j++)
			for (int k=0;k<M;k++)
				scanf("%d",&image[j][k]);
		comp=h();
		if (comp<T){
			if (res) 
				duplex();
			else
				continue;
		}
		else {
			if (res)
				continue;
			else
				div();
		}
	}
	scanf("%d",&Q);
	for (int i=0;i<Q;i++) {
		for (int j=0;j<M;j++)
			for (int k=0;k<M;k++)
				scanf("%d",&image[j][k]);
		comp=h();
		if (comp<T)
			puts("0");
		else
			puts("1");
	}
	return 0;
}