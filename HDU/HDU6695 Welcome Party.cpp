#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct node
{	
	int id; ll val,opp; 
}a[maxn],b[maxn];
bool operator <(const node& x,const node& y)
{	return x.val<y.val; }
ll inf=1e18+5;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].val,&b[i].val);
			a[i].opp=b[i].val;
			a[i].id=b[i].id=i;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		ll ans=inf,maxm=-1;
		for(int i=n;i;i--)
		{
			ll tmp=inf;
			int pt=upper_bound(b+1,b+n+1,a[i])-b;
			pt=min(pt,n);
			if(b[pt].val<=maxm) 
			{	ans=min(ans,abs(a[i].val-maxm)); continue; }
			while(pt&&abs(a[i].val-b[pt].val)<tmp)
				a[i].id!=b[pt].id?tmp=abs(a[i].val-b[pt].val):false,pt--;
			ans=min(ans,tmp);
			maxm=max(maxm,a[i].opp);
		}
		printf("%lld\n",ans);
	}
}