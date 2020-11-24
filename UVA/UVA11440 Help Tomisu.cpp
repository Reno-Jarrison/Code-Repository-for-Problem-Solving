#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+5;
const ll mod=1e8+7;
int tot,p[maxn],vis[maxn];
ll phifac[maxn];
void init(int n)
{
	phifac[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i,phifac[i]=phifac[i-1]*(i-1)%mod;
		else phifac[i]=phifac[i-1]*i%mod;
		for(int j=1;p[j]*i<=n;j++)
		{
			vis[p[j]*i]=1;
			if(p[j]%i==0) break;
		}
	}
}
int main()
{
	init(maxn-1);
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		ll ans=phifac[m];
		for(int i=m+1;i<=n;i++)
			ans=ans*i%mod;
		printf("%lld\n",(ans-1+mod)%mod);
	}
}