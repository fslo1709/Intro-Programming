#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int k;
	char fname[21];
	char outname[21];
	char words[20][4];
	FILE *filespt[20];
	FILE *fout;
	int counters[20];
	int sizes[20];
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%s", fname);
		filespt[i] = fopen(fname, "r");
		counters[i] = 0;
		fseek(filespt[i], 0, SEEK_END);
		sizes[i] = ftell(filespt[i])/3;
		fseek(filespt[i], 0, SEEK_SET);
		fread(&words[i], 1, 3, filespt[i]);
		words[i][3] = '\0';
	}
	scanf("%s", outname);
	fout = fopen(outname, "wa");
	int nfinished = k;
	while (nfinished > 0) {
		char max[4];
		int flag = 0, maxid = 0;
		for (int i = 0; i < k; i++) {
			if (counters[i] < sizes[i]) {
				if (flag == 0) {
					strcpy(max, words[i]);
					maxid = i;
					flag = 1;
				}
				else if (strcmp(max, words[i]) > 0) {
					strcpy(max, words[i]);
					maxid = i;
				}
			}
		}
		counters[maxid]++;
		if (counters[maxid] == sizes[maxid])
			nfinished--;
		else {
			fread(&words[maxid], 1, 3, filespt[maxid]);
			words[maxid][3] = '\0';
		}
		fwrite(&max, 1, 3, fout);
	}
	for (int i = 0; i < k; i++)
		fclose(filespt[i]);
	fclose(fout);
	return 0;
}