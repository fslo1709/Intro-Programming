#include <stdio.h>
#include <string.h>

char buf[100000];

void task1(void) {
	scanf("%s", buf);
	int count = 0;
	unsigned long long int ans = 0;
	unsigned char comp = 1;
	comp<<=7;
	for (int i = 0; i < strlen(buf); i++) {
		unsigned char temp = buf[i];
		if (count == 8) {
			printf("%llu\n", ans);
			ans = 0, count = 0;
		}
		for (int i = 0; i < 8; i++) {
			ans<<=1;
			if (comp & temp)
				ans |= 1;
			temp<<=1;
		}
		count++;
	}
	if (count == 8) {
		printf("%llu\n", ans);
		printf("0\n");
	}
	else {
		while (count < 8) {
			ans<<=8;
			count++;
		}
		printf("%llu\n", ans);
	}
}

unsigned long long int nums[12500];
char answer[12500*8+1];

void task2(void) {
	int N, count = 0;
	unsigned long long int comp = 1u;
	comp<<=63;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%llu", &nums[i]);
		for (int j = 0; j < 8; j++) {
			unsigned char temp = 0;
			for (int k = 0; k < 8; k++) {
				temp<<=1;
				if (nums[i] & comp)
					temp |= 1;
				nums[i]<<=1;
			}
			if (temp == 0) {
				answer[count] = '\0';
				return;
			}
			answer[count++] = temp;
		}
	}
	answer[count] = '\0';
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	if (T) {
		task2();
		printf("%s\n", answer);
	}
	else
		task1();
	return 0;
}