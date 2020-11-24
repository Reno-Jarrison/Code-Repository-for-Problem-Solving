#include<iostream>
#include<cstring>
using namespace std;
int vis[25]={0,1},fib[20]={1,1};
int main()
{
	int t,cases=0,ans,n,pt;
	for(int i=2;i<20;i++)
		fib[i]=fib[i-1]+fib[i-2],vis[fib[i]]=1;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			ans+=vis[i];
		printf("Case #%d: %d\n",++cases,n-ans);
	}
} 