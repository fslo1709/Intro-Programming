#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[18];
	int H;
}scholar;

scholar all[20005];

int cmp(const void *a, const void *b) {
	scholar *A = (scholar *)a;
	scholar *B = (scholar *)b;
	int x = strcmp(A->name, B->name);
	if (x)
		return x;
	else
		return (B->H - A->H);
}

int main(int argc, char const *argv[]) {
	int i = 0;
	while (scanf("%s %d", all[i].name, &all[i].H) != EOF)
		i++;
	qsort(all, i, sizeof(scholar), cmp);
	int j = 0;
	char temp[18];
	strcpy(temp, all[0].name);
	int H = 0, flag = 0;
	while (j < i) {
		if (strcmp(temp, all[j].name) != 0) {
			if (flag == 0)
				printf("%s %d\n", temp, H);
			H = 0, flag = 0;
			strcpy(temp, all[j].name);
		}
		if (flag == 0) {
			if (H + 1 <= all[j].H)
				H++;
			else {
				printf("%s %d\n", temp, H);
				flag = 1;
			}
		}
		j++;
	}
	if (flag == 0)
		printf("%s %d\n", temp, H);
	return 0;
}