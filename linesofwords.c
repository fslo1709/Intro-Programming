#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char W[1<<24];
char *second[16384];
char **first[1024];
char line[1<<24];
void swap(int, int, int, int);
int main (){
	int n,m,a,b,c,d,counts=0,countf=0,countw=0;
	char word[1024];
	scanf("%d",&n);
	second[0]=&W[0];
	first[0]=&second[0];
	fgets(line,1024*1024,stdin);
	for (int i=0;i<n;i++)
	{
		fgets(line,1024*1024,stdin);
		int count=0,j=0;
		while (sscanf(line,"%s",word)!=EOF)
		{
			for (j=0;j<strlen(word);j++)
			{
				W[countw]=word[j];
				countw++;
			}
			for (j=count;j<strlen(word)+count;j++)
				line[j]=' ';
			while (1)
			{
				if (line[j]!=' ')
					break;
				j++;
			}
			count=j;
			W[countw]=' ';
			countw++;
			counts++;
			second[counts]=&(W[countw]);
		}
		countf++;
		first[countf]=&(second[counts]);
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		swap(a,b,c,d);
	}
	int q=0;
	int poschar,possec;
	for (int v=0;v<countf;v++)
	{
		possec=0;
		while (first[v]+possec<first[v+1])
		{
			poschar=0;
			while (*(second[q]+poschar)!=' ')	
			{
				printf("%s",*(second[q]+poschar));
				poschar+=sizeof(char);
			}
			q++;
			possec+=sizeof(char);
			if (first[v]+possec<first[v+1])
				printf(" ");
		}
		
			printf("\n");
	}	
            return 0;
}
void swap(int a, int b, int c, int d)
{
	char *temp;
	int q=0,r=0;
	while (&second[q]<first[a]+b*sizeof(char))
		q++;
	while (&second[r]<first[c]+d*sizeof(char))
		r++;
	temp=second[q];
	second[q]=second[r];
	second[r]=temp;
	return;
}