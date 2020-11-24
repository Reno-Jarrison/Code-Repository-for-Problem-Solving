#include<cstdio>
#include<cstring>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;
const int maxn=1e5+5;
int a[maxn],tree[maxn],l[maxn],r[maxn];
void update(int x)
{	while(x<=maxn-5) tree[x]++,x+=lowbit(x);	}
int query(int x)
{
	int ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;i++) 
			l[i]=query(a[i]),update(a[i]);
		memset(tree,0,sizeof(tree));
		for(int i=n;i;i--)
			r[i]=query(a[i]),update(a[i]);
		for(int i=2;i<n;i++)
			ans+=l[i]*(n-i-r[i])+(i-1-l[i])*r[i];
		printf("%lld\n",ans);
	}
}