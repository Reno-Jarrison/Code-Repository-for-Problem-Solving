#include<stdio.h>
int main()
{
	int k,m,a[105]={0},count=0;
	scanf("%d%d",&k,&m);
	for(int i=0;i<k;i++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		for(int j=s;j<=e;j++)
			a[j]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(!a[i])
			count++;
	}
	printf("%d\n",count);
	for(int i=1;i<=m;i++)
	{
		if(!a[i])
			printf("%d ",i);
	}
	printf("\n");
}