#include <stdio.h>
void fill_array(int *ptr[], int n);
int main(void) {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}
void fill_array(int *ptr[], int n)
{
	int *alfa=ptr[0];
	int *omega=ptr[n-1]+1;
	int m=0;
	for (int *x=alfa; x!=omega; x++)
		*x=-1, m++;
	for (int i=0; i<n; i++)
		*(ptr[i])=i;
	int left=0, right=1;
	while (right<m && alfa[right]==-1)
		right++;
	for (int *x=alfa;x!=omega;x++)
	{
		if (*x==-1)
		{
			*x=alfa[left]+alfa[right];
		}
		else
			if (alfa+right<=x)
			{
				left=right, right++;
				while (right<m && alfa[right]==-1)
					right++;
			}
	}
	return;
}
