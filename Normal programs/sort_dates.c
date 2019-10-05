#include <stdio.h>
#include <stdlib.h>
#define SZ 65536
typedef struct {
	int year;
	int day;
	int month;
}date;

date alldates[1000000];

int cmp(const void* a, const void* b) {
	date* A = (date *)a;
	date* B = (date *)b;
	if (A->year == B->year) {
		if (A->month == B->month) {
			return A->day - B->day;
		}
		else
			return A->month - B->month;
	}
	else 
		return A->year - B->year;
}
int readChar(void) {
    static char buf[SZ];
    static char *p = buf, *end = buf;
    if (p == end) {
      if ((end = buf + fread(buf, 1, SZ, stdin)) == buf) return EOF; 
      p = buf;
    }
    return *p++;
}
int ReadInt(void) {
    static int x;
    static char c;
    static char neg;
    while((c = readChar()) < '-')    {if (c == EOF) return EOF;}
    neg = (c == '-') ? -1 : 1;
    x = (neg == 1) ? c - '0' : 0;
    while((c = readChar()) >= '0')
        x = (x << 3) + (x << 1) + (c - '0');
    x *= neg;
    return x;
}

int main(int argc, char const *argv[])
{
	int N;
	N = ReadInt();
	for (int i = 0; i < N; i++) {
		alldates[i].year = ReadInt();
		alldates[i].month = ReadInt();
		alldates[i].day = ReadInt();
	}
	qsort(alldates, N, sizeof(date), cmp);
	for (int i = 0; i < N; i++)
		printf("%d %d %d\n", alldates[i].year, alldates[i].month, alldates[i].day);
	return 0;
}