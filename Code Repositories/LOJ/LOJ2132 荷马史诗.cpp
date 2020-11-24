#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
struct hpnode
{
	ll w,h;
	hpnode(ll w=0,ll h=0):w(w),h(h){}
};
bool operator <(const hpnode& x,const hpnode& y)
{	return x.w>y.w||(x.w==y.w&&x.h>y.h); }
priority_queue<hpnode>hp;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	ll x,ans=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&x),hp.push(hpnode(x));
	int tot=((n-1)/(k-1)+((n-1)%(k-1)>0))*(k-1);
	for(int i=n;i<=tot;i++)
		hp.push(hpnode(0));
	for(int i=tot;i;i-=k-1)
	{
		ll w=0,h=0;
		for(int j=1;j<=k;j++)
		{
			w+=hp.top().w;
			h=max(h,hp.top().h);
			hp.pop();
		}
		hp.push(hpnode(w,h+1)),ans+=w;
	}
	printf("%lld\n%lld",ans,hp.top().h);
}