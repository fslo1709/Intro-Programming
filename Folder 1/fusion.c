#include <stdio.h>
#include <string.h>
int main(void) {
	char res[127]={},a[127]={};
	while (scanf("%s",a)!=EOF)
	{
		if (res[0]=='\0')
			strcat(res,a);
		else
		{
			int ls=strlen(res),la=strlen(a),i;
			int x= ls>la ? ls:la;
			char p[127]={};
			for (i=x;i>0;i--)
			{
				int c=1;
				for (int j=0,k=ls-i;j<i && c;j++,k++)
					c&= res[k]==a[j];
				if (c)
					break;
			}
			int n=0;
			for (int k=i;k<la;k++)
				p[n++]=a[k];
			strcat(res,p);
		}
	}
	printf("%s",res);
	return 0;
}
