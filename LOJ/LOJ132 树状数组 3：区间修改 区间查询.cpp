#include<cstdio>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e6+5;
ll tree1[maxn],tree2[maxn];
void update(int x,ll val,int n)
{	
	ll pos=x;
	while(x<=n) tree1[x]+=val,tree2[x]+=val*pos,x+=lowbit(x);
}
ll query(int x)
{
	ll ans=0,pos=x;
	while(x) ans+=tree1[x]*(pos+1)-tree2[x],x-=lowbit(x);
	return ans;
}
void modify(int l,int r,ll val,int n)
{	update(l,val,n),update(r+1,-val,n); }
ll getsum(int l,int r)
{	return query(r)-query(l-1); }
int main()
{
	int n,q,o,l,r;
	ll a,x;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a),modify(i,i,a,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&o);
		if(o==1) scanf("%d%d%lld",&l,&r,&x),modify(l,r,x,n);
		if(o==2) scanf("%d%d",&l,&r),printf("%lld\n",getsum(l,r));
	}
}