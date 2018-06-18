#include <stdio.h>
#include <string.h>
int main(void) {
	char w[128]={};
	char abb[128]={};
	int pos=0;
	while (scanf("%s",&w)!=EOF)
	{
		int t=strlen(w);
		for (int i=0;i<t;i++)
			w[i]=tolower(w[i]);
		if (strcmp(w,"and")!=0 && strcmp(w,"of")!=0 && strcmp(w,"the")!= 0 && strcmp(w,"at")!=0)
		{
			if (w[t-1]=='.')
			{
				if (strcmp(w,"and.")!=0 && strcmp(w,"of.")!=0 && strcmp(w,"the.")!= 0 && strcmp(w,"at.")!=0)
				{
					abb[pos++]=toupper(w[0]);
				}
				pos=0;
				puts(abb);
				for (int i=0;i<127;i++)
					abb[i]='\0';
			}
			else
			{
				abb[pos++]=toupper(w[0]);
			}
		}
	}
	return 0;
}
