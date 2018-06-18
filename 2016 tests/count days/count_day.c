int extra[12]={0,3,3,6,1,4,6,2,5,0,3,5};
int daysm[12]={3,1,3,2,3,2,3,3,2,3,2,3};
void count_day(int year, int day, int month, int results[7]) {
	for (int i=0;i<7;i++)
		results[i]=4;
	int isleap=0,lastday;
	if (month>1) {
		if (year%4==0) {
			if (year%100)
				isleap=1;
			else 
				if (year%400==0) 
					isleap=1;
		}
	}
	if (month==2) {
		if (isleap==0)	
			return;
		isleap=0;
	}
	for (int i=0;i<daysm[month-1];i++)
		results[(day+extra[month-1]+i+isleap)%7]++;
}