#include <stdio.h>
#include <string.h>
int main(void) {
	int n,t=0,i,j;
	char a[80]={},b[80]={};
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",a);
		scanf("%s",b);
		int x=strlen(a),y=strlen(b);
		if (strcmp(a,b)==0)
			puts("yes");
		else
		{
			if (x==y)
			{
				int l=0;
				for (j=0;j<x-1;j++)
				{
					if ((a[j]==b[j+1])&&(a[j+1]==b[j])&&(a[j]!=a[j+1]))
						l++;
				}		
				if (l==1) t++;
			}
			else
			{
				if (x-y==1)
				{
					i=0,j=0;
					int l=0;
					while (i<x || j<y)
					{
						if (a[i]!=b[j]) l++,i++;
						else i++,j++;
					}
					if (l<=1)
						t++;
				}
				if (y-x==1)
				{
					i=0,j=0;
					int l=0;
					while (i<x || j<y)
					{
						if (a[i]!=b[j]) l++,j++;
						else i++,j++;
					}
					if (l<=1)
						t++;	
				}
			}
			if (t==0)
				puts("no");
			else
				puts("yes");
		}
		t=0;
		for (int i=0;j<80;j++)
			a[j]='\0',b[j]='\0';
	}
	return 0;
}
