#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+5,mod=1e9+7;
int f[maxn];
ll qpow(ll a,ll b,ll p=mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p,b>>=1;
	}
	return ans;
}
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m,l,r;
	for(int i=0;i<maxn;i++) f[i]=i;
	while(~scanf("%d%d",&n,&m))
	{
		int tot=n;
		set<int>st;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r),l--;
			st.insert(l),st.insert(r);
			int fl=find(l),fr=find(r);
			if(fl!=fr) f[fl]=fr,tot--;
		}
		printf("%lld\n",qpow(26,tot));
		for(int x:st) f[x]=x;
	}
}