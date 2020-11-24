#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)	
	{
		int L,v,l,r,count,a;
		scanf("%d%d%d%d",&L,&v,&l,&r);
		count=(l-1)/v+L/v-(r+1)/v;
		if((r+1)%v==0)
		count++;	
		printf("%d\n",count);
	}
}