#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,len,n,temp,minm=0,maxm=0;
	scanf("%d",&t);
	while(t--)
	{
		minm=maxm=0;
		scanf("%d%d",&len,&n);
		while(n--) 
		{
			int tmin,tmax;
			scanf("%d",&temp);
			if(temp>len-temp)
				tmax=temp,tmin=len-temp;
			else
				tmin=temp,tmax=len-temp;
			maxm=max(tmax,maxm);
			minm=max(tmin,minm);
		}
		printf("%d %d\n",minm,maxm);
	} 
}
