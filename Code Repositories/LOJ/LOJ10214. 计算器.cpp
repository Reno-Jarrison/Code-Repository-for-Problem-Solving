#include<bits/stdc++.h>
#define ll long long
#define MOD 192617
#define maxn
using namespace std;
struct node{ ll val,key; };
vector<node>h[MOD];
ll qpow(ll x,ll y,ll mod)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod,y>>=1LL;
	}
	return ans;
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x; 
}
inline void insert(ll val,ll key)
{ 	h[val*val%MOD].push_back({val,key}); }
ll query(ll val,ll key)
{
	ll hval=val*val%MOD,len=h[hval].size();
	for(int i=len-1;i>=0;i--)
		if(h[hval][i].val==val&&h[hval][i].key<=key)
			return key-h[hval][i].key;
	return -1;
}
ll bsgs(ll a,ll b,ll c)   //a^x===b(%c)
{
	for(int i=0;i<MOD;i++) h[i].clear();
	if(!a&&!b) return 1;
	if(!a&&b) return -1; 
	ll m=ceil(sqrt(c)),am=qpow(a,m,c),ans,minm=0x7fffffff;
	for(ll i=0,val=b;i<m;i++) 
		insert(val,i),val=val*a%c;
	for(ll i=0,val=1;i<=m+1;i++)
	{
		ans=query(val,i*m);
		if(ans>=0) 
			return ans;
		val=val*am%c;
	}
	return -1;
}
int main()
{
	int t,k;
	ll y,z,p,ans;
	scanf("%d%d",&t,&k);
	while(t--)
	{
		scanf("%lld%lld%lld",&y,&z,&p);
		ans=-1;
		if(k==1) ans=qpow(y,z,p);
		else if(k==2)
		{
			ll d,x0,y0,m;
			exgcd(y,p,d,x0,y0);
			if(z%d==0) m=p/d,ans=(z*x0/d%m+m)%m;
		}
		else ans=bsgs(y%p,z%p,p);
		if(ans==-1) printf("Orz, I cannot find x!\n");
		else printf("%lld\n",ans);
	}
}