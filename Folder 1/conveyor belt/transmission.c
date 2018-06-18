#include <stdio.h>
long long int fuckyou[1048576];
void transmission(long long int belt[],int N,int T) {
 	long long int buffer=0;
 	int move=T%64,steps=(T-move)/64;
 	for (int j=0;j<move;j++) {
 	 	buffer=buffer<<1;
 	 	if (belt[0]&(1ULL<<(63-j))) 
 	 		buffer++;
 	}
 	for (int i=0;i<N;i++) {
 		belt[i]=belt[i]<<move;
 		long long int temp=0;
 		if (i<N) {
	 		for (int j=0;j<move;j++) {
	 			temp=temp<<1;
	 			if (belt[i+1]&(1ULL<<(63-j)))
	 				temp++;
	 		}
	 	}
 		belt[i]|=temp;
 	}
 	belt[N-1]|=buffer;
 	for (int i=0;i<N;i++) {
 		fuckyou[i]=belt[(i+steps)%N];
 	}
 	for (int i=0;i<N;i++)
 		belt[i]=fuckyou[i];
}