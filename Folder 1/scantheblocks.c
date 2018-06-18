#include <stdio.h>
#pragma GCC optimize("Ofast")
int main(int argc, char *argv[]) {
    int a,flag=0,max,min,l=0;
    while (scanf("%d",&a)!=EOF)    {
        max=-10001,min=10001;
        for (int i=0; i<a; i++) {
            if (scanf("%d",&l)==EOF) {
                flag=1;
                break;
            }
            if (l>max)
                max=l;
            if (l<min)
                min=l;
        }
        if (flag==1) {
            printf("%d",min);
            break;
        }
        else
            printf("%d\n",max);
    }
    return 0;
}