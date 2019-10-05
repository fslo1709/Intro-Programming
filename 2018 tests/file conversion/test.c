#include <stdio.h>
int main(int argc, char const *argv[])
{
	unsigned char x = 2;
	char fname[32];
	scanf("%s", fname);
	FILE* fout = fopen(fname, "wb");
	fwrite(&x, 1, 1, fout);
	fclose(fout);
	return 0;
}