#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char S[1025], buff[1025];
	fgets(S,1025,stdin);
	S[strlen(S)-1]='\0';
	while (fgets(buff,1025,stdin)) {
		if (buff[0]=='s') {
			char *s1=NULL,*s2=NULL,*s3=NULL,*s4=NULL,*s5=NULL;
			char tok[2]={0};
			tok[0]=buff[1];
			tok[1]='\0';
			s2=strtok(buff+2,tok);
			s3=strtok(NULL,tok);
			s4=strstr(S,s2);
			if (s4!=NULL) {
				int i=0,j=0;
				char secbuff[1025]={0};
				while (&S[i]!=s4)
					secbuff[j++]=S[i++];
				secbuff[j]='\0';
				s1=strcat(secbuff,s3);
				i+=strlen(s2);
				j=strlen(secbuff);
				while (i<strlen(S))
					secbuff[j++]=S[i++];
				secbuff[j]='\0';
				s1=strcpy(S,secbuff);
			}
		}
		if (buff[0]=='p')
			printf("%s\n",S);
	}
	return 0;
}