#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;
Student *record;
int filesize(FILE *fi){
	int prev= ftell(fi);
	fseek(fi,0L,SEEK_END);
	int size= ftell(fi);
	fseek(fi,prev,SEEK_SET);
	return size;
}
int main (void){
	char fname[100],outname[100];
	scanf("%s %s",fname,outname);
	FILE *fin=fopen(fname,"rb");;
	FILE *fout=fopen(outname,"w");
	int fsize=filesize(fin);
	unsigned char *mem = malloc(sizeof(unsigned char)*fsize);
	fread(mem,1,fsize,fin);
	record = (Student *) mem;
	int n= fsize/sizeof(Student);
	fprintf(fout,"<table border=\"1\">\n");
	fprintf(fout,"<tbody>\n");
	for (int i=0;i<n;i++)
	{
		fprintf(fout,"<tr>\n");
		fprintf(fout,"<td>%s</td>\n",record[i].name);
		fprintf(fout,"<td>%d</td>\n",record[i].id);
		fprintf(fout,"<td>%s</td>\n",record[i].phone);
		fprintf(fout,"<td>%f, %f, %f, %f</td>\n",record[i].grade[0],record[i].grade[1],record[i].grade[2],record[i].grade[3]);
		fprintf(fout,"<td>%d, %d, %d</td>\n",record[i].birth_year,record[i].birth_month,record[i].birth_day);
		fprintf(fout,"</tr>\n");
	}
	fprintf(fout,"</tbody\n");
	fprintf(fout,"</table>\n");
	fclose(fin);
	fclose(fout);
	free (mem);
	return 0;
}