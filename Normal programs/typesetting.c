#include <stdio.h>
#include <string.h>

char w[257];
char buf[257];
int spaces[257][2];

int main(int argc, char const *argv[])
{
	int linelen, curlen = 0;
	scanf("%d", &linelen);
	while (scanf("%s", w) != EOF) {
		int templen = strlen(w);
		if (curlen + 1 + templen <= linelen) {
			if (curlen > 0) {
				strcat(buf, " ");
			}
			strcat(buf, w);
		}
		else {
			int addspace = linelen - curlen;
			int index = 0;
			for (int i = 0; i < curlen; i++) {
				if (buf[i] == ' ') {
					spaces[index][0] = i;
					spaces[index++][1] = 0;
				}
			}
			while (addspace > 0) {
				for (int i = 0; i < index; i++) {
					if (addspace == 0)
						break;
					spaces[i][1]++;
					addspace--;
				}
			}
			int secbufcount = 0, id = 0;
			char secbuf[257];
			for (int i = 0; i < curlen; i++) {
				if (buf[i] == ' ') {
					for (int j = 0; j < spaces[id][1]; j++) 
						secbuf[secbufcount++] = ' ';
					id++;
				}
				secbuf[secbufcount++] = buf[i];
			}	
			printf("%s\n", secbuf);
			strcpy(buf, w);
		}
		curlen = strlen(buf);
	}
	int addspace = linelen - curlen;
	int index = 0;
	for (int i = 0; i < curlen; i++) {
		if (buf[i] == ' ') {
			spaces[index][0] = i;
			spaces[index++][1] = 0;
		}
	}
	while (addspace > 0) {
		for (int i = 0; i < index; i++) {
			if (addspace == 0)
				break;
			spaces[i][1]++;
			addspace--;
		}
	}
	int secbufcount = 0, id = 0;
	char secbuf[257];
	for (int i = 0; i < curlen; i++) {
		if (buf[i] == ' ') {
			for (int j = 0; j < spaces[id][1]; j++) 
				secbuf[secbufcount++] = ' ';
			id++;
		}
		secbuf[secbufcount++] = buf[i];
	}
	secbuf[secbufcount] = '\0';
	printf("%s\n", secbuf);
	return 0;
}
