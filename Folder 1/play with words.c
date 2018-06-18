#include <stdio.h>
#include <string.h>
char wor[1<<20]={};
int main(void) {
	char t[7],r[7],ch[16];
	int len=0;
	while (1)
	{
		int k=0;
		if (scanf("%s %s",&t[0],&r[0])==EOF)
			break;
		if (strcmp(t,"insert")==0)
		{
			scanf("%s",&ch[0]);
			wor[len+1]='\0';
			if (strcmp(r,"right")==0)
				k=strlen(wor);
			else
			{
				if (strcmp(r,"left")==0)
					k=0;
				else
					k= atoi(r)-1;
			}
			for (int i=len-1;i>=k;i--)
				wor[i+1]=wor[i];
			wor[k]=ch[0];
			len++;
		}	
		else
		{			
			if (strcmp(r,"right")==0)
				k=len;
			else
			{
				if (strcmp(r,"left")==0)
					k=0;
				else
					k=atoi(r)-1;
			}
			for (int i=k;i<len;i++)
				wor[i]=wor[i+1];
			len--;
		}
	}
	int maj=0,count=1;
	for (int i=1;i<=len;i++)
	{
		if (wor[i]==wor[i-1])
		{
			count++;
		}
		else
		{
			if (count>maj)
				maj=count;
			count=1;
		}
	}
	count=1;
	for (int i=1;i<=len;i++)
	{
		if (wor[i]==wor[i-1])
			count++;
		else
		{
			if (count==maj)
				printf("%c ",wor[i-1]);
			count=1;
		}
	}
	printf("%d",maj);
	return 0;
}
