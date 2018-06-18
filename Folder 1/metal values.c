int value(int type, int width, int height, int length)
{
	#define max(x, y) (x > y ? x : y)
	int t[128] = {};
	t[79]=30, t[47]=10, t[29]=4;
	t[82]=5, t[26]=3, t[22]=9;
	if ((type<0)||(type>100)||(t[type]==0))
		return -1;
	if ((width<=0)||(height<=0)||(length<=0))
		return -2;
	int res=0;
	int i;
	for (i=1; i<=width && i<=height && i<=length; i++)
		if ((width%i==0)&&(height%i==0)&&(length%i==0))
			res= max (res,((width/i)*(height/i)*(length/i))*(i*i*i*i*i*i));
	return res*t[type];
}
