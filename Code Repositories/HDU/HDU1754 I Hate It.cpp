#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=2e5+5;
ll a[maxn],tree[maxn],delta;
void update(int x,ll val,int n)
{
	a[x]=val;
	for(int i=x;i<=n;i+=lowbit(i))
	{
		tree[i]=val;
		for(int j=1;j<lowbit(i);j<<=1)
			tree[i]=max(tree[i],tree[i-j]);
	}
}
ll query(int l,int r)
{
	ll ans=0;
	while(l<=r)
	{
		ans=max(ans,a[r]),r--;
		while(r-l>=lowbit(r))
			ans=max(ans,tree[r]),r-=lowbit(r);
	}
	return ans;
}
int main()
{
	int n,q,pos,l,r;
	char o[3];
	while(~scanf("%d%d",&n,&q))
	{
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),update(i,a[i],n);
		for(int i=1;i<=q;i++)
		{
			scanf("%s",o);
			if(o[0]=='U') scanf("%d%lld",&pos,&delta),update(pos,delta,n);
			if(o[0]=='Q') scanf("%d%d",&l,&r),printf("%lld\n",query(l,r));
		}
	}
}