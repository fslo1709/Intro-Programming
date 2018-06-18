#include <stdio.h>
int main(int argc, char const *argv[])
{
    int k,n,posneg=0,curlen=0,longest=0,length=0;
    scanf("%d",&k);
    while (scanf("%d",&n)!=EOF) {
        if (n==0) {
            if (posneg == 1 && curlen>=k && length+1>=3 && length+1>=longest) 
                longest = length+1;
            break;
        }
        else if (n>0) {
            if (posneg==1) 
                curlen++;
            else if (posneg==-1) {
                if (curlen>k || curlen<k)
                    length = 0;
                else
                    length++;
                curlen = 1;
                posneg = 1;
            }
            else
                length=0,curlen=1,posneg=1;
        } 
        else if (n<0) {
            if (posneg==-1)
                curlen++;
            else if (posneg==1) {
                if (curlen>k) {
                    if (length+1>=3 && length+1>longest)
                        longest = length+1;
                    length = 1;
                }
                else if (curlen<k) {
                    length = -1;
                }
                else {
                    if (length<0)
                        length=0;
                    if (length+1>=3 && length+1>longest)
                        longest = length+1;
                    length++;
                }
                curlen = 1;
                posneg =-1;
            }
        }
    }
    printf("%d",longest*k);
    return 0;
}