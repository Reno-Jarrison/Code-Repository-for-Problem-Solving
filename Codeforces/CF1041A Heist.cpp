#include<stdio.h>
int main()
{
	int n,min=1000000000,max=0,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>max)
			max=a;
		if(a<min)
			min=a;
	}
	printf("%d\n",max-min-n+1);		
} 