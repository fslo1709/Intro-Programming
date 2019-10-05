#include <stdio.h>
#pragma GCC optimize ("Ofast", "unroll-loops")
int n, N, a;
int rec[201][3];
int used[201];
 
void stackr(int cur, int prevx, int prevy, int nrec, int sum) {
    if (nrec >= N) {
        N = nrec;
        a = sum;
    }
    if (cur == n-1) {
        return;
    }
    if (n-cur+nrec < N)
        return;
    if (cur == -1) {
        for (int i = 0; i < n; i++) {
            stackr(i, rec[i][0], rec[i][1], 1, i);
            if (n-i < N)
                break;
        }
        return;
    }
    for (int i = cur+1; i < n; i++) {
        if (prevx >= rec[i][0] && prevy>= rec[i][1]) 
            stackr(i, rec[i][0], rec[i][1], nrec+1, sum+i);
        if (n-i+nrec < N)
            break;
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rec[i][0], &rec[i][1]);
        if (rec[i][0] > rec[i][1]) {
            int temp = rec[i][0];
            rec[i][0] = rec[i][1];
            rec[i][1] = temp;
        }
    }
    stackr(-1, -1, -1, 0, 0);
    printf("%d %d\n", N, a);
    return 0;
}