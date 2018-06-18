#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,hprev=0,dirprev=0,h,total=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&h);
		if (i==1) {
			if (h>hprev) {
				total=3*(h-hprev);
				dirprev=1;
			}
			else {
				total=2*(hprev-h);
				dirprev=-1;
			}
		}
		else
			if (i>1) {
				if (h>hprev) {
					if (dirprev==1) 
						total+=4*(h-hprev);
					else 
						total+=3*(h-hprev);
					dirprev=1;
				}
				else {
					if (dirprev==1) 
						total+=3*(hprev-h);
					else 
						total+=2*(hprev-h);
					dirprev=-1;
				}
			}
		hprev=h;
	}
	printf("%d",total);
	return 0;
}