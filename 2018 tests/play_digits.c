#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,count,even,zeroes,eleven,exactpos,notcorrectpos;
    exactpos = 0, notcorrectpos = 0;
    while (scanf("%d",&a)!=EOF) {
        count++;
        if (a==0)
            zeroes++;
        if (count%2==0)
            exactpos+=a;
        else
            notcorrectpos+=a;
    }
    if (a%2==0) 
        even = 1;
    else
        even = 0;
    int total = exactpos-notcorrectpos;
    if (total%11 == 0)
        eleven = 1;
    else
        eleven = 0;
    // printf("%d %d %d\n",exactpos,notcorrectpos,total);
    printf("%d\n%d\n%d\n%d",count,even,zeroes,eleven);
    return 0;
}