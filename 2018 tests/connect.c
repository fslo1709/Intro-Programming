#include <stdio.h>
int main(int argc, char const *argv[])
{
	int cur, temp, len = 0, curlen = 1, last;
	scanf("%d",&cur);
	temp = cur;
	last = temp%10;
	while (temp>=10) {
		temp /= 10;
		curlen++;
	}
	len = curlen;
	while (scanf("%d",&cur)!=EOF) {
		int templen = 1;
		temp = cur;
		while (temp>=10) {
			temp /= 10;
			templen++;
		}
		if (temp == last) {
			curlen += templen;
			if (curlen > len)
				len = curlen;
		}
		else {
			curlen = templen;
			if (curlen > len)
				len = curlen;
		}
		last = cur%10;
	}
	printf("%d\n",len);
	return 0;
}