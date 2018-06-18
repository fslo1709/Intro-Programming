#include "count.h"
#include "stdio.h"
#include "stdlib.h"
typedef struct pointerwval
{
	int* point;
	int numb;
	int quan;
}pointerwval;
int cmp(const void* A, const void* B) {
	pointerwval* a= (pointerwval *)A;
	pointerwval* b= (pointerwval *)B;
	if (a->quan>b->quan)
		return 1;
	else
		if (a->quan==b->quan)
			if (a->numb>b->numb)
				return 1;
			else
				return -1;
		else
			return -1;
	return 0;
}
void count(int **p[]) {
	pointerwval elements[512];
	int x=-1,y=0;
	while (p[++x]!=NULL) {
		int flag=0;
		for (int i=0;i<y;i++) 
			if (elements[i].point==*p[x]) {
				flag=1;
				elements[i].quan++;
				break;
			}
		if (flag==0) {
			elements[y].point=*p[x];
			elements[y].numb=**p[x];
			elements[y++].quan=1;
		}
	}
	qsort(&elements[0],y,sizeof(pointerwval),cmp);
	for (int i=0;i<y;i++)
		printf("%d %d\n",elements[i].numb,elements[i].quan);
}