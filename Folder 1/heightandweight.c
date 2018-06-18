#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct people {
	char name[65];
	int height;
	int weight;
	float BMI;
};
int cmp(const void *a, const void *b) {
	struct people *A = (struct people *)a;
	struct people *B = (struct people *)b;
	if (A->BMI>B->BMI)
		return 1;
	else if (A->BMI<B->BMI)
		return -1;
	else
		if (A->weight>B->weight)
			return 1;
		else if (A->weight<B->weight)
			return -1;
		else
			if (A->height>B->height)
				return 1;
			else if (A->height<B->height)
				return -1;
			else {
				int tmp = strcmp(A->name,B->name);
				if (tmp>0)
					return 1;
				else 
					return -1;
			}
}
struct people list[100001];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%s %d %d",&list[i].name,&list[i].height,&list[i].weight);
		float h = list[i].height;
		list[i].BMI = list[i].weight/((h/100)*(h/100));
	}
	qsort(list,n,sizeof(struct people),cmp);
	for (int i=0;i<n;i++)
		printf("%s %d %d\n", list[i].name,list[i].height,list[i].weight);
	return 0;
}