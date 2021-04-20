#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5,maxm=5e7;
int tot,vis[maxm],p[maxm];
ll c[maxn],ans[maxn];
vector<pair<int,int>>e[maxn];
ll qpow(ll a,ll b)
{	
	ll ans=1;
	while(b)
	{
		if(b&1) ans*=a;
		a*=a,b>>=1;
	}
	return ans;
}
void solve(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;i*p[j]<=n;i++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll find(ll x,int d)
{
	if(d==1) return x;
	ll cur=max(1,int(pow(x,1.0/d))-10);
	while(qpow(cur,d)<x) cur++;
	return cur;
}
int main()
{
	solve(5e7);
	int m,n,k,u,v,d;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&v,&u,&d);
		e[u].emplace_back(v,d);
	}
	int cnt=m;
	for(int i=1;i<=n&&cnt;i++)
	{
		sort(e[i].begin(),e[i].end());
		int tmp=0,d;
		for(auto x:e[i])
		{
			if(ans[x.first]) 
				c[i]/=qpow(ans[x.first],x.second); 
			else tmp++,d=x.second;
		}
		vector<ll>buf;
		if(!tmp) continue;
		else if(tmp==1)
			c[i]=find(c[i],d);
		else for(int j=1;1ll*p[j]*p[j]<=c[i];j++)
			{
				if(c[i]%p[j]==0)
				{
					while(c[i]%p[j]==0)
						c[i]/=p[j];
					buf.push_back(p[j]);
				}
			}
		if(c[i]>1) buf.push_back(c[i]);
		int pt=0;
		for(auto x:e[i])
			if(!ans[x.first])
				ans[x.first]=buf[pt++],cnt--;
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
}