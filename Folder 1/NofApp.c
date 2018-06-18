#include <stdio.h>
int main(void) {
	char n1[2]={};
	char n2[7]={};
	int i,c=0;
	scanf("%s %s",&n1,&n2);
	for (i=0;i<6;i++)
		if ((n1[0]==n2[i])&&(n1[1]==n2[i+1]))
			c++;
	printf("%d",c);
	return 0;
}
