#include<cstdio>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e6+5;
ll c[maxn];
void update(int x,ll val,int n)
{	while(x<=n) c[x]+=val,x+=lowbit(x); }
ll query(int x)
{
	ll ans=0;
	while(x) ans+=c[x],x-=lowbit(x);
	return ans;
}
ll getsum(int l,int r) { return query(r)-query(l-1); }
int main()
{
	int n,q,o,pos,l,r;
	ll a,x;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a),update(i,a,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&o);
		if(o==1) scanf("%d%lld",&pos,&x),update(pos,x,n);
		if(o==2) scanf("%d%d",&l,&r),printf("%lld\n",getsum(l,r));
	}
}