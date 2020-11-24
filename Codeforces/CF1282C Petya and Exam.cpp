#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct node
{	ll t; int tag; }p[maxn];
bool operator <(const node& x,const node& y)
{	return x.t<y.t||(x.t==y.t&&x.tag<y.tag); }
int main()
{
	int T,n,c[2],tot[2]; ll t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%d%d",&n,&t,&c[0],&c[1]);
		tot[0]=tot[1]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].tag);
			tot[p[i].tag]++;
		}
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i].t);
		sort(p+1,p+n+1);
		int ans=0,cnt[2]={0};
		ll idx=0;
		for(int i=1;i<=n;i++)
		{
			if(idx<p[i].t) 
			{
				int res=max(p[i].t-idx-1,0LL);
				int ax=min(tot[0]-cnt[0],res/c[0]);
				res-=ax*c[0];
				int bx=min(tot[1]-cnt[1],res/c[1]);
				ans=max(ans,i+ax+bx-1);
			}
			idx+=c[p[i].tag];
			cnt[p[i].tag]++;
		}
		if(idx<=t) ans=n;
		printf("%d\n",ans);
	}
}