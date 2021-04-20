#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e5+5;
int a[maxn],d[maxn],pos[maxn],tree[maxn];
int query(int x)
{
	int ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
void update(int x,int val)
{	while(x<maxn) tree[x]+=val,x+=lowbit(x); }
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),d[i]=a[i];
	sort(d+1,d+n+1);
	int uni=unique(d+1,d+n+1)-d-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(d+1,d+uni+1,a[i])-d,pos[a[i]]=i;
	ll ans=0;
	for(int i=n;i;i--)
	{
		ll lval=pos[i]-1-query(pos[i]);
		ll rval=n-pos[i]-(query(n)-query(pos[i]));
		ans+=min(lval,rval);
		update(pos[i],1);
	}
	printf("%lld\n",ans);
}