#include <stdio.h>
int gcd(int x, int y)
{
	int t;
	while (x%y)	t=x, x=y, y=t%y;
	return y;
}
int main() {
  int x,lcm = 1;
  while (scanf ("%d", &x)==1)
	  lcm = lcm/gcd(x,lcm) * x;
  printf ("%d\n", lcm);
  return 0;
}
