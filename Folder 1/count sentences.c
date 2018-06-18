#include <stdio.h>
#include <string.h>
char p[1<<20]={};
int main(void) {
	fread (p,1,1<<20,stdin);
	int t=0;
	for (int i=0;p[i];i++)
	{
		if (p[i]=='.')
		{
			if (p[i+1]==' ' && p[i+2]==' ')
				t++;
			else
			if (p[i+1]=='\n' || p[i+1]=='\0')
				t++;
		}
	}
	printf("%d", t);
	return 0;
}
