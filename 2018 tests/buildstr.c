#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int k, l, n, N;
char c;
char posstr[1026];
 
void printstr(char prev, int len) {
    int i;
    if (N == n)
        return;
    if (len == l) {
        puts(posstr);
        N++;
        return;
    }
    int wrap = 0;
    if (prev+k > 'z') {
        char list[k];
        for (i = 0; i < prev+k-'z'; i++)
            list[i] = 'a'+i;
        int j;
        for (j = prev+1; j <= 'z'; j++)
            list[i++] = j;
        for (i = 0; i < k; i++) {
            posstr[len] = list[i];
            printstr(list[i], len+1);
            if (N==n)
              return;
        }
    }
    else {
        for (i = 1; i <= k; i++) {
            posstr[len] = prev+i;
            printstr(prev+i, len+1);
              if (N == n) return;
        }
    }
    return;
}
 
 
int main(int argc, char const *argv[])
{
    scanf("%c %d %d %d", &c, &k, &l, &n);
    posstr[0] = c;
    posstr[l] = '\0';
    printstr(c, 1);
    return 0;
}