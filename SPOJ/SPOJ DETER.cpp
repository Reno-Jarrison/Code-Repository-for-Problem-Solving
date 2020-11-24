#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
const ll mod=1e6+3;
int tot,p[maxn],vis[maxn],phi[maxn];
ll ans[maxn];
void sieve(int n)
{
	ans[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i,phi[i]=i-1;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) 
			{	phi[i*p[j]]=phi[i]*p[j]; break; }
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
		ans[i]=ans[i-1]*phi[i]%mod;
	}
}
int main()
{
	int t,n;
	sieve(2e6);
	scanf("%d",&t);
	while(t--)
		scanf("%d",&n),printf("%lld\n",ans[n]);
}