#include <stdio.h>
int main(int argc, char const *argv[])
{
	int k, digit, remainder=0, res=0, lead = 0, count = 1;
	scanf("%d",&k);
	while (scanf("%d",&digit)!=EOF) {
		if (lead) {
			remainder += digit;
			printf("%d\n",remainder/k);
			count = 0;
			remainder = (remainder%k)*10;
		}
		else {
			if (digit >= k) {
				printf("%d\n",digit/k);
				count = 0;
				remainder = (digit%k)*10;
			}
			else
				remainder = digit*10;
			lead = 1;
		}
	}
	if (count)
		puts("0");
	return 0;
}