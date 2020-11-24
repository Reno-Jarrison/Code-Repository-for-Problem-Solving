#include<stdio.h>
int main()
{
	int n,i,j,v,s,T;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{   
		scanf("%d",&n);
		for(j=0,v=1,s=0;j<n;j++)
		{
			s+=v;
			v+=2;
		} 
		printf("%d\n",s%10000);
	} 
} 