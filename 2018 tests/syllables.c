#include <stdio.h>
#include <string.h>

char buf[10200];
char wbuf[10200];
char printbuf[30200];

int main(int argc, char const *argv[])
{
	int i, j;
	while (fgets(buf, 10200, stdin) != NULL) {
		sscanf(buf, "%s %d %d", &wbuf[0], &i, &j);
		int begi = 0, begj = 0, endi = 0, endj = 0, count = 0, k = 0, len = strlen(wbuf);
		while (i + j != -2 && k < len) {
			if (wbuf[k] == 'a' || wbuf[k] == 'e' || wbuf[k] == 'i' || wbuf[k] == 'o' || wbuf[k] == 'u') {
				if (count == i-1)	begi = k+1;
				if (count == j-1)	begj = k+1;
				if (count == i) 	endi = k, i = -1;
				if (count == j)		endj = k, j = -1;
				count++;
			}
			k++;
		}
		for (k = 0; k < len; k++) {
			printbuf[k] = (k >= begi && k <= endi) ? wbuf[k]: '+';
			printbuf[k+len+1] = (k >= begj && k <= endj) ? wbuf[k]: '+';
			printbuf[k+2*len+2] = ((k >= begi && k <= endi) || (k >= begj && k <= endj)) ? '+': wbuf[k];
		}
		printbuf[k] = printbuf[k+len+1] = '\n';
		printbuf[k+2*len+2] = '\0';
		puts(printbuf);
	}
	return 0;
}