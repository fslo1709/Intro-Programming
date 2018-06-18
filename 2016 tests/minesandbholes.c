#include <stdio.h>
int dist(int px,int py,int pz,int qx,int qy,int qz) {
	int rx,ry,rz,x;
	if (px>qx)
		rx=px-qx;
	else
		rx=qx-px;
	if (py>qy)
		ry=py-qy;
	else
		ry=qy-py;
	if (pz>qz)
		rz=pz-qz;
	else
		rz=qz-pz;
	x=rx+ry+rz;
	return x;
}
int main(int argc, char const *argv[])
{
	int space[3],mine[3],bh[3];
	int dx[7]={0,1,-1,0,0,0,0};
	int dy[7]={0,0,0,1,-1,0,0};
	int dz[7]={0,0,0,0,0,1,-1};
	int N,inst,flag=0,bhdist;
	scanf("%d %d %d %d %d %d %d %d %d %d",&space[0],&space[1],&space[2],&mine[0],&mine[1],&mine[2],&bh[0],&bh[1],&bh[2],&N);
	for (int i=1;i<=N;i++) {
		scanf("%d",&inst);
		space[0]+=dx[inst];
		space[1]+=dy[inst];
		space[2]+=dz[inst];
		int minedist=dist(space[0],space[1],space[2],mine[0],mine[1],mine[2]);
		if (flag==0)
			bhdist=dist(space[0],space[1],space[2],bh[0],bh[1],bh[2]);
		else
			bhdist=11;
		if (minedist<10)
			break;
		if (bhdist<10) {
			for (int j=0;j<3;j++)
				space[j]=bh[j];
			flag=1;
		}
		if (i%5==0)
			printf("%d %d %d\n",space[0],space[1],space[2]);
	}
	return 0;
}