
int evaluate_f(int *iptr[], int n, int *index)
{
  int max=0,p=0,a[2],x,y;
  for (int i=0;i<n;i++)
  {
    x=iptr[i][0],y=iptr[i][1];
    p=4*x-6*y;
    if (i==0)
    {
      max=p;
      *index=i;
    }
    else
      if (p>max)
      {
        max=p;
        *index=i;
      }
  }
  return max;
}
