#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    //b06902102
    int tim,a,b;
    int readya=0;
    int readyb=0;
    int compa,compb,ta,tb=0;
    while (1==1)
    {
        if (scanf("%d %d %d",&tim,&a,&b)==EOF)
            break;
        if (tim>readya)
            ta=tim+a;
        else
            ta=readya+a;
        readya=ta;
        if (readyb>ta)    
            tb=readyb+b;
        else   
            tb=ta+b;        
        readyb=tb;
        printf("%d\n",tb);
    }
    return 0;
}
