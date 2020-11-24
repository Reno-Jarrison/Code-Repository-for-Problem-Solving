#include<stdio.h>
int main()
{
	int m,max=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a+b>max)
			max=a+b;
	}
	printf("%d\n",max);
}