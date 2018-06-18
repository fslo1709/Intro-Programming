#include <stdio.h>
#pragma GCC optimize("Ofast")
int map2[1024][1024];
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]) {
	int flag=0,i=0,j=0,k;
	int dirx[9]={0,0,1,-1,1,-1,-1,1,0};
	int diry[9]={1,-1,0,0,1,-1,1,-1,0};
	while (flag==0) {
		if (directionA[i]!=-1) {
			int max=map[A_r][A_c];
			int dir=8;
			for (k=0;k<8;k++) {
				if (A_r+dirx[k]>=0 && A_r+dirx[k]<N && A_c+diry[k]>=0 && A_c+diry[k]<M) {
					if (map[A_r+dirx[k]][A_c+diry[k]]>max) {
						dir=k;
						max=map[A_r+dirx[k]][A_c+diry[k]];
					}
				}
			}
			map2[A_r][A_c]=1;
			A_r+=dirx[dir];
			A_c+=diry[dir];
			if (dir==8)
				directionA[i]=-1;
			else {
				directionA[i]=dir;
				i++;
			}
		}
		if (directionB[j]!=-1) {
			int min=map[B_r][B_c];
			int dirB=8;
			for (k=0;k<8;k++) {
				if (B_r+dirx[k]>=0 && B_r+dirx[k]<N && B_c+diry[k]>=0 && B_c+diry[k]<M) {
					if (map[B_r+dirx[k]][B_c+diry[k]]<min) {
						dirB=k;
						min=map[B_r+dirx[k]][B_c+diry[k]];
					}
				}
			}
			map2[B_r][B_c]=1;
			B_r+=dirx[dirB];
			B_c+=diry[dirB];
			if (dirB==8)
				directionB[j]=-1;
			else {
				directionB[j]=dirB;
				j++;
			}
		}	
		if (map2[A_r][A_c]==1)
			directionA[i]=-1;
		if (map2[B_r][B_c]==1)
			directionB[j]=-1;
		if (directionA[i]==-1 && directionB[j]==-1)
			break;
		if (A_r==B_r && A_c==B_c) {
			directionA[i]=-1;
			directionB[j]=-1;
			break;
		}
	}
}
 
int map[1024][1024];
int main(void) {
    int N, M;
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
 
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
    return 0;
}

