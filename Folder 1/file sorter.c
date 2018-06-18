#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct Account {
	int balance;
	char name[128];
	int gender;
};
int filesize(FILE *fp){
	int prev = ftell(fp);
	fseek(fp,0L,SEEK_END);
	int size = ftell(fp);
	fseek(fp,prev,SEEK_SET);
	return size;
}
int cmp(const void *A, const void *B){
	struct Account *a = (struct Account *)A;
	struct Account *b = (struct Account *)B;
	int x = strcmp(a->name,b->name);
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}
int checkalpha(char a[129])
{
	int ct = 0;
	for (int i=0;i<strlen(a);i++)
	{
		if (isalpha(a[i])==0)
			if (a[i]!=' ')
				ct++;
	}
	return ct;
}
struct Account rgis[1025];
struct Account outregis[1025];
int main (void) {
	int pos=0;
	char name1[100],name2[100];
	scanf("%s",name1);
	scanf("%s",name2);
	FILE *fin=fopen(name1,"rb");
	FILE *fout=fopen(name2,"wb");
	int finsize = filesize(fin);
	int n = finsize/sizeof(struct Account);
	fread(rgis,sizeof(struct Account),n,fin);
	for (int i=0;i<n;i++)	
	{
		if (rgis[i].balance>=0 && (rgis[i].gender==0 || rgis[i].gender==1) &&(checkalpha(rgis[i].name)==0))
		{
			outregis[pos]=rgis[i];
			pos++;
		}
	}
	qsort(outregis,pos,sizeof(struct Account),cmp);
	fwrite(outregis,sizeof(struct Account),pos,fout);
	fclose(fin);
	fclose(fout);
}