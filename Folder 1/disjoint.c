#include <stdio.h>
#include <stdlib.h>

int N, k;
unsigned long long int clubs[101] = {};
int ans[101] = {};

void check(int pos, int nK, unsigned long long int cop) {
    if (nK + (N-pos) < k)
        return;
    if (nK == k) {
        for (int i = 0; i < k; i++)
            printf("%d\n", ans[i]);
        exit(0);
    }
    if ((cop & clubs[pos]) == 0) {
        ans[nK] = pos;
        check(pos+1, nK+1, cop | clubs[pos]);
    }
    check(pos+1, nK, cop);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &k);
    for (int i = 0, M; i < N; i++) {
        unsigned long long int st = 0;
        scanf("%d", &M);
        for (int j = 0, move; j < M; j++) {
            unsigned long long int t = 1;
            scanf("%d", &move);
            t<<=move;
            st |= t;
        }
        clubs[i] = st;
    }
    check(0, 0, 0);
    return 0;
}