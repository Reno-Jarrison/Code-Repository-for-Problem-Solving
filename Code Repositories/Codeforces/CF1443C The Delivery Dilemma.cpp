#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct node
{	ll a,b; }p[maxn];
bool operator <(const node& x,const node& y)
{	return x.a<y.a; }
ll suc[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i].a);
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i].b);
		sort(p+1,p+n+1);
		suc[n+1]=0;
		for(int i=n;i;i--)
			suc[i]=suc[i+1]+p[i].b;
		ll ans=1e16;
		for(int i=0;i<=n;i++)
			ans=min(ans,max(p[i].a,suc[i+1]));
		printf("%lld\n",ans);
	}
}