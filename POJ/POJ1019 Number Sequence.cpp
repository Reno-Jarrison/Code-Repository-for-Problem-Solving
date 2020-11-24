#include<cstdio>
#define ll long long
using namespace std;
const int maxn=3.5e4+5;
ll siz[maxn],cnt[maxn],pre[maxn];
void solve(int n)
{
	for(int i=1;i<=n;i++)
	{
		siz[i]=siz[i/10]+1;
		cnt[i]=cnt[i-1]+siz[i];
		pre[i]=pre[i-1]+cnt[i];
	}
}
int main()
{
	solve(35000);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll x,pt1=0,pt2=0;
		scanf("%lld",&x);
		while(pre[pt1+1]<x) pt1++;
		x-=pre[pt1];
		while(cnt[pt2+1]<x) pt2++;
		x-=cnt[pt2];
		ll ans=pt2+1,pos=siz[ans]-x;
		while(pos) ans/=10,pos--;
		printf("%lld\n",ans%10);
	}
}