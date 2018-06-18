#include <stdio.h>
#pragma GCC optimize("Ofast")
int main(int argc, char const *argv[])
{
	int machinetime[501]={0};		//time after the machine is free
	int jobready[501]; 			//time after the job can do the next task
	int jobntasks[501][501];	//all the tasks in the job linked to the corresponding machine it needs to do the job
	int jobntimes[501][501];	//all the tasks in the job linked to the corresponding time it will take to finish them
	int jobindexes[501]={0};		//which task of the job is next in the to-do list
	int maxtasks[501];			//how many tasks are there in total (if the jobindexes reaches this number, skip the task)
	int n,m,p,q,t,numbertasks=0;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++) {
		scanf("%d %d",&jobready[i],&maxtasks[i]);
		for (int j=0;j<maxtasks[i];j++) {
			scanf("%d %d",&jobntasks[i][j],&jobntimes[i][j]);
			numbertasks++;
		}
	}
	int mintime,inmin=-1;
	for (int i=0;i<numbertasks;i++) {
		mintime=1000001;
		for (int j=0;j<m;j++) {
			if (jobindexes[j]<maxtasks[j]) {
				int expectedtime,mactime;
				mactime= machinetime[jobntasks[j][jobindexes[j]]];
				if (mactime<jobready[j])
					mactime=jobready[j];
				expectedtime = mactime+jobntimes[j][jobindexes[j]];
				if (mintime>expectedtime) {
					mintime=expectedtime;
					inmin=j;
				}
			}
		}
		jobready[inmin]=mintime;										//change to the expected time
		machinetime[jobntasks[inmin][jobindexes[inmin]]]=mintime;		//move the ready time for the machine
		jobindexes[inmin]++;											//move the index to the next task
	}
	for (int i=0;i<m;i++) {
		printf("%d\n",jobready[i]);
	}
	return 0;
}