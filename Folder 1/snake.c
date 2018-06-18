#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void snake(const int *ptr_array[100][100], int m);
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
  snake(ptr_array, m);
    for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
  return 0;
}
void snake(const int *ptr_array[100][100], int m)
{
	int i=0,j=0,p=0,x=0,y=0,mx,my;
	const int *a;
	while (i<(m*m-1))
	{
		j=i+1;
		x=((i/m)%2)*(m-1)-(i-(i/m)*m);
		x=abs(x);
		y=i/m;
		p=*(ptr_array[y][x]);
		a=ptr_array[y][x];
		mx=x;
		my=y;
		while (j<m*m)
		{
			x=((j/m)%2)*(m-1)-(j-(j/m)*m);
			x=abs(x);
			y=j/m;
			if (p>*(ptr_array[y][x]))
			{
				p=*(ptr_array[y][x]);
				a=ptr_array[y][x];
				mx=x;
				my=y;
			}
			j++;	
		}
		x=((i/m)%2)*(m-1)-(i-(i/m)*m);
		x=abs(x);
		y=i/m;
		ptr_array[my][mx]=ptr_array[y][x];
		ptr_array[y][x]=a;
		i++;
	}
	return;
}
