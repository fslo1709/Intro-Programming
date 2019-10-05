#include <stdio.h>

int main(int argc, char const *argv[]) {
	char fn1[33], fn2[33], fout[33];
	scanf("%s %s %s", fn1, fn2, fout);
	FILE *f1 = fopen(fn1, "rb");
	FILE *f2 = fopen(fn2, "rb");
	FILE *fo = fopen(fout, "wb");
	fseek(f1, 0, SEEK_END);
	fseek(f2, 0, SEEK_END);
	long long int size1 = ftell(f1), size2 = ftell(f2);
	if (size2 > size1) {
		int tmp1 = size2;
		size2 = size1;
		size1 = tmp1;
		FILE* tmp2 = f2;
		f2 = f1;
		f1 = tmp2;
	}
	int carry = 0, sum = 0;
	unsigned char s1, s2;
	for (int i = 0; i < size1; i++) {
		s1 = s2 = 0;
		fseek(f1, size1 - i - 1, SEEK_SET);
		fread(&s1, sizeof(unsigned char), 1, f1);
		if (i < size2) {
			fseek(f2, size2 - i - 1, SEEK_SET);
			fread(&s2, sizeof(unsigned char), 1, f2);
		}
		sum = carry + s1 + s2;
		carry = (sum > 255) ? 1: 0;
		fseek(fo, size1 - i - 1, SEEK_SET);
		fwrite(&sum, sizeof(unsigned char), 1, fo);
	}
	fclose(f1);
	fclose(f2);
	fclose(fo);
	return 0;
}