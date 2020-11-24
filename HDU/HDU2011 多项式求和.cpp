#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		float sum=0;
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++)
		{
			if(j%2)
				sum+=(float)1/j;
			else
				sum-=(float)1/j;		
		}
		printf("%.2f\n",sum);
	}
}