#include <stdio.h>
typedef struct 
{
	int nomber,discharge;
}nombers;
int power(int a)
{int i=1,x=1;
    for (i=1;i<a;i++)
	    x=x*10;
return x;
}
int myfunction1(int a, int*l)
{
	int c=0,b=0,v=0,p=1,k=0,n=1,e=0,g=0;
	c=a/10;
	do 
	{
		c=c/10;
	    p++;
	}while (c>0);
	e=p;
	if ((p & 1) == 0)
	{
		do 
		{
			c=a/power(p);
			a=a%power(p);
			b=a/power(p-1);
			v=b;
			b=c;
			c=v;
			if (a>0)
			{
			k=k+power(p)*c+(power(p-1))*b;
			}
			else
			{}
			a=a%power(p-1);
			p=p-2;
		}while (a>0);
	}
	else 
	{
	a=a*10;
	do 
		{
			c=a/power(p+1);
			a=a%power(p+1);
			b=a/power(p);
			v=b;
			b=c;
			c=v;
			k=k+power(p+1)*c+(power(p))*b;
			a=a%power(p);
			p=p-2;
		}while (a>0);
	}
	*l=k;
	if ((p & 1) == 0)
		g=k/power(e);
	else
	    g=k/power(e+1);
	return g;
}

int getint(int*a)
{
	int n;
	do 
	{
		n=scanf_s("%d",a);
		if (n==0)
		{
			printf("Input err!\n");
			scanf_s("%*[^\n]");
		}
	}while (n==0);
	return n<0?0:1;
}
int main()
{
nombers arr2 [50];
int arr [50], n=0,i=0, t=0,j=1,s=0;
do
{
printf("Write a size of array(<50):");
s=getint(&n);
if (n<=0 || n>50)
printf("Error!\n");
}while (n<=0 || n>50);
for ( i=0; i<n; i++)
  {
	  do
	  {
		  printf("Write a nomber array[%d](<20 signs):",i);
		  scanf_s("%d",&arr[i]);
		  if (0=>arr[i] || arr[i]>2000000000)
			  printf("Error!\n");
	  }while (0=>arr[i] || arr[i]>2000000000);
  }
for (i=0;i<n;i++)
  {
	  arr2[i].discharge = myfunction1(arr[i],&t);
      arr2[i].nomber =t;
  }


for (j=1;j<n;j++)
  {
  for (i=0;i<n-j;i++)
  {
	  if (arr2[i].discharge < arr2[i+1].discharge)
	  {
           t=arr2[i].nomber;
           arr2[i].nomber=arr2[i+1].nomber;
		   arr2[i].nomber=t;
		   t=arr2[i].discharge;
           arr2[i].discharge=arr2[i+1].discharge;
		   arr2[i].discharge=t;
	  }
  }
  }



printf("\nFirst sequence:\n");
  for ( i=0; i<n; i++)
  {
	  printf("Array1[%d]:%d\n",i,arr[i]);
  }
printf("\nSecond sequence:\n");
  for ( i=0; i<n; i++)
  {
	  printf("Array2[%d]:%d\n",i,arr2[i].nomber);
  }
  scanf("%d",i);
}