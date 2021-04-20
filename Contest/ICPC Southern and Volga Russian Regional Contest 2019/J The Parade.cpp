#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e4+5;
ll c[maxn];
bool check(int n,ll row,ll lim)
{
	if(!lim) return true;
	ll ans=0,las=0;
	for(int i=1;i<=n;i++)
	{
		ll cur=c[i];
		if(las+cur>=lim)
			ans++,cur-=lim-las;
		ans+=cur/lim,las=cur%lim;
	}
	return ans>=row;
}
int main()
{
	int t,n;
	ll k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&c[i]);
		ll l=0,r=1e13;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(n,k,mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",k*r);
	}
}