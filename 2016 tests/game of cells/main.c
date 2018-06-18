#include<stdio.h>
#include"game_of_cell.h"
int main()
{
    int grid[50][50]={0},outcome[50][50]={0},compare[50][50]={0},N;
    scanf("%d",&N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&grid[i][j]);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&compare[i][j]);
    game_of_cell(grid,outcome,N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            if (compare[i][j]!=outcome[i][j]) {
                printf("error");
                break;
            }
    return 0;
}