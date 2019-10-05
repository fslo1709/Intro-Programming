#include "compute.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int count;
	int citations;
	char journalName[64];
} tablepaper;
tablepaper tabla[1026];
int references[1026];
int cmp (const void* A, const void *B) {
	tablepaper *a = (tablepaper*)A;
	tablepaper *b = (tablepaper*)B;
	return strcmp(a->journalName, b->journalName);
}
void compute(paper P[], int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int flag = -1;
		for (int j = 0; j < cnt; j++) {
			if (strcmp(tabla[j].journalName,P[i].journalName) == 0) {
				flag = j;
				break;
			}
		}
		if (flag < 0) {
			tabla[cnt].count = 1;
			strcpy(tabla[cnt].journalName,P[i].journalName);
			references[i] = cnt;
			cnt++;
		}
		else {
			tabla[flag].count++;
			references[i] = flag;
		}
	}	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P[i].numCitedPaper; j++) {
			tabla[references[P[i].citedPaperIndex[j]]].citations++;
		}
	}
	qsort(tabla, cnt, sizeof(tablepaper), cmp);
	for (int i = 0; i < cnt; i++)
		printf("%s %d/%d\n",tabla[i].journalName,tabla[i].citations,tabla[i].count);
}