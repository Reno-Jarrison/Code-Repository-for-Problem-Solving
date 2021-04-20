#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
vector<int>e[maxn];
ll f[maxn],g[maxn];
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
ll inv(ll x)
{	return qpow(x,mod-2); }
void dfs(int u)
{
	if(!e[u].size())
	{	f[u]=1,g[u]=0; return; }
	ll pro=1;
	set<int>buf;
	for(int v:e[u])
	{
		dfs(v);
		ll cur=(f[v]+g[v])%mod;
		if(cur) pro=pro*cur%mod;
		else buf.insert(v);
	}
	g[u]=pro,f[u]=0;
	if(buf.size()) g[u]=0;
	if(buf.size()>1) f[u]=0;
	else for(int v:e[u])
	{
		if(buf.count(v))
			f[u]=(f[u]+f[v]*pro)%mod;
		else if(!buf.size())
			f[u]=(f[u]+f[v]*pro%mod*inv((f[v]+g[v])%mod))%mod;
	}
}
int main()
{
	int n,p;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",&p),e[p].push_back(i);
	dfs(1);
	printf("%lld\n",(f[1]+g[1])%mod);
}