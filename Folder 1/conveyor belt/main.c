#include<stdio.h>
#include"transmission.h"
#define MAXSIZE 1048576
long long int belt[MAXSIZE];
int main(){
    int N,T,i;
    scanf("%d%d",&N,&T);
    for(i=0;i<N;i++)
        scanf("%lld",&belt[i]);
    transmission(belt,N,T);
    for(i=0;i<N;i++)
        printf("%lld%s",belt[i],i==N-1?"":" ");
    return 0;
}