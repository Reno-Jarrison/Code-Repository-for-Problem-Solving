#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,maxm=5e6+5;
int tot,p[maxm],vis[maxm];
ll a[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	init(1e4);
	int n,x,ks=0;
	while(~scanf("%d",&n))
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x),a[i]=0;
			for(int j=1;p[j]*p[j]<=x;j++)
				while(x%p[j]==0) a[i]++,x/=p[j];
			if(x>1) a[i]++;
			sum^=a[i];
		}
		printf("Test #%d: ",++ks);
		if(!sum) puts("Bob");
		else for(int i=1;i<=n;i++)
			if((sum^a[i])<a[i])
			{	printf("Alice %d\n",i); break; }
	}
}