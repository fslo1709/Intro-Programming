#include <stdio.h>
struct customers{
	int arrival;
	int duration;
};
int times[1025]={0};
int total=0;
struct customers people[1000001];
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++) 
		scanf("%d %d",&people[i].arrival,&people[i].duration);
	for (int i=0;i<m;i++){
		int pos=0,mintime=times[0];
		for (int j=1;j<n;j++) {
			if (mintime==0)
				break;
			if (times[j]<mintime) {
				pos = j;
				mintime = times[j];
			}
		}
		if (people[i].arrival>times[pos])
			times[pos] = people[i].arrival;
		total += times[pos] - people[i].arrival;
		times[pos] += people[i].duration;
	}
	printf("%d",total);
	return 0;
}