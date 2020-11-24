#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tot[2][3],cur[2][3];
int vis[6],idx[6],a[6],b[6];
ll getmnv(ll& a,ll& b)
{
	ll mnv=min(a,b);
	a-=mnv,b-=mnv;
	return mnv;
}
void dfs(int pos,ll& ans1)
{
	if(pos==6)
	{
		memcpy(cur,tot,sizeof(tot));
		for(int i=0;i<6;i++)
			getmnv(cur[0][a[idx[i]]],cur[1][b[idx[i]]]);
		ll sum=0;
		for(int i=0;i<3;i++)
			sum+=getmnv(cur[0][i],cur[1][(i+1)%3]);
		ans1=min(ans1,sum);
	}
	for(int i=0;i<6;i++)
	{
		if(vis[i]) continue;
		vis[i]=1,idx[pos]=i;
		dfs(pos+1,ans1);
		vis[i]=0;
	}
}
int main()
{
	ll n,ans1=1e9,ans2=0;
	scanf("%lld",&n);
	for(int i=0;i<=1;i++)
		for(int j=0;j<3;j++)
			scanf("%lld",&tot[i][j]);
	for(int i=0;i<3;i++)
		a[i]=i,b[i]=(i+2)%3,a[i+3]=i,b[i+3]=i;
	dfs(0,ans1);
	for(int i=0;i<3;i++)
		ans2+=getmnv(tot[0][i],tot[1][(i+1)%3]);
	printf("%lld %lld\n",ans1,ans2);
}