#include<stdio.h>
void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]) {
    if (method==0) {
        for (int i=0;i<M;i++) {
            int j=0,flag=-1;
            while (j<N && flag==-1) {
                if (bucket[j]>=ball[i]) {
                    bucket[j]-=ball[i];
                    flag=j;
                    break;
                }
                else
                    j++;
            }
            result[i]=flag;
        }
    }
    if (method==1) {
        for (int i=0;i<M;i++) {
            int j=0,flag=-1,min=1<<31-1;
            while (j<N) {
                if (bucket[j]-ball[i]>=0 && bucket[j]-ball[i]<min) {
                    min=bucket[j]-ball[i];
                    flag=j;
                    if (bucket[j]-ball[i]==0)
                        break;
                }
                j++;
            }
            if (flag>-1)
                bucket[flag]-=ball[i];
            result[i]=flag;
        }
    }
    if (method==2) {
        for (int i=0;i<M;i++) {
            int j=0,flag=-1,max=-1;
            while (j<N) {
                if (bucket[j]-ball[i]>=0 && bucket[j]-ball[i]>=max) {
                    max=bucket[j]-ball[i];
                    flag=j;
                }
                j++;
            }
            if (flag>-1)
                bucket[flag]-=ball[i];
            result[i]=flag;
        }
    }
}
int main(){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}