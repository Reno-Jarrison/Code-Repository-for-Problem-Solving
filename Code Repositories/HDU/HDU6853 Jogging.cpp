#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sx,sy,a,b;
map<pair<ll,ll>,int>vis;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
bool dfs(ll x,ll y)
{
	if(x==y) return true;
	vis[make_pair(x,y)]=1,b++;
	for(int i=0;i<8;i++)
	{
		ll nx=x+dx[i],ny=y+dy[i];
		if(gcd(nx,ny)>1LL)
		{
			b++;
			if(!vis[make_pair(nx,ny)])
				if(dfs(nx,ny)) return true;
			if(x==sx&&y==sy) a++;
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&sx,&sy);
		vis.clear(),a=1,b=0;
		if(dfs(sx,sy)) puts("0/1");
		else
		{
			ll d=gcd(a,b);
			printf("%lld/%lld\n",a/d,b/d);
		}
	}
}