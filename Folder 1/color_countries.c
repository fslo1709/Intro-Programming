#include <stdio.h>
#include <stdlib.h>
int n, c, p;
int countries[20][20];
int used[20];
 
int colorcountries(int id) {
    if (id == 0) {
        used[0] = 1;
        return colorcountries(1);
    }
    for (int i = 1; i <= c; i++) {
        int check = 0, conflict = 0;
        used[id] = i;
        for (int j = 0; j < id; j++) {
            if (countries[id][j] == 1 && used[j] == used[id]) {
                conflict = 1;
                break;
            }
        }
        if (conflict == 0) 
            check = (id == n-1) ? 1: colorcountries(id+1);
        if (check == 1)
            return 1;
    }
    return 0;
}
 
int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &c, &p);
    for (int i = 0; i < p; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        countries[c1][c2] = countries[c2][c1] = 1;
    }
    int x = colorcountries(0);
    if (x)
        for (int i = 0; i < n; i++) {
            printf("%d\n", used[i]);
        }
    else
        printf("no solution.\n");
    return 0;
}